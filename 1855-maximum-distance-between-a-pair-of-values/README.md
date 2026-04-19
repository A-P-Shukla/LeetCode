# 1855. Maximum Distance Between a Pair of Values

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Two Pointers, Binary Search |
| Date | April 19, 2026 |
| LeetCode Link | [https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/](https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/) |

## Intuition

The problem asks us to find the maximum $j - i$ such that $i \le j$ and $nums1[i] \le nums2[j]$. The most critical piece of information is that both arrays are **non-increasing** (sorted in descending order).

When arrays are sorted, we usually consider two approaches: Binary Search or Two Pointers.

1.  **Binary Search approach**: For every index $i$ in `nums1`, we can binary search in `nums2` for the rightmost index $j$ where $nums2[j] \ge nums1[i]$. Since `nums2` is non-increasing, this property is monotonic.
2.  **Two Pointers approach**: This is even more efficient. We can maintain two pointers, `i` for `nums1` and `j` for `nums2`. 
    *   If the condition $nums1[i] \le nums2[j]$ is met, it is a valid pair. We update our maximum distance and increment `j` to see if we can find an even larger distance for the current `i`. 
    *   If the condition is not met ($nums1[i] > nums2[j]$), we must increment `i`. Because the arrays are non-increasing, incrementing `i` makes $nums1[i]$ smaller, which might satisfy the condition $nums1[i] \le nums2[j]$ for the current $j$.

The Two Pointers approach is optimal because each pointer traverses its respective array only once.

## Complexity Analysis

- **Time Complexity**: $O(N + M)$, where $N$ is the length of `nums1` and $M$ is the length of `nums2`. Each pointer moves from left to right and never backtracks.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store pointers and the maximum distance.