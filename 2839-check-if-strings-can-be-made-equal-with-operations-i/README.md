# 2839. Check if Strings Can be Made Equal With Operations I

Property | Value
--- | ---
Difficulty | Easy
Topics | String, Sorting
Date | March 29, 2026
LeetCode Link | [https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/](https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/)

## Intuition

The problem restricts swaps to indices $i$ and $j$ where $j - i = 2$. Given that the strings always have a length of 4, the indices are fixed as $\{0, 1, 2, 3\}$.

This constraint implies that indices are partitioned into two independent sets:
1.  **Even Indices:** $\{0, 2\}$
2.  **Odd Indices:** $\{1, 3\}$

A character at an even index can only ever move to another even index, and a character at an odd index can only move to another odd index. Therefore, for `s1` to be transformable into `s2`, the multiset of characters at the even positions in `s1` must match the multiset of characters at the even positions in `s2`. The same logic applies to the odd positions.

Since each set contains only two characters, we simply need to check if the pairs are identical either in their original order or swapped.

## Complexity Analysis

-   **Time Complexity:** $O(1)$. The strings are of a fixed length (4), and we perform a constant number of comparisons.
-   **Space Complexity:** $O(1)$. No additional data structures that scale with input size are used.