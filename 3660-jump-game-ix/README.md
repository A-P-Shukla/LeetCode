# 3660. Jump Game IX

Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Dynamic Programming, Monotonic Stack, Prefix Max
Date | May 7, 2026
LeetCode Link | [Jump Game IX](https://leetcode.com/problems/jump-game-ix/)

## Intuition

The problem defines two jump rules:
1. **Forward Jump ($j > i$):** Allowed if the value at the destination is smaller than the current value ($nums[j] < nums[i]$).
2. **Backward Jump ($j < i$):** Allowed if the value at the destination is larger than the current value ($nums[j] > nums[i]$).

To solve this efficiently, we must determine the reachability of indices and identify the maximum value in those reachable sets.

**Key Observations:**
1. **Backward Jumps:** From any index $i$, we can always jump to any index $k < i$ that has a value $nums[k] > nums[i]$. This means from $i$, we can effectively reach any prefix maximum value to its left. Let $P_i = \max(nums[0 \dots i])$. The maximum value reachable by jumping only left is $P_i$.
2. **Forward Jumps:** To jump right, we must find an element smaller than our current value. To maximize the values we can reach later (via backward jumps), we should aim to jump as far right as possible.
3. **Rightmost Reachable Index:** If we jump from $i$ to any $j > i$ (where $nums[j] < nums[i]$), we can then jump from $j$ to any $k < j$ where $nums[k] > nums[j]$. The maximum value reachable from $j$ is $P_j$. Since $P$ is a non-decreasing array, to maximize our reachable value, we simply need to find the **rightmost index** $j$ in the entire array such that $nums[j] < nums[i]$. Let's call this $j_{max}$.
4. **Conclusion:** For every index $i$, the maximum reachable value is $P[\max(i, j_{max})]$, where $j_{max}$ is the rightmost index in the array such that $nums[j_{max}] < nums[i]$.

## Complexity Analysis

- **Time Complexity:** $O(N \log N)$ where $N$ is the length of the array. This accounts for sorting unique values to perform coordinate compression and binary searches for each index.
- **Space Complexity:** $O(N)$ to store the prefix maximums, the rightmost occurrences of values, and the result array.