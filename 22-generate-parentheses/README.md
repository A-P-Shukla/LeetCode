# 22. Generate Parentheses

Metadata Table:
Property | Value
--- | ---
Difficulty | Medium
Topics | String, Dynamic Programming, Backtracking, Bracket Sequences
Date | 2026-10-02
LeetCode Link | https://leetcode.com/problems/generate-parentheses/

## Intuition
The task is to list every possible way to arrange `n` pairs of parentheses such that they are *well‑formed*.  
A sequence is well‑formed when, while scanning from left to right, the number of opening brackets never falls below the number of closing brackets, and at the end both counts are equal to `n`.

This condition lends itself naturally to **backtracking**:

1. At each step we may add an `'('` if we still have opening brackets left.  
2. We may add a `')'` only if the number of closing brackets used so far is smaller than the number of opening brackets already placed (otherwise the sequence would become invalid).  

We continue this recursive construction until the constructed string reaches length `2 * n`. At that point the string is a complete, valid combination and is stored.

The recursion depth never exceeds `2n` (max 16 for the given constraints), making backtracking both simple and fast enough.

## Complexity Analysis
- **Time Complexity:**  
  The number of valid sequences for `n` pairs is the *n‑th Catalan number* `C_n = (1/(n+1)) * (2n choose n)`. The algorithm visits each node of the recursion tree exactly once, so the overall time is `O(C_n)`. For `n ≤ 8`, `C_8 = 1430`, which is tiny.
- **Space Complexity:**  
  The recursion stack holds at most `2n` characters, and the result list stores `C_n` strings each of length `2n`. Hence auxiliary space (excluding output) is `O(n)`, while total space including the output is `O(C_n * n)`.