# 2540. Minimum Common Value

| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | Array, Hash Table, Two Pointers, Binary Search |
| Date | May 19, 2026 |
| LeetCode Link | [https://leetcode.com/problems/minimum-common-value/](https://leetcode.com/problems/minimum-common-value/) |

## Intuition

The problem asks for the smallest integer present in both arrays. A crucial piece of information is that both input arrays are already sorted in non-decreasing order. This sorted property allows us to efficiently find the common element without using extra space or checking every possible pair.

We can employ a **Two Pointers** strategy. By placing one pointer at the start of `nums1` and another at the start of `nums2`, we can compare the elements at these positions:
1. If the elements are equal, we have found the smallest common value because we are traversing from the smallest to the largest values.
2. If the element in `nums1` is smaller than the element in `nums2`, we increment the pointer for `nums1` to search for a larger value that might match `nums2`.
3. If the element in `nums2` is smaller than the element in `nums1`, we increment the pointer for `nums2` for the same reason.

If we exhaust either array without finding a match, it means no common element exists, and we return -1.

## Complexity Analysis

- **Time Complexity:** $O(n + m)$, where $n$ is the length of `nums1` and $m$ is the length of `nums2`. In the worst case, we traverse each array once.
- **Space Complexity:** $O(1)$, as we only use two pointer variables regardless of the input size.