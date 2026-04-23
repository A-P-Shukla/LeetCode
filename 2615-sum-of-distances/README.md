# 2615. Sum of Distances

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Hash Table, Prefix Sum |
| Date | April 23, 2024 |
| LeetCode Link | [https://leetcode.com/problems/sum-of-distances/](https://leetcode.com/problems/sum-of-distances/) |

## Intuition

The problem asks us to find the sum of absolute differences between an index $i$ and all other indices $j$ where $nums[i] = nums[j]$. A naive $O(N^2)$ approach would check every pair, which is too slow given $N = 10^5$.

To optimize, consider a specific value $X$ that appears at indices $\{i_0, i_1, i_2, \dots, i_{k-1}\}$. For a specific index $i_m$ in this set, we want to calculate:
$$\text{Sum} = \sum_{j=0}^{k-1} |i_m - i_j|$$

We can split this summation into two parts: indices smaller than $i_m$ and indices larger than $i_m$:
$$\text{Sum} = \sum_{j=0}^{m-1} (i_m - i_j) + \sum_{j=m+1}^{k-1} (i_j - i_m)$$

Expanding the sums:
$$\text{Sum} = (m \cdot i_m - \sum_{j=0}^{m-1} i_j) + (\sum_{j=m+1}^{k-1} i_j - (k - 1 - m) \cdot i_m)$$

This mathematical breakdown reveals that if we know the **prefix sum** of the indices for each unique value, we can calculate the result for any index in $O(1)$ time. 

The strategy is:
1. Group all indices for each unique number using a hash map.
2. For each group of indices, use the prefix sum technique to calculate the total distance for every index in that group.

## Complexity Analysis
- **Time Complexity:** $O(N)$, where $N$ is the length of the input array. We traverse the array once to group indices and then iterate through the grouped indices to calculate the sums.
- **Space Complexity:** $O(N)$ to store the indices in a hash map and to store the resulting array.