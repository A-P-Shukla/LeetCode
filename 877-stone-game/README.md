# 877. Stone Game

## Metadata Table
| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Math, Dynamic Programming, Game Theory |
| Date | August 2, 2026 |
| LeetCode Link | https://leetcode.com/problems/stone-game/ |

## Intuition

The problem asks whether Alice can always win a stone-picking game given an **even number** of piles and an **odd total sum** of stones, with players taking turns picking from either end of the row.

There are two primary ways to analyze this problem:

### 1. Dynamic Programming Approach (Interval DP)
If we generalize the problem to arbitrary game states, we can model it using Dynamic Programming:
- Let `dp[i][j]` represent the maximum net score difference (current player's score minus opponent's score) achievable from the subrange `piles[i...j]`.
- On their turn, the active player can pick either:
  1. `piles[i]`: yielding a net gain of `piles[i] - dp[i+1][j]`
  2. `piles[j]`: yielding a net gain of `piles[j] - dp[i][j-1]`
- The recurrence relation is:
  $$\text{dp}[i][j] = \max(\text{piles}[i] - \text{dp}[i+1][j],\, \text{piles}[j] - \text{dp}[i][j-1])$$
- If `dp[0][n-1] > 0`, Alice wins.

### 2. Mathematical Proof (O(1) Optimal Insight)
By carefully examining the problem constraints, we find that Alice can **always** force a win:
1. **Even Number of Piles**: We can color the piles alternately like a chessboard—even indices $0, 2, 4, \dots$ and odd indices $1, 3, 5, \dots$.
2. **Odd Total Sum**: The sum of stones at even indices and the sum of stones at odd indices cannot be equal. Therefore, one sum is strictly greater than the other:
   $$\sum \text{even piles} \neq \sum \text{odd piles}$$
3. **Alice's Strategy**:
   - If the sum of even-indexed piles is greater, Alice takes `piles[0]` on her first turn. This leaves Bob with choices at indices $1$ and $n-1$ (both odd indices). Whatever Bob picks, he exposes an even-indexed pile for Alice. Alice can repeat this to collect **all** even-indexed piles.
   - If the sum of odd-indexed piles is greater, Alice takes `piles[n-1]` on her first turn, forcing a similar trap to collect **all** odd-indexed piles.

Since Alice plays first and can choose whichever group has more stones, Alice is guaranteed to win every game. Thus, the answer is always `true`.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(1)$. Determining the outcome requires no iteration or array traversal because Alice always has a winning strategy.
- **Space Complexity:** $\mathcal{O}(1)$. No additional data structures or memory allocation are required.