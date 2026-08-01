# 486. Predict the Winner

### Metadata
Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Math, Dynamic Programming, Recursion, Game Theory
Date | August 1, 2026
LeetCode Link | [Predict the Winner](https://leetcode.com/problems/predict-the-winner/)

## Intuition

The problem can be modeled as a zero-sum game played on a subarray `nums[i...j]`. At any point in the game, the active player can choose either the left element `nums[i]` or the right element `nums[j]`. 

Because both players play optimally, each player aims to maximize the net score difference between themselves and their opponent:
$$\text{Net Score Difference} = \text{Current Player's Score} - \text{Opponent's Score}$$

When player 1 picks `nums[i]`, player 2 is left with the range `[i + 1, j]`. The maximum net difference player 2 can achieve from `[i + 1, j]` is `dp(i + 1, j)`. Thus, from player 1's perspective, picking `nums[i]` yields a net gain of `nums[i] - dp(i + 1, j)`.
Similarly, picking `nums[j]` yields a net gain of `nums[j] - dp(i, j - 1)`.

The active player will pick the option that maximizes this net difference:
$$\text{dp}(i, j) = \max(\text{nums}[i] - \text{dp}(i + 1, j), \text{nums}[j] - \text{dp}(i, j - 1))$$

Base Case:
When $i == j$, only one number remains, so $\text{dp}(i, i) = \text{nums}[i]$.

If Player 1 can achieve a non-negative final net score ($\text{dp}(0, n - 1) \ge 0$), Player 1 wins or ties, so we return `true`. We can optimize the 2D DP state into a 1D array since calculating the current row $i$ only depends on the previous row $i + 1$.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n^2)$ where $n$ is the length of `nums`. There are $n(n + 1) / 2$ states, and each state takes $\mathcal{O}(1)$ time to compute.
- **Space Complexity:** $\mathcal{O}(n)$ using a 1D dynamic programming array to maintain state across subproblems.

---