# 2078. Two Furthest Houses With Different Colors

Property | Value
--- | ---
Difficulty | Easy
Topics | Array, Greedy
Date | April 20, 2026
LeetCode Link | [https://leetcode.com/problems/two-furthest-houses-with-different-colors/](https://leetcode.com/problems/two-furthest-houses-with-different-colors/)

## Intuition

To maximize the distance between two houses with different colors, we want at least one of those houses to be as close to the boundaries of the street as possible. The two most extreme positions are the first house (index `0`) and the last house (index `n-1`).

The optimal distance must involve either the first house or the last house. 
1. If the first and last houses have different colors, the maximum distance is simply `n - 1`.
2. If they have the same color, we need to find:
   - The rightmost house that has a different color than the house at index `0`.
   - The leftmost house that has a different color than the house at index `n-1`.

By checking these two scenarios, we are guaranteed to find the global maximum distance because any pair of houses in the "middle" could be extended to one of the ends unless the end house shares the same color, which our two-pass strategy already accounts for.

## Complexity Analysis

- **Time Complexity:** $O(n)$, where $n$ is the number of houses. We perform two linear scans of the array (one from the right and one from the left).
- **Space Complexity:** $O(1)$, as we only use a few integer variables regardless of the input size.