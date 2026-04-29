# 3225. Maximum Score From Grid Operations

Property | Value
--- | ---
Difficulty | Hard
Topics | Array, Dynamic Programming, Matrix, Prefix Sum
Date | April 29, 2026
LeetCode Link | [Maximum Score From Grid Operations](https://leetcode.com/problems/maximum-score-from-grid-operations/)

## Intuition

The problem asks us to find the maximum sum of grid values that are "white" and adjacent to at least one "black" cell horizontally. The operation of coloring column $j$ down to row $i$ means the black cells in column $j$ are at rows $[0, i]$. Thus, if column $j$ has a height $H_j$, cells $(0, j) \dots (H_j-1, j)$ are black, and $(H_j, j) \dots (n-1, j)$ are white.

A cell $(i, j)$ contributes to the score if:
1. It is white: $i \ge H_j$.
2. It is horizontally adjacent to a black cell: $H_{j-1} > i$ OR $H_{j+1} > i$.

Combining these, cell $(i, j)$ contributes if $H_j \le i < \max(H_{j-1}, H_{j+1})$.
The score for column $j$ is the sum of `grid[i][j]` for rows $i \in [H_j, \max(H_{j-1}, H_{j+1}) - 1]$. Using prefix sums $P[j][h] = \sum_{row=0}^{h-1} grid[row][j]$, this score is:
$$\text{Score}(j) = \max(0, P[j][\max(H_{j-1}, H_{j+1})] - P[j][H_j])$$

This dependency on $H_{j-1}, H_j, H_{j+1}$ suggests a Dynamic Programming approach. By tracking the heights of the current and previous columns, we can calculate the contribution of the previous column based on the height we choose for the next column.

## Complexity Analysis

- **Time Complexity**: $O(n^3)$, where $n$ is the dimension of the grid. For each column, we iterate through all possible current heights $H_j$ and next heights $H_{j+1}$, using precomputed prefix maximums to handle the previous heights $H_{j-1}$ in $O(1)$ time.
- **Space Complexity**: $O(n^2)$. We store a 2D DP table `dp[height_curr][height_prev]` and prefix sums. While the logical state is $O(n^3)$, we only need the previous column's DP values to compute the current one.