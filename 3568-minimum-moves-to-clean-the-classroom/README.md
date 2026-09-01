# 3419. Min Moves to Clean Classroom

Property | Value
--- | ---
Difficulty | Hard
Topics | Array, Bit Manipulation, Breadth-First Search, Matrix
Date | September 1, 2026
LeetCode Link | https://leetcode.com/problems/min-moves-to-clean-classroom/

## Intuition

The problem asks for the minimum number of moves required to collect all litter items scattered across a grid while managing a limited energy budget that can be replenished at reset cells (`'R'`).

Since we want to find the **minimum number of moves** (shortest path in an unweighted state graph), **Breadth-First Search (BFS)** is the natural algorithm to use. However, a standard BFS over grid positions $(r, c)$ is insufficient because the state depends on:
1. The student's current position $(r, c)$.
2. The set of collected litter items (represented as a bitmask `mask`).
3. The remaining energy `e`.

Given that there are at most 10 litter cells ($K \le 10$), the bitmask has $2^K \le 1024$ states.

### State Optimization & Dominance Pruning
Instead of tracking full 4D states $(r, c, mask, e)$, we can observe a key property:
- BFS naturally explores paths in increasing order of step counts.
- For a specific state $(r, c, mask)$, if we reach it at step $S_1$ with energy $E_1$, and later (at step $S_2 \ge S_1$) we reach the exact same $(r, c, mask)$ with energy $E_2 \le E_1$, the second state is **strictly dominated** by the first state. It took equal or more steps and has equal or less energy.

Therefore, we only need to maintain a 3D array `max_energy[r][c][mask]` which stores the maximum remaining energy achieved at position $(r, c)$ with collected litters `mask`.
- If a new move reaches $(r, c, nmask)$ with energy $ne > \text{max\_energy}[r][c][nmask]$, we record the new maximum energy and push the state to the BFS queue.
- Otherwise, the state is pruned.

This reduces the maximum number of queue states to $M \times N \times 2^K \approx 20 \times 20 \times 1024 = 409,600$, guaranteeing fast execution.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(M \cdot N \cdot 2^K)$, where $M$ and $N$ are the dimensions of the grid ($M, N \le 20$) and $K$ is the number of litter items ($K \le 10$). Each state $(r, c, mask)$ is visited at most once for each distinct, strictly increasing energy level. In practice, the state space is bounded by $M \cdot N \cdot 2^K \approx 4.1 \times 10^5$ states, running well within standard time limits.
- **Space Complexity:** $\mathcal{O}(M \cdot N \cdot 2^K)$ to store the `max_energy` lookup table and the BFS queue.

---