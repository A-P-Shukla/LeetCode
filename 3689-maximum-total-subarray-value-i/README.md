# 3689. Maximum Total Subarray Value I

| Property      | Value                                                                                           |
| ------------- | ----------------------------------------------------------------------------------------------- |
| Difficulty    | Medium                                                                                          |
| Topics        | Array, Greedy                                                                                   |
| Date          | June 9, 2026                                                                                    |
| LeetCode Link | [Maximum Total Subarray Value I](https://leetcode.com/problems/maximum-total-subarray-value-i/) |

## Intuition

The problem asks us to choose exactly $k$ non-empty subarrays and maximize the sum of their individual values. The value of a subarray is defined as the difference between its maximum and minimum elements: $\max(nums[l..r]) - \min(nums[l..r])$.

Crucially, the problem states that:
1. Subarrays **may overlap**.
2. The **exact same subarray** (same $l$ and $r$) **can be chosen more than once**.

These two conditions simplify the problem significantly. To maximize the sum of $k$ values, we want to choose the single subarray with the largest possible value and repeat it exactly $k$ times. 

What is the maximum possible value of any subarray in the entire array?
For any subarray, its elements are a subset of the full array `nums`. Therefore, the maximum element of any subarray can never exceed the global maximum of `nums`, and its minimum element can never be smaller than the global minimum of `nums`. 

Thus, the maximum possible value for any single subarray is $\max(nums) - \min(nums)$, which we can achieve by selecting the entire array as our subarray (or any subarray that contains both the global maximum and the global minimum).

Since we can choose this same optimal subarray $k$ times, the maximum total value we can achieve is simply:
$$\text{Total Value} = k \times (\max(nums) - \min(nums))$$

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n)$
  We only need a single pass over the array `nums` to find both the maximum and minimum elements.
  
- **Space Complexity:** $\mathcal{O}(1)$
  We only use a few variables to store the maximum and minimum values, which requires constant auxiliary space.
