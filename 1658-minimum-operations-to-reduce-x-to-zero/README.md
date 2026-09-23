# 1658. Minimum Operations to Reduce X to Zero

## Metadata Table
Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Hash Table, Binary Search, Sliding Window, Prefix Sum
Date | 2026-09-23
LeetCode Link | https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

## Intuition

The problem asks for the **minimum** number of operations (removing elements from either the leftmost or rightmost end) to make the sum of removed elements equal to `x`.

Instead of thinking about which elements to *remove* from the prefix and suffix, we can invert the problem:
- Removing elements from both ends that sum up to `x` is equivalent to finding a **contiguous subarray in the middle** that sums up to $\text{total\_sum} - x$.
- Minimizing the number of removed elements from the ends is directly equivalent to **maximizing the length of the remaining contiguous subarray**.

Let $\text{target} = \text{total\_sum} - x$:
1. **If $\text{target} == 0$**: We must remove all elements from the array. The answer is `nums.length`.
2. **If $\text{target} < 0$**: Since all elements are positive ($nums[i] \ge 1$), it is impossible for any combination of elements to sum to $x$. Return `-1`.
3. **If $\text{target} > 0$**: We can use a **Sliding Window (Two Pointers)** technique to find the longest contiguous subarray whose sum equals `target`. Since all elements are positive, expanding the right pointer increases the sum and incrementing the left pointer decreases the sum monotonically.

If the maximum length of such a subarray is $M$, then the minimum operations required is $N - M$ (where $N$ is the length of `nums`). If no such subarray exists, return `-1`.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the number of elements in `nums`. Each element is added to the sliding window sum once by the `right` pointer and removed at most once by the `left` pointer.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space. We only use a few scalar variables for pointers and sum tracking.