# 1888. Minimum Number of Flips to Make the Binary String Alternating

Property | Value
--- | ---
Difficulty | Medium
Topics | String, Dynamic Programming, Sliding Window
Date | March 7, 2026
LeetCode Link | [https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/](https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/)

## Intuition

The problem defines two operations: a circular shift (Type-1) and a bit flip (Type-2). We want to find the minimum number of bit flips required to make any rotation of the string alternating.

An alternating string of length $n$ can only take two forms:
1. Starting with '0': `010101...`
2. Starting with '1': `101010...`

The key insight for handling "circular" problems or "Type-1" operations efficiently is the **String Doubling** technique. If we concatenate the string with itself ($s + s$), every possible rotation of the original string $s$ appears as a substring of length $n$ within the doubled string.

By sliding a window of size $n$ over the doubled string $s + s$, we can compare each window against the two possible alternating patterns. Since the patterns themselves are periodic, we don't need to generate them for every window; we can simply track the mismatches incrementally.

**Why does this work?**
- If $n$ is even, rotating the string doesn't change the alignment of bits with an infinite alternating pattern.
- If $n$ is odd, rotating the string by one position effectively swaps the required flips for pattern 1 and pattern 2.
- The sliding window over $s+s$ covers all these possibilities naturally.

## Complexity Analysis

### Time Complexity: $O(n)$
We iterate through the doubled string ($2n$) exactly once. Each step in the sliding window involves constant time additions and subtractions.

### Space Complexity: $O(n)$
We create a new string of length $2n$ to facilitate the sliding window. While this can be optimized to $O(1)$ by using modulo operators on the original string, $O(n)$ is well within the limits for $n = 10^5$.