# 1510. Stone Game IV

| Property | Value |
| --- | --- |
| Difficulty | Hard |
| Topics | Math, Dynamic Programming, Game Theory |
| Date | August 10, 2026 |
| LeetCode Link | [LeetCode - Stone Game IV](https://leetcode.com/problems/stone-game-iv/) |

## Intuition

This problem can be framed as an **impartial game** under normal play convention, where two players take turns making valid moves, and the first player who cannot make a move loses.

To determine if Alice ( the first player ) wins from a starting state of $n$ stones, we can categorize states as either **winning** or **losing**:
- A state is a **losing state** (`False`) if every valid move leads to a winning state for the opponent.
- A state is a **winning state** (`True`) if there is at least one valid move that leaves the opponent in a losing state.

We can solve this problem using **Dynamic Programming**. Let `dp[i]` represent whether the player whose turn it is with $i$ stones remaining will win.

- **Base Case**: `dp[0] = False`, because a player facing 0 stones has no moves available and loses.
- **State Transition**: For $i$ stones, a player can pick any non-zero square number $k^2 \le i$. If `dp[i - k^2]` is `False` for any $k$, it means the opponent will lose if given `i - k^2` stones. Thus, the current player can guarantee a win by picking $k^2$ stones, so `dp[i] = True`. If all available moves lead to states where `dp[i - k^2]` is `True`, then the current player cannot avoid losing, so `dp[i] = False`.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n \sqrt{n})$. For each state $i$ from $1$ to $n$, we iterate through all perfect squares $k^2 \le i$. The total number of operations is proportional to $\sum_{i=1}^n \sqrt{i} \approx \int_0^n \sqrt{x} \, dx = \frac{2}{3} n^{3/2} = \mathcal{O}(n \sqrt{n})$. With $n = 10^5$, $n \sqrt{n} \approx 3.16 \times 10^7$ operations, which easily runs within time limits.
- **Space Complexity:** $\mathcal{O}(n)$ auxiliary space for the `dp` array of size $n + 1$.