# 2975. Maximum Square Area by Removing Fences From a Field

Metadata Table:
Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Hash Table, Enumeration
Date | 2026-08-27
LeetCode Link | https://leetcode.com/problems/lexicographically-smallest-string-after-a-swap/

*(Note: The problem described above is **"Lexicographically Smallest Permutation Greater Than Target"**)*

---

### Intuition

To construct the lexicographically smallest permutation of `s` that is strictly greater than `target`, we must understand how lexicographical ordering works:
1. Two strings are compared character by character from left to right.
2. A string $A$ is greater than string $B$ if at the **first index $i$ where they differ**, $A[i] > B[i]$.
3. Matching a longer common prefix with `target` always produces a lexicographically smaller result than matching a shorter prefix, regardless of the remaining characters.

Thus, our optimal strategy is:
1. Find the maximum prefix of `target` that can be formed using the characters available in `s`. Let this prefix length be $L$.
2. Iterate backwards from index $i = \min(L, n-1)$ down to $0$:
   - Check if there is any remaining character in `s` (after using characters for `target[0..i-1]`) that is strictly greater than `target[i]`.
   - If such a character exists, we pick the **smallest** available character greater than `target[i]` for position $i$.
   - To keep the overall string as small as possible, all subsequent positions $i+1 \dots n-1$ should be filled with the remaining available characters sorted in ascending order.
   - If no valid character exists at index $i$, we "backtrack" by restoring `target[i-1]` to our pool of available characters and try index $i-1$.
3. If no index $i$ yields a valid character, it is impossible to form any permutation greater than `target`, so we return `""`.

---

### Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N + \Sigma)$, where $N$ is the length of string `s` ($N \le 300$) and $\Sigma = 26$ is the alphabet size. Counting character frequencies takes $\mathcal{O}(N)$, finding the longest match takes $\mathcal{O}(N)$, and the loop executes at most $N$ times with a fixed $\mathcal{O}(\Sigma)$ check per iteration.
- **Space Complexity:** $\mathcal{O}(\Sigma)$ auxiliary space to store character frequency counts, plus $\mathcal{O}(N)$ space for the output string.

---