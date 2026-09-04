# Find Smallest Stable Index

| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | Array, Prefix / Suffix Precomputation |
| Date | September 4, 2026 |
| LeetCode Link | https://leetcode.com/problems/find-smallest-stable-index/ |

## Intuition

The instability score at index `i` requires two distinct pieces of information:
1. The maximum element in the prefix range `nums[0..i]`.
2. The minimum element in the suffix range `nums[i..n-1]`.

Calculating these prefix maximums and suffix minimums naively for every index `i` would require $O(n^2)$ time. Given that prefix max grows incrementally as we move left-to-right, and suffix min shrinks as we move left-to-right, we can precompute or compute both efficiently:

- **Suffix Minimums**: We precalculate an array `suff_min` from right to left where `suff_min[i]` holds the minimum value from index `i` to `n - 1`.
- **Prefix Maximums**: We maintain a running variable `curr_max` as we iterate from index `0` to `n - 1`.

By doing this, for any index `i`, both `max(nums[0..i])` and `min(nums[i..n-1])` are obtainable in $O(1)$ time. We return the first index `i` where `curr_max - suff_min[i] <= k`.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n)$, where $n$ is the length of the array `nums`. We perform one pass from right to left to precompute the suffix minimums, and one pass from left to right to check stability for each index.
- **Space Complexity:** $\mathcal{O}(n)$, required to store the suffix minimum array `suff_min`.