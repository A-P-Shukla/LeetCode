# 2472. Maximum Number of Non-overlapping Palindrome Substrings

### Metadata Table
Property | Value
--- | ---
Difficulty | Medium
Topics | Two Pointers, String, Dynamic Programming, Greedy
Date | 2026-09-15
LeetCode Link | https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/

### Intuition

The problem asks us to find the maximum number of non-overlapping palindromic substrings, each of length at least $k$.

A key theoretical insight simplifies this problem:
**Any palindrome of length $L \ge k$ contains a centered palindromic substring of length $k$ or length $k + 1$.**

- If $L$ and $k$ have the same parity (both even or both odd), trimming equal characters from both ends yields a valid palindrome of length $k$.
- If $L$ and $k$ have different parities, trimming equal characters from both ends yields a valid palindrome of length $k + 1$.

Because any longer valid palindrome contains a shorter valid palindrome of length $k$ or $k + 1$, we never need to search for palindromes longer than $k + 1$. Choosing a shorter valid palindrome allows the substring to end as early as possible, which greedily leaves the maximum remaining string available for future non-overlapping palindromes.

Thus, we can process the string from left to right using a **greedy approach**:
1. Iterate through each end index `i` from `k - 1` to `n - 1`.
2. At each index `i`, check if the substring of length $k$ (ending at `i`) is a palindrome and does not overlap with previously selected substrings.
3. If not, check if the substring of length $k + 1$ (ending at `i`) is a palindrome and does not overlap.
4. As soon as a valid palindrome is found, increment our count and update `last_end` to `i + 1`.

### Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N \cdot k)$, where $N$ is the length of string `s`. At each index $i$, we check at most two substrings (of length $k$ and $k + 1$), taking $\mathcal{O}(k)$ time for character comparisons. Given $N \le 2000$, this performs at most $4 \times 10^6$ operations, which easily runs in a few milliseconds.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space, as we check palindromes in-place without allocating extra string copies or DP tables.

---