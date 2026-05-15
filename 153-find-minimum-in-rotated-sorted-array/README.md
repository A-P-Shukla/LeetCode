# 153. Find Minimum in Rotated Sorted Array

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Binary Search |
| Date | May 15, 2026 |
| LeetCode Link | [https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/) |

## Intuition

The problem asks us to find the minimum element in an array that was originally sorted but has been rotated. The key observation is that a rotated sorted array consists of two sorted sub-segments. For example, in `[4, 5, 6, 7, 0, 1, 2]`, the segments are `[4, 5, 6, 7]` and `[0, 1, 2]`. The minimum element is the first element of the second segment.

Since the array is partially sorted and we need $O(\log n)$ time complexity, **Binary Search** is the ideal choice. 

The logic for the search is as follows:
1. Compare the middle element (`nums[mid]`) with the rightmost element (`nums[right]`).
2. If `nums[mid] > nums[right]`, it means the "inflection point" (where the values drop) is to the right of `mid`. Therefore, the minimum value must be in the right half. We set `left = mid + 1`.
3. If `nums[mid] < nums[right]`, it means the right half is sorted normally, and the minimum value is either at `mid` or to the left of `mid`. We set `right = mid`.
4. We continue this until `left == right`, at which point `nums[left]` will be the minimum element.

Note: Since all elements are unique, we don't need to worry about cases where `nums[mid] == nums[right]` unless `left == right`.

## Complexity Analysis
- **Time Complexity:** $O(\log n)$, where $n$ is the length of the array. This is due to the binary search approach which halves the search space in each iteration.
- **Space Complexity:** $O(1)$, as we only use a constant amount of extra space for pointers.