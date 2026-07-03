# 3620. Network Recovery Pathways

| Property | Value |
| --- | --- |
| Difficulty | Hard |
| Topics | Array, Binary Search, Dynamic Programming, Graph Theory, Topological Sort, Dijkstra |
| Date | 2026-07-03 |
| LeetCode Link | [Network Recovery Pathways](https://leetcode.com/problems/network-recovery-pathways/) |

### Intuition

The problem asks to find the maximum possible "minimum edge cost" on a path from node 0 to $n-1$, subject to a total path cost constraint $k$ and the requirement that all intermediate nodes must be online.

1.  **Monotonicity**: Notice that if a path exists with a minimum edge cost of $X$, then a path also exists with a minimum edge cost of $Y$ for any $Y < X$ (using the same path). This property suggests that the result is monotonic, making **Binary Search on the Answer** an ideal approach.
2.  **Range**: The potential values for the answer range from the minimum edge cost in the graph to the maximum edge cost.
3.  **Feasibility Check**: For a fixed threshold $C$, we need to check if there exists a path from 0 to $n-1$ such that:
    *   Every edge $(u, v)$ in the path has $cost(u, v) \ge C$.
    *   Every node in the path (excluding source/sink) is `online`.
    *   The sum of costs of edges in the path is $\le k$.
4.  **Shortest Path**: This is equivalent to finding the shortest path (minimum cost) from 0 to $n-1$ in a filtered graph where we only include edges with $cost \ge C$ and only include nodes where `online[node]` is true. Since the graph is a Directed Acyclic Graph (DAG), we can compute the shortest path efficiently using Dynamic Programming (or Dijkstra, though DP is sufficient here).

### Complexity Analysis

*   **Time Complexity**: $O((N + M) \log(\text{max\_cost}))$.
    *   Binary search takes $O(\log(\text{max\_cost}))$ iterations.
    *   In each iteration, we perform a reachability/shortest-path check using DP or Dijkstra. Since it's a DAG, this takes $O(N + M)$.
*   **Space Complexity**: $O(N + M)$ to store the adjacency list and the `online` status array.