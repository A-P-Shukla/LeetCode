# 26. Remove Duplicates from Sorted Array

| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | Array, Two Pointers |
| Date | May 31, 2026 |
| LeetCode Link | [https://leetcode.com/problems/remove-duplicates-from-sorted-array/](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) |

## Intuition

Because the array is **sorted**, all duplicate copies of any value are contiguous. We exploit this with a **two-pointer** technique:

- **Slow pointer `k`:** points to the position where the next unique element should be written.
- **Fast pointer `i`:** scans the array from left to right.

Whenever `nums[i] != nums[i-1]`, we have encountered a new unique value. We write it to `nums[k]` and advance `k`. Elements at indices `≥ k` after the loop are irrelevant — the problem only requires the first `k` elements to be correct.

**Why this works:** In a sorted array, `nums[i] != nums[i-1]` is a sufficient and necessary condition for `nums[i]` being a new unique value. We never need to look further back than one position.

## Complexity Analysis

- **Time Complexity:** $O(n)$ — a single pass through the array.
- **Space Complexity:** $O(1)$ — the modification is done in-place with no auxiliary data structures.
