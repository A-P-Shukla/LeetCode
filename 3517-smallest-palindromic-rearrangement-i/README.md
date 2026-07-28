# 3517. Smallest Palindromic Rearrangement I

Property | Value
--- | ---
Difficulty | Medium
Topics | String, Sorting, Counting Sort
Date | July 28, 2026
LeetCode Link | https://leetcode.com/problems/smallest-palindromic-rearrangement-i/

## Intuition

We are given a string `s` that is guaranteed to already be a palindrome. We need to find the lexicographically smallest palindromic permutation of `s`.

A key property of palindromes is their symmetry:
1. Any palindrome $P$ of length $n$ is completely determined by its first half $L = P[0 \dots \lfloor n/2 \rfloor - 1]$, an optional center character $M = P[\lfloor n/2 \rfloor]$ (if $n$ is odd), and a right half $R = \text{reverse}(L)$.
2. Since the input string `s` is already a palindrome, the first half `s[0 ... n/2 - 1]` contains exactly one copy of each mirrored character pair in `s`.
3. To make the reconstructed palindrome lexicographically smallest, we must make its prefix $L$ lexicographically smallest.
4. The multiset of characters forming $L$ is fixed by the character counts of $s$. Therefore, the smallest possible prefix $L$ is obtained simply by sorting the characters in `s[0 ... n/2 - 1]` in ascending alphabetical order.
5. If $n$ is odd, the middle character at $s[n/2]$ remains in the center.

Thus, the optimal strategy is:
1. Extract the left half prefix of length $\lfloor n/2 \rfloor$.
2. Sort this prefix alphabetically.
3. Form the result by concatenating the sorted left half, the middle character (if $n$ is odd), and the reversed sorted left half.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N \log N)$ using standard sorting (or $\mathcal{O}(N)$ if using counting sort, since the alphabet size is $\Sigma = 26$). Given $N \le 10^5$, sorting takes negligible time and executes well within constraints.
- **Space Complexity:** $\mathcal{O}(N)$ to store and return the constructed string.