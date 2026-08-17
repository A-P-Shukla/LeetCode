# 1563. Stone Game V

Property | Value
--- | ---
Difficulty | Hard
Topics | Array, Math, Dynamic Programming, Game Theory
Date | 2026-08-17
LeetCode Link | https://leetcode.com/problems/stone-game-v/

## Intuition

The problem asks for the maximum score Alice can obtain by repeatedly partitioning a contiguous subarray of stones into two non-empty subarrays, discarding the one with the strictly larger sum (or choosing which one to discard if sums are equal), and continuing the game with the retained subarray until only one stone remains.

Since at each step Alice retains a contiguous subarray of the original array, we can define subproblems based on subarray boundaries $[i, j]$.

Let $DP[i][j]$ represent the maximum score Alice can achieve from the subarray `stoneValue[i...j]`.
- **Base Case:** If $i == j$, there is only one stone remaining, so $DP[i][i] = 0$.
- **Transition:** For a subarray `stoneValue[i...j]`, we can split it at any index $k$ such that $i \le k < j$.
  - Let $S_L$ be the sum of `stoneValue[i...k]` and $S_R$ be the sum of `stoneValue[k+1...j]`.
  - If $S_L < S_R$: Bob discards the right part, and Alice receives $S_L + DP[i][k]$.
  - If $S_L > S_R$: Bob discards the left part, and Alice receives $S_R + DP[k+1][j]$.
  - If $S_L == S_R$: Alice can choose either part to keep, maximizing her score: $S_L + \max(DP[i][k], DP[k+1][j])$.

We iterate over all possible split points $k \in [i, j-1]$ and take the maximum possible score. Using prefix sums allows us to compute any subarray sum in $O(1)$ time. 

With $n \le 500$, an $O(n^3)$ interval dynamic programming approach with memoization or iterative bottom-up evaluation runs efficiently and comfortably within standard time limits.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n^3)$, where $n$ is the number of stones. There are $\mathcal{O}(n^2)$ states (subarrays $[i, j]$), and for each state, we iterate over up to $n-1$ partition points $k$.
- **Space Complexity:** $\mathcal{O}(n^2)$ for the 2D memoization table / DP table, and $\mathcal{O}(n)$ for the prefix sum array and recursion call stack.