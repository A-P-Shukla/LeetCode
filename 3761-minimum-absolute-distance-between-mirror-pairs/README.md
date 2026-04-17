# 3761. Minimum Absolute Distance Between Mirror Pairs

Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Hash Table, Math
Date | April 17, 2026
LeetCode Link | [3761. Minimum Absolute Distance Between Mirror Pairs](https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/)

## Intuition

The problem asks us to find the minimum distance $|i - j|$ for a pair $(i, j)$ such that $i < j$ and $reverse(nums[i]) = nums[j]$. 

A naive $O(N^2)$ solution would involve checking every pair, which is too slow given the constraint $N = 10^5$. Instead, we can optimize this by observing that as we iterate through the array from left to right at index $j$, we are looking for the largest previous index $i$ that satisfies the condition. 

Specifically, for each element $nums[j]$, we want to know if any $nums[i]$ (where $i < j$) was encountered such that $reverse(nums[i])$ matches $nums[j]$. To minimize the distance, we only care about the **most recent** index $i$ where $reverse(nums[i])$ produced that specific value.

We can use a **Hash Map** to store the mapping of `{reversed_value: last_seen_index}`. As we process each number $nums[j]$:
1. We check if $nums[j]$ exists in our map. If it does, we calculate the distance $j - \text{map}[nums[j]]$ and update our global minimum.
2. We calculate $R = reverse(nums[j])$ and update the map with $map[R] = j$. By updating the map even if the key already exists, we ensure that future checks for $R$ will find the closest possible index, maintaining the greedy requirement for minimum distance.

## Complexity Analysis

- **Time Complexity:** $O(N \cdot \log_{10}(M))$, where $N$ is the length of the array and $M$ is the maximum value in `nums`. We iterate through the array once ($N$), and for each element, we reverse its digits, which takes logarithmic time relative to the value of the number (approximately 10 iterations for $10^9$).
- **Space Complexity:** $O(N)$, as in the worst case, we store a reversed value for every index in our hash map.