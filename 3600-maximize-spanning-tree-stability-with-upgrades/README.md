# 3600. Maximize Spanning Tree Stability with Upgrades

Property | Value
--- | ---
Difficulty | Hard
Topics | Binary Search, Greedy, Union-Find, Graph Theory, Minimum Spanning Tree
Date | 2026-03-12
LeetCode Link | [Maximize Spanning Tree Stability with Upgrades](https://leetcode.com/problems/maximize-spanning-tree-stability-with-upgrades/)

## Intuition

The problem asks us to find a valid spanning tree such that the minimum strength (stability) of its edges is maximized, subject to the constraints of "must-include" edges and a limited number of "upgrades."

1.  **Constraints of a Spanning Tree:** A spanning tree must include exactly $n-1$ edges and connect all $n$ nodes without cycles.
2.  **Mandatory Edges:** Any edge with `must_i == 1` **must** be included. If these mandatory edges already form a cycle, it is impossible to form a spanning tree, and we return -1.
3.  **Upgrades:** Optional edges (`must_i == 0`) can be upgraded once, doubling their strength. This costs 1 unit of $k$.
4.  **Stability Goal:** We want to maximize the threshold $X$ such that every edge in the tree has strength $\ge X$. This suggests a **Binary Search on Answer** approach for $X$, ranging from 1 to $2 \times 10^5$.

### The `check(X)` Strategy:
For a fixed stability threshold $X$:
1.  Verify that all mandatory edges already satisfy $s_i \ge X$. If even one mandatory edge is weaker than $X$, it's impossible to achieve stability $X$.
2.  Using a Union-Find (DSU) structure:
    *   Add all mandatory edges. If they form a cycle (checked during pre-processing), return false.
    *   Greedily add "Type A" optional edges: those that satisfy $s_i \ge X$ without an upgrade (Cost: 0).
    *   Greedily add "Type B" optional edges: those that satisfy $2s_i \ge X$ with an upgrade (Cost: 1), but only if they connect components not yet connected by Type A or mandatory edges.
3.  If the total number of components becomes 1 and the upgrades used are $\le k$, then stability $X$ is achievable.

## Complexity Analysis
- **Time Complexity:** $O(E \log(\max S) \cdot \alpha(N))$, where $E$ is the number of edges, $N$ is the number of nodes, and $S$ is the maximum strength. The binary search takes $\approx 18$ steps, and each step involves iterating over edges and performing Union-Find operations.
- **Space Complexity:** $O(N + E)$ to store the edge lists and the Union-Find parent/rank arrays.