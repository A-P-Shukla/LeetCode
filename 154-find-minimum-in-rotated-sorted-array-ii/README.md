# 154. Find Minimum in Rotated Sorted Array II

Property | Value
--- | ---
Difficulty | Hard
Topics | Array, Binary Search
Date | May 16, 2026
LeetCode Link | [https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/)

## Intuition

The problem asks us to find the minimum element in a sorted array that has been rotated an unknown number of times and contains duplicates. This is a variation of the classic "Find Minimum in Rotated Sorted Array" problem, but the presence of duplicates introduces a specific edge case that prevents a pure logarithmic search in all scenarios.

The core logic of searching in a rotated sorted array involves comparing the middle element (`nums[mid]`) with the rightmost element (`nums[right]`):

1.  **`nums[mid] > nums[right]`**: This implies that the rotation point (and thus the minimum element) must be to the right of `mid`. We set `left = mid + 1`.
2.  **`nums[mid] < nums[right]`**: This implies that the right half is sorted normally, and the minimum element is either at `mid` or to its left. We set `right = mid`.
3.  **`nums[mid] == nums[right]`**: This is the ambiguous case caused by duplicates. We cannot determine if the minimum is to the left or right (e.g., `[1, 0, 1, 1, 1]` vs `[1, 1, 1, 0, 1]`). However, we know that since `nums[mid] == nums[right]`, even if `nums[right]` were the minimum, `nums[mid]` is an equivalent value. Therefore, we can safely decrement the `right` pointer by 1 (`right--`) to narrow the search space without losing the minimum value.

## Complexity Analysis

*   **Time Complexity**: 
    *   **Average Case**: $O(\log N)$, where $N$ is the number of elements. When there are few duplicates, the algorithm behaves like standard binary search.
    *   **Worst Case**: $O(N)$. This occurs when most elements are identical (e.g., `[1, 1, 1, 0, 1]`), forcing the algorithm to decrement the `right` pointer linearly.
*   **Space Complexity**: $O(1)$ as we only use a constant amount of extra space for pointers.