# 33. Search in Rotated Sorted Array

### Metadata
Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Binary Search
Date | May 22, 2026
LeetCode Link | [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)

### Intuition

The problem requires finding a target element in a sorted array that has been rotated. The overall runtime must be $O(\log n)$, which strongly points to a variation of **Binary Search**.

In a standard binary search, we divide the search space in half. Here, because the array is rotated, it is split into two parts: one portion will be strictly sorted, while the other portion will contain the rotation point (and thus be only partially sorted). 

A key insight is that **at least one of the halves (left or right) of any pivot split will always be sorted**. 

We can determine which half is sorted by comparing the boundary elements:
1. If `nums[left] <= nums[mid]`, the left half is sorted.
2. Otherwise, the right half is sorted.

Once we identify the sorted half, we can easily check if the `target` lies within its boundaries:
- If the left half is sorted and the `target` falls within `[nums[left], nums[mid])`, we narrow our search space to the left half. Otherwise, we look in the right half.
- If the right half is sorted and the `target` falls within `(nums[mid], nums[right]]`, we narrow our search space to the right half. Otherwise, we look in the left half.

This process is repeated until we either find the target or the search range becomes invalid.

### Complexity Analysis

- **Time Complexity:** $\mathcal{O}(\log n)$. At each step, we divide the search interval in half, resulting in logarithmic time complexity.
- **Space Complexity:** $\mathcal{O}(1)$. The algorithm runs in-place, using only a few variables to maintain search boundaries.