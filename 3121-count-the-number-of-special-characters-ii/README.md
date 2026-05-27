# 3121. Count the Number of Special Characters II


Property | Value
--- | ---
Difficulty | Medium
Topics | Hash Table, String, Two Pointers
Date | May 27, 2026
LeetCode Link | [Count the Number of Special Characters II](https://leetcode.com/problems/count-the-number-of-special-characters-ii/)

## Intuition

The problem asks us to count the number of "special" characters. A character $c$ is special if:
1. It appears in both lowercase and uppercase.
2. **Every** lowercase occurrence of $c$ appears before the **first** uppercase occurrence of $c$.

Let's translate the second requirement into index comparisons:
- If *every* lowercase occurrence of $c$ is before the *first* uppercase occurrence, then the **last** (latest) lowercase occurrence of $c$ must be before the **first** (earliest) uppercase occurrence of $c$.
- Conversely, if the last lowercase occurrence is before the first uppercase occurrence, then all preceding lowercase occurrences are also guaranteed to be before the first uppercase occurrence.

Thus, the condition for a character \( c \) to be special is:

\[
\text{last\_lower}[c] \neq -1
\quad \text{and} \quad
\text{first\_upper}[c] \neq -1
\quad \text{and} \quad
\text{last\_lower}[c] < \text{first\_upper}[c]
\]

We can solve this problem in a single pass over the string by keeping track of:
- The last occurrence index of each lowercase letter.
- The first occurrence index of each uppercase letter.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the length of the string `word`. We iterate through the string once to populate our tracking structures, and then perform a constant-time check ($\mathcal{O}(26)$) over the alphabet.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space. The arrays for storing index information are fixed at size $26$ (one for each letter of the English alphabet), which is constant regardless of the input length.
