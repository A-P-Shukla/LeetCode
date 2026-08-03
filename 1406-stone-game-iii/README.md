# 1406. Stone Game III

### Metadata Table
Property | Value
--- | ---
Difficulty | Hard
Topics | Array, Math, Dynamic Programming, Game Theory
Date | August 3, 2026
LeetCode Link | https://leetcode.com/problems/stone-game-iii/

### Intuition

This problem can be modeled as a **zero-sum game** with two players playing optimally. Rather than tracking both players' absolute scores independently, we can simplify the game state by calculating the maximum **score difference** a player can achieve relative to their opponent from any given starting index.

Let $DP[i]$ represent the maximum score difference ($\text{Current Player Score} - \text{Opponent Score}$) that the current player can achieve starting from index $i$ to the end of the array.

At index $i$, the active player can choose to take $k \in \{1, 2, 3\}$ stones:
1. Taking $k$ stones yields an immediate gain equal to the sum of these $k$ stones: $\text{take} = \sum_{j=i}^{i+k-1} \text{stoneValue}[j]$.
2. The turn then transitions to the opponent starting from index $i + k$. The opponent will play optimally to maximize their score difference over the remaining stones, which is $DP[i+k]$.
3. From the current player's perspective, the opponent's relative score gain is subtracted from the current player's immediate gain: $\text{take} - DP[i+k]$.

To play optimally, the current player chooses $k \in \{1, 2, 3\}$ to maximize this net difference:
$$DP[i] = \max_{1 \le k \le 3} \left( \sum_{j=i}^{i+k-1} \text{stoneValue}[j] - DP[i+k] \right)$$

Working backwards from the end of the array to index $0$:
- If $DP[0] > 0$, Alice wins ("Alice").
- If $DP[0] < 0$, Bob wins ("Bob").
- If $DP[0] = 0$, it ends in a tie ("Tie").

Since $DP[i]$ only depends on $DP[i+1]$, $DP[i+2]$, and $DP[i+3]$, we can optimize space from $O(N)$ to $O(1)$ using modulo arithmetic over an array of size 4.

---

### Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the number of stones. We iterate through the array once from back to front, and at each index $i$, we perform at most 3 constant-time calculations.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary memory, as we only need to maintain the results of the last 4 DP states.

---