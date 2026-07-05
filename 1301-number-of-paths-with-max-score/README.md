# 1301. Number of Paths with Max Score

| Property | Value |
| --- | --- |
| Difficulty | Hard |
| Topics | Array, Dynamic Programming, Matrix |
| Date | 2026-07-05 |
| LeetCode Link | https://leetcode.com/problems/number-of-paths-with-max-score/ |

### Intuition

This problem is a classic pathfinding challenge that can be solved using Dynamic Programming (DP). Since we need to find the maximum score and the number of ways to achieve it, we can define a DP state `dp[r][c]` which stores a pair: `{max_score, num_paths}` to reach position `(r, c)` starting from the bottom-right corner `'S'` and moving towards the top-left `'E'`.

Because movement is restricted to Up, Left, and Up-Left, the state `dp[r][c]` depends only on `dp[r+1][c]`, `dp[r][c+1]`, and `dp[r+1][c+1]`. This allows us to iterate backwards from the bottom-right corner `(n-1, n-1)` to `(0, 0)`.

**Key steps:**
1. **Base Case:** Initialize the target `'E'` (top-left) as `0`.
2. **State Transition:** For each cell `(r, c)`, evaluate the three possible incoming directions. If a cell is reachable from multiple directions, we aggregate the paths from the directions that offer the current global maximum score.
3. **Modulus:** Since the number of paths can be very large, we apply `modulo 10^9 + 7` to the count.
4. **Handling Obstacles:** If a cell contains 'X', it is effectively unreachable, and its path count is 0.

### Complexity Analysis

- **Time Complexity:** $O(N^2)$, where $N$ is the side length of the board. We visit each cell in the $N \times N$ grid exactly once and perform a constant number of operations (checking 3 neighbors) for each cell.
- **Space Complexity:** $O(N^2)$ to store the DP table. While this could be optimized to $O(N)$ using space compression (since we only need the previous row/column), $O(N^2)$ is well within limits for $N=100$.