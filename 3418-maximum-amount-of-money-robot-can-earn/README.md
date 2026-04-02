# 3418. Maximum Amount of Money Robot Can Earn

Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Dynamic Programming, Matrix
Date | April 2, 2026
LeetCode Link | [Maximum Amount of Money Robot Can Earn](https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/)

## Intuition

The problem asks us to find the maximum path sum from the top-left to the bottom-right of a grid, with a twist: we can "neutralize" up to two negative values (robbers) along the path. 

This is a classic dynamic programming problem on a grid. A standard grid DP state is usually `dp[i][j]`, representing the maximum value reaching cell `(i, j)`. However, because our ability to neutralize robbers is limited (at most 2), we must track how many neutralizations have been used as part of our state.

We define `dp[i][j][k]` as the maximum coins the robot can have at cell `(i, j)` having used `k` neutralizations, where `k` is 0, 1, or 2.

At each cell `(i, j)`, the robot can arrive from the top `(i-1, j)` or the left `(i, j-1)`. 
1. If the robot does **not** use a neutralization at the current cell:
   - It simply adds `coins[i][j]` to the best possible values from the previous cells with the same number of neutralizations `k`.
2. If the robot **does** use a neutralization at the current cell (only beneficial if `coins[i][j] < 0`):
   - It takes the best possible value from the previous cells with `k-1` neutralizations and adds `0` instead of the negative `coins[i][j]`.

## Complexity Analysis

- **Time Complexity:** $O(m \times n)$, where $m$ is the number of rows and $n$ is the number of columns. We iterate through each cell of the grid once, and for each cell, we perform a constant number of operations (3 states for $k$).
- **Space Complexity:** $O(m \times n)$, as we store a 3D DP table of size $m \times n \times 3$. Note that this can be optimized to $O(n)$ by only storing the current and previous rows.