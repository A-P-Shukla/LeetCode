# 1872. Stone Game VIII

### Metadata Table
Property | Value
--- | ---
Difficulty | Hard
Topics | Array, Math, Dynamic Programming, Game Theory, Prefix Sum
Date | 2026-08-24
LeetCode Link | https://leetcode.com/problems/stone-game-viii/

## Intuition

The game mechanics initially seem complex: removing $x$ leftmost stones, adding their sum to score, and placing a single new stone with that sum back on the left. However, observing how the prefix sums behave reveals a critical simplification.

Let `pref[i]` be the prefix sum of the array up to index $i$ (0-indexed). 
When a player chooses to merge the first $x$ stones ($x = i + 1 \ge 2$), they:
1. Earn `pref[i]` points.
2. Replace the first $x$ stones with a single stone of value `pref[i]`.

Notice that for any index $j > i$, the sum of stones from the beginning of the modified array up to index $j$ **remains exactly `pref[j]`**! Thus, the game is equivalent to players taking turns selecting strictly increasing indices $i_1 < i_2 < i_3 < \dots \le n-1$, starting from index $1$.

Let $dp[i]$ be the maximum score difference (current player's score - opponent's score) when the current player is forced to pick an index from $i$ to $n-1$.

At index $i$, the current player has two choices:
1. **Take index $i$**: The player gains `pref[i]` points, and the opponent plays the remaining game from $i+1$ onwards, obtaining optimal score difference $dp[i+1]$. The net score difference achieved is `pref[i] - dp[i+1]`.
2. **Skip index $i$**: The player passes the choice of taking index $i$ and instead looks for the best move starting from index $i+1$, which yields a score difference of $dp[i+1]$.

Thus, the recurrence relation is:
$$dp[i] = \max(dp[i+1], \text{pref}[i] - dp[i+1])$$

Since the game must end at index $n-1$ (where only 1 stone remains), our base case is:
$$dp[n-1] = \text{pref}[n-1]$$

By iterating backwards from $n-1$ down to $1$, we can compute the answer in $O(n)$ time and $O(1)$ auxiliary space by keeping track of the running prefix sum and the optimal DP value.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n)$, where $n$ is the length of the `stones` array. We compute the total sum of the array and perform a single pass from right to left.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space, as we only maintain a few scalar variables for the DP state and running prefix sum.