# 1464. Maximum Product of Two Elements in an Array

| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | Array, Sorting, Heap (Priority Queue) |
| Date | 2026-07-27 |
| LeetCode Link | https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/ |

## Intuition

The problem asks us to pick two distinct indices $i$ and $j$ from an array of positive integers to maximize the expression $(nums[i] - 1) \times (nums[j] - 1)$.

Since every element in `nums` is an integer greater than or equal to $1$, the value $(nums[k] - 1)$ is guaranteed to be non-negative for any index $k$. To maximize the product of two non-negative numbers, we simply need to choose the two largest individual factors possible. This translates directly to finding the two largest numbers in the array.

While sorting the array in non-decreasing order would easily give us the two largest numbers at the end in $O(N \log N)$ time, we can optimize this further. By tracking the largest (`max1`) and second-largest (`max2`) values in a single pass over the array, we can achieve an optimal $O(N)$ time complexity with $O(1)$ auxiliary space.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the number of elements in `nums`. We traverse the array exactly once, updating our two tracking variables in constant time $\mathcal{O}(1)$ at each step.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space. We only use two integer variables (`max1` and `max2`) to maintain the largest values, requiring no extra memory proportional to the input size.