# 3460. Lexicographically Smallest Palindromic Permutation Greater Than Target

Property | Value
--- | ---
Difficulty | Medium
Topics | Two Pointers, String, Greedy, Counting
Date | August 28, 2026
LeetCode Link | [Lexicographically Smallest Palindromic Permutation Greater Than Target](https://leetcode.com/problems/lexicographically-smallest-palindromic-permutation-greater-than-target/)

## Intuition

To construct the lexicographically smallest palindromic permutation of string `s` that is strictly greater than `target`:

1. **Palindrome Feasibility & Structure**:
   - Count character frequencies in `s`.
   - For an even length $n$, all character counts must be even.
   - For an odd length $n$, exactly one character must have an odd count (which will fixedly occupy the middle position $n / 2$).
   - The entire palindrome is completely determined by its first half (indices $0$ to $\lfloor n/2 \rfloor - 1$). The multiset of available characters for this first half consists of $\lfloor \text{count}[c] / 2 \rfloor$ for each character $c$. The second half is simply the mirror image of the first half.

2. **Greedy Candidate Search**:
   - A palindrome $P$ is strictly greater than `target` if at the first index $k$ where they differ, $P[k] > \text{target}[k]$.
   - To make $P$ as small as possible while ensuring $P > \text{target}$, we prefer to match `target` for as long a prefix as possible before making a character strictly larger.
   - We check candidates in order of preference (from smallest possible resulting string to largest):
     1. **Candidate 0 (Exact Match on First Half)**:
        Try setting $P[0 \dots \text{half}-1] = \text{target}[0 \dots \text{half}-1]$. If this is valid (we have enough characters) and the resulting full palindrome $P$ is strictly greater than `target` (which could happen if the middle or second half naturally exceeds `target`), this $P$ is our optimal solution.
     2. **Divergence Candidate at Index $k$**:
        If Candidate 0 fails or is invalid, iterate $k$ from $\text{half} - 1$ down to $0$:
        - Assume $P[0 \dots k-1] = \text{target}[0 \dots k-1]$.
        - At position $k$, select the smallest character $c > \text{target}[k]$ available in our remaining first-half character pool.
        - For positions $k+1 \dots \text{half}-1$, fill them with the remaining available characters in **ascending order** to make the string lexicographically as small as possible.
        - Mirror the first half to complete the palindrome.
        - The first valid divergence string found during this reverse iteration ($k = \text{half}-1$ down to $0$) is guaranteed to be the overall lexicographically smallest palindrome greater than `target`.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n + |\Sigma| \cdot n) = \mathcal{O}(n)$, where $n$ is the length of the string and $|\Sigma| = 26$ is the alphabet size. Checking character availability and building strings takes linear time.
- **Space Complexity:** $\mathcal{O}(n + |\Sigma|) = \mathcal{O}(n)$ to store character counts and construct the candidate palindromic string.