# 1752. Check if Array Is Sorted and Rotated

### Metadata Table
Property | Value
--- | ---
Difficulty | Easy
Topics | Array
Date | May 23, 2026
LeetCode Link | [Check if Array Is Sorted and Rotated](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/)

### Intuition
The problem asks if the array is originally sorted in non-decreasing order and then rotated by some amount. 

If we look at a sorted array, it increases monotonically. If we rotate it, we introduce at most one point where the next element is smaller than the current element (a "drop"). 
For example, in `[3, 4, 5, 1, 2]`, the elements are strictly non-decreasing except at the transition `5 -> 1`.
Additionally, we must check the transition from the last element back to the first element (i.e., comparing `nums[n-1]` with `nums[0]`). If we treat the array as a circular buffer, there can be at most one position index `i` such that `nums[i] > nums[(i + 1) % n]`.

Thus, the core logic is:
1. Count how many times an element is strictly greater than its subsequent element (using modulo indexing for circularity).
2. If this count is at most $1$, the array can be formed by rotating a sorted array. Otherwise, it is not possible.

### Complexity Analysis
- **Time Complexity:** $\mathcal{O}(N)$ where $N$ is the number of elements in the array. We perform a single pass through the array.
- **Space Complexity:** $\mathcal{O}(1)$ as we only need a few variables to count the transitions and keep track of loop indices.