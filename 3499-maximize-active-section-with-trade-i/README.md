# 3499. Maximize Active Section with Trade I

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | String, Enumeration |
| Date | 2026-07-21 |
| LeetCode Link | [Maximize Active Section with Trade I](https://leetcode.com/problems/maximize-active-section-with-trade-i/) |

### Intuition

The problem asks us to perform at most one "trade": remove a block of '1's surrounded by '0's and replace a block of '0's surrounded by '1's with '1's. The augmented string `t = '1' + s + '1'` simplifies the conditions, as every block of '1's is now surrounded by '0's, and every block of '0's is now surrounded by '1's.

1.  **Represent the string as blocks:** Parse the string into alternating groups of 1s and 0s. For example, `s = "1000100"` becomes `[1, 3, 1, 2]` (lengths of segments starting with 1s).
2.  **Define the Trade:** Removing a block of '1's (length $L_1$) and adding a block of '0's (length $L_0$) transforms the total active count by $+L_0 - L_1$. We want to maximize this delta.
3.  **Constraints:** The '1's block must be between two '0's, and the '0's block must be between two '1's. Given our block representation, any block of 1s at index $i$ is adjacent to 0s at $i-1$ and $i+1$. Similarly, any 0s block at $i$ is between 1s at $i-1$ and $i+1$.
4.  **Strategy:** Calculate the initial number of '1's. Iterate through all possible blocks of 0s that are surrounded by 1s (those are the ones we can flip to '1's). For each such block, we want to subtract the "cost" of removing a block of '1's. To maximize the gain, we should subtract the smallest possible block of '1's that appears before or after the chosen block of '0's.

### Complexity Analysis

*   **Time Complexity:** $O(N)$, where $N$ is the length of the string. We perform a single pass to group the segments and another pass (or linear scan) to find the optimal trade.
*   **Space Complexity:** $O(N)$ to store the segment lengths.