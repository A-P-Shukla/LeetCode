# 2770. Maximum Number of Jumps to Reach the Last Index

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Dynamic Programming |
| Date | May 10, 2026 |
| LeetCode Link | [https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/](https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/) |

## Intuition

The problem asks for the maximum number of jumps to reach the final index of an array given a specific jump condition. Since the decision to jump to index $j$ depends on the state of previous indices $i$ (where $i < j$), this problem naturally fits the **Dynamic Programming (DP)** paradigm.

We can define $DP[i]$ as the maximum number of jumps required to reach index $i$ starting from index $0$. 

1.  **Base Case**: At the starting position (index 0), the number of jumps is 0. Thus, $DP[0] = 0$.
2.  **Transitions**: For any index $j > 0$, we look at all previous indices $i < j$. If index $i$ is reachable (meaning $DP[i] \neq -1$) and the condition $|nums[j] - nums[i]| \le target$ is satisfied, then index $j$ can be reached from $i$. The number of jumps to reach $j$ via $i$ would be $DP[i] + 1$.
3.  **Optimization**: Since we want to maximize the jumps, for each $j$, we take the maximum value among all valid $DP[i] + 1$.
4.  **Final Result**: If $DP[n-1]$ remains its initial value (e.g., -1), it means the last index is unreachable.

## Complexity Analysis

- **Time Complexity**: $O(n^2)$, where $n$ is the length of the `nums` array. We use two nested loops: the outer loop iterates through each index $j$, and the inner loop checks all previous indices $i < j$.
- **Space Complexity**: $O(n)$ to store the `dp` array.