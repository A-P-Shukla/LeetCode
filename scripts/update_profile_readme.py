#!/usr/bin/env python3
"""
Detects the latest LeetCode problem pushed and updates the GitHub profile README.
Triggered by GitHub Actions on every push to the LeetCode repo.
"""

import os
import re
import subprocess
import sys
import tempfile
from pathlib import Path

PROFILE_REPO = "A-P-Shukla/A-P-Shukla"
LEETCODE_REPO = "A-P-Shukla/LeetCode"
LEETCODE_START = "<!-- LEETCODE_START -->"
LEETCODE_END = "<!-- LEETCODE_END -->"
STREAK_OLD = "github-readme-streak-stats.herokuapp.com"
STREAK_NEW = "streak-stats.demolab.com"

# Pattern for problem folders: NUMBER-slug-words
FOLDER_PATTERN = re.compile(r"^(\d+)-(.+)$")


def run(cmd, cwd=None, check=True):
    """Run a shell command and return stdout."""
    result = subprocess.run(
        cmd, cwd=cwd, capture_output=True, text=True, check=check, shell=True
    )
    return result.stdout.strip()


def get_changed_folders():
    """Find problem folders changed in the latest commit."""
    try:
        diff_output = run("git diff HEAD~1 HEAD --name-only")
    except subprocess.CalledProcessError:
        # Fallback for first commit
        diff_output = run("git diff --name-only HEAD")

    changed_folders = set()
    for line in diff_output.splitlines():
        parts = line.strip().split("/")
        if len(parts) >= 2 and FOLDER_PATTERN.match(parts[0]):
            changed_folders.add(parts[0])

    return sorted(changed_folders)


def parse_readme_metadata(folder_path):
    """Parse the README.md metadata table inside a problem folder."""
    readme_path = folder_path / "README.md"
    if not readme_path.exists():
        return None

    content = readme_path.read_text(encoding="utf-8")

    # Extract the H1 title: "# NUMBER. Title"
    title_match = re.search(r"^#\s+(\d+)\.\s+(.+)$", content, re.MULTILINE)
    if not title_match:
        return None

    number = int(title_match.group(1))
    title = title_match.group(2).strip()

    # Extract difficulty from the metadata table
    diff_match = re.search(r"Difficulty\s*\|\s*(.+)", content)
    difficulty = diff_match.group(1).strip() if diff_match else "Unknown"

    # Extract LeetCode link from the metadata table
    link_match = re.search(
        r"LeetCode Link\s*\|\s*\[.*?\]\((https?://[^)]+)\)", content
    )
    if not link_match:
        # Fallback: try bare URL
        link_match = re.search(r"LeetCode Link\s*\|\s*(https?://\S+)", content)

    link = link_match.group(1).strip() if link_match else f"https://leetcode.com/problems/{folder_path.name.split('-', 1)[1] if '-' in folder_path.name else ''}/"

    return {
        "number": number,
        "title": title,
        "difficulty": difficulty,
        "link": link,
        "folder": folder_path.name,
    }


def difficulty_badge(difficulty):
    """Return a colored badge for the difficulty level."""
    colors = {
        "Easy": "🟢",
        "Medium": "🟡",
        "Hard": "🔴",
    }
    return f"{colors.get(difficulty, '⚪')} {difficulty}"


def generate_leetcode_section(problem):
    """Generate the markdown for the LeetCode section showing a single problem."""
    if problem is None:
        return (
            f"{LEETCODE_START}\n"
            "| Problem | Title | Difficulty | Status |\n"
            "| :--- | :--- | :--- | :---: |\n"
            "| -- | Working on next problem... | -- | ⏳ |\n"
            f"{LEETCODE_END}"
        )

    return (
        f"{LEETCODE_START}\n"
        "| Problem | Title | Difficulty | Status |\n"
        "| :--- | :--- | :--- | :---: |\n"
        f"| #{problem['number']} "
        f"| [{problem['title']}]({problem['link']}) "
        f"| {difficulty_badge(problem['difficulty'])} "
        f"| ✅ |\n"
        f"{LEETCODE_END}"
    )


def update_profile_readme(new_section, dry_run=False):
    """Clone the profile repo, update the README, and push."""
    if dry_run:
        print("\n--- DRY RUN: Generated LeetCode section ---")
        print(new_section)
        print("--- End of section ---\n")
        return

    token = os.environ.get("PROFILE_README_TOKEN")
    if not token:
        print("ERROR: PROFILE_README_TOKEN not set. Cannot push to profile repo.")
        sys.exit(1)

    with tempfile.TemporaryDirectory() as tmpdir:
        clone_url = f"https://x-access-token:{token}@github.com/{PROFILE_REPO}.git"
        run(f'git clone "{clone_url}" profile_repo', cwd=tmpdir)
        repo_dir = os.path.join(tmpdir, "profile_repo")

        readme_path = os.path.join(repo_dir, "README.md")
        if not os.path.exists(readme_path):
            print("ERROR: README.md not found in profile repo.")
            sys.exit(1)

        with open(readme_path, "r", encoding="utf-8") as f:
            readme = f.read()

        # Replace LeetCode section
        pattern = re.compile(
            re.escape(LEETCODE_START) + r".*?" + re.escape(LEETCODE_END),
            re.DOTALL,
        )
        if pattern.search(readme):
            readme = pattern.sub(new_section, readme)
        else:
            print("WARNING: LeetCode markers not found in README. Skipping update.")
            return

        # Fix broken Streak Stats URL
        if STREAK_OLD in readme:
            readme = readme.replace(STREAK_OLD, STREAK_NEW)
            print("Fixed broken Streak Stats URL.")

        with open(readme_path, "w", encoding="utf-8") as f:
            f.write(readme)

        # Configure git and push
        run('git config user.name "LeetCode Bot"', cwd=repo_dir)
        run('git config user.email "bot@leetcode-auto.dev"', cwd=repo_dir)
        run("git add README.md", cwd=repo_dir)

        # Check if there are changes to commit
        status = run("git status --porcelain", cwd=repo_dir)
        if not status:
            print("No changes to commit. README is already up to date.")
            return

        run('git commit -m "🤖 auto-update: latest LeetCode solve"', cwd=repo_dir)
        run("git push origin main", cwd=repo_dir)
        print("Profile README updated successfully!")


def main():
    dry_run = "--dry-run" in sys.argv

    repo_root = Path(os.environ.get("GITHUB_WORKSPACE", ".")).resolve()
    print(f"Scanning repo at: {repo_root}")

    # Find changed problem folders
    changed = get_changed_folders()
    if not changed:
        print("No problem folders changed in this commit. Nothing to update.")
        return

    print(f"Changed problem folders: {changed}")

    # Pick the last (highest-numbered or most recent) folder
    latest_folder = changed[-1]
    print(f"Latest problem folder: {latest_folder}")

    # Parse metadata
    problem = parse_readme_metadata(repo_root / latest_folder)
    if problem:
        print(f"Detected: #{problem['number']} - {problem['title']} ({problem['difficulty']})")
    else:
        print(f"WARNING: Could not parse metadata from {latest_folder}/README.md")

    # Generate and apply
    section = generate_leetcode_section(problem)
    update_profile_readme(section, dry_run=dry_run)


if __name__ == "__main__":
    main()
