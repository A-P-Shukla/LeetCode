# 1140. Stone Game II

### Metadata Table
Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Dynamic Programming, Math, Game Theory, Prefix Sum
Date | 2026-08-09
LeetCode Link | https://leetcode.com/problems/stone-game-ii/

---

### Intuition

The problem models a zero-sum game played optimally by two players. Alice wants to maximize the total number of stones she collects. Since all pile values are positive, both players will always play to maximize their own total stones.

Key insights:
1. **Minimax / Game Theory Relationship**: At any point starting at index $i$ with parameter $M$, the total stones available from index $i$ to the end of the array is fixed and equal to the suffix sum `suffix_sum[i]`. If the current player takes $X$ piles ($1 \le X \le 2M$), the next player will face the state $(i + X, \max(M, X))$ and play optimally to collect the maximum stones possible from that point on. Therefore, the current player's optimal score from state $(i, M)$ is:
   $$\text{dp}(i, M) = \max_{1 \le X \le 2M} (\text{suffix\_sum}[i] - \text{dp}(i + X, \max(M, X)))$$
2. **Base Case / Greedy End**: If the current player can take all remaining piles ($i + 2M \ge n$), it is always optimal to do so, yielding all remaining stones `suffix_sum[i]`.
3. **State Representation**: The state of the game is uniquely defined by $(i, M)$, where $i$ is the starting index of remaining piles, and $M$ is the current step parameter. Using Top-Down Dynamic Programming with Memoization avoids redundant computations.

---

### Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n^3)$
  There are $\mathcal{O}(n)$ choices for index $i$ ($0 \le i < n$) and $\mathcal{O}(n)$ possible values for $M$ ($1 \le M \le n$). For each state $(i, M)$, we loop up to $2M \le 2n$ times to evaluate choices of $X$. Thus, the total number of operations is bounded by $\mathcal{O}(n^3)$. With $n \le 100$, $100^3 / 6 \approx 1.6 \times 10^5$ operations, which easily runs within time limits.

- **Space Complexity:** $\mathcal{O}(n^2)$
  The recursion depth is bounded by $\mathcal{O}(n)$, and the memoization table requires $\mathcal{O}(n^2)$ memory to store the computed optimal values for each state $(i, M)$.

---