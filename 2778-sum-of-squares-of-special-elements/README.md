# 2778. Sum of Squares of Special Elements

Metadata Table:
Property | Value
--- | ---
Difficulty | Easy
Topics | Array, Enumeration
Date | 2026-10-11
LeetCode Link | https://leetcode.com/problems/sum-of-squares-of-special-elements/

## Intuition
The array is **1‑indexed**, so an element `nums[i]` (where `i` starts at 1) is *special* when the index `i` divides the length `n` of the array (`n % i == 0`).  
Because `n ≤ 50`, we can simply check every index. For each special index we add the square of its value to the answer.

The algorithm is therefore a single linear scan, testing the divisibility condition and accumulating the squared value.

## Complexity Analysis
- **Time Complexity:** O(n) – we visit each of the `n` indices once.  
- **Space Complexity:** O(1) – only a few scalar variables are used regardless of input size.