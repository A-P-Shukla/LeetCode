# 1846. Maximum Element After Decreasing and Rearranging

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Greedy, Sorting |
| Date | 2026-06-28 |
| LeetCode Link | https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/ |

### Intuition

To maximize the final element, we want to keep the numbers in the array as large as possible while strictly following the rules. 

1.  **Sorting:** Since we can rearrange the elements freely, sorting the array is the first logical step. Sorting allows us to process the numbers in non-decreasing order, making it easier to ensure the "absolute difference" condition.
2.  **Greedy Strategy:** 
    *   The first element must be 1. If `arr[0]` is not 1, we change it to 1. 
    *   For every subsequent element at index `i`, we want it to be as large as possible. However, it cannot be more than `arr[i-1] + 1` to satisfy the condition `abs(arr[i] - arr[i-1]) <= 1`.
    *   If `arr[i]` is already greater than `arr[i-1] + 1`, we can decrease it to `arr[i-1] + 1` to maintain the constraint while keeping the value as high as possible.
    *   If `arr[i]` is already less than or equal to `arr[i-1] + 1`, we leave it as it is (it already satisfies the condition).
3.  **Result:** After iterating through the sorted array and applying these constraints, the last element of the array will be the maximum possible value.

### Complexity Analysis

*   **Time Complexity:** $O(N \log N)$ where $N$ is the length of the array, primarily due to sorting the input array. The subsequent pass through the array takes $O(N)$.
*   **Space Complexity:** $O(1)$ or $O(N)$ depending on the space complexity of the sorting algorithm implemented by the language (typically $O(\log N)$ or $O(N)$ stack space).