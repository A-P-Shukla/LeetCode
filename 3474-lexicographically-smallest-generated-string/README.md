# 3474. Lexicographically Smallest Generated String

Property | Value
--- | ---
Difficulty | Hard
Topics | String, Greedy, String Matching
Date | March 31, 2026
LeetCode Link | [https://leetcode.com/problems/lexicographically-smallest-generated-string/](https://leetcode.com/problems/lexicographically-smallest-generated-string/)

## Intuition

The problem asks for the lexicographically smallest string `word` of length $N = n + m - 1$ that satisfies $n$ constraints provided by `str1` and `str2`. Each constraint $i$ (from $0$ to $n-1$) states that the substring of `word` starting at index $i$ of length $m$ must either match `str2` (if `str1[i] == 'T'`) or not match it (if `str1[i] == 'F'`).

To find the lexicographically smallest string, we follow a greedy approach:
1.  **Satisfy all 'T' constraints first**: These are hard constraints that fix specific characters in `word`. If two 'T' constraints overlap and demand different characters for the same index, no solution exists.
2.  **Initial Greedy Guess**: Fill all unassigned (not fixed by 'T') positions in `word` with the smallest possible character, 'a'.
3.  **Correct 'F' violations**: Iterate through the string from left to right. If an 'F' constraint at index $i$ is violated (i.e., the substring $word[i \dots i+m-1]$ matches `str2`), we must change one character in that window. To maintain lexicographical order, we want to:
    *   Change a character at the **largest possible index** $j$ within the window $[i, i+m-1]$ that was not fixed by a 'T' constraint. This delays the difference from the smallest possible prefix as much as possible.
    *   Change it to the **smallest possible character** $c \in ['a', 'z']$ that breaks the current match at $i$ and does not create any new violations for all previous and current indices $k \le i$ where `str1[k] == 'F'`.

By processing violations from left to right and always choosing the rightmost available character to change, we ensure that we only modify the string when absolutely necessary and in the most optimal way for lexicographical order.

## Complexity Analysis

*   **Time Complexity**: $O(n \cdot m + V \cdot m^2 \cdot 26)$, where $n$ is the length of `str1`, $m$ is the length of `str2`, and $V$ is the number of 'F' violations. In the worst case, $V \approx n$. However, the inner check for violations is performed $O(m)$ times and `memcmp` is highly optimized. Given the constraints $n=10^4, m=500$, the greedy approach with efficient string comparison is well within limits as most 'F' constraints are satisfied by default.
*   **Space Complexity**: $O(n + m)$ to store the generated string and the boolean array tracking fixed indices.