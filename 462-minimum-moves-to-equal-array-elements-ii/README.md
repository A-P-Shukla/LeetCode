# 462. Minimum Moves to Equal Array Elements II

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Math, Sorting |
| Date | 2026-11-02 |
| LeetCode Link | https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/ |

## Intuition & Approach
The cost of moving all elements to a target value `t` equals the sum of absolute differences `|nums[i] - t|`.  
This is a classic *ℓ₁* minimization problem: the sum of absolute deviations is minimized when `t` is any median of the multiset.  

Why not try the mean? The mean minimizes the sum of squared deviations (ℓ₂), not absolute deviations, so it can yield a larger move count.  

Thus the optimal strategy is:
1. Sort the array to access the median in O(1) after sorting.  
2. Pick the median element (`nums[n/2]` for zero‑based indexing).  
3. Accumulate `abs(nums[i] - median)` for all `i`.  

Sorting dominates the runtime; the subsequent linear scan is O(n). The algorithm uses only a few extra variables beyond the input array.

## Complexity Analysis
- **Time Complexity:** O(n log n) due to sorting; the final pass is O(n).  
- **Space Complexity:** O(1) auxiliary space if the sort is in‑place (C++ `std::sort`, Python's Timsort uses O(log n) stack space, still O(1) extra for our calculation).