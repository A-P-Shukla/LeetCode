# 2492. Minimum Score of a Path Between Two Cities

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Depth-First Search, Breadth-First Search, Union-Find, Graph Theory |
| Date | 2026-07-04 |
| LeetCode Link | https://problems/minimum-score-of-a-path-between-two-cities/ |

### Intuition

The problem asks for the minimum weight of an edge in any path between city 1 and city $n$. A critical observation is that we are allowed to traverse edges and visit cities multiple times. If city $1$ and city $n$ are in the same connected component, any road that belongs to that connected component can potentially be included in a path between 1 and $n$ (by traversing back and forth).

Therefore, the problem simplifies to finding the minimum weight among **all edges** belonging to the connected component that contains both city 1 and city $n$.

We can approach this using:
1.  **Graph Traversal (BFS/DFS):** Start a traversal from city 1, visit all reachable cities within the connected component, and keep track of the minimum weight edge encountered during the traversal.
2.  **Union-Find:** Initialize every city in its own set. For every edge `(u, v, dist)`, union the sets of `u` and `v`. After processing all edges, find all edges that belong to the component containing city 1 (or $n$) and identify the minimum distance among them.

The traversal method is generally more straightforward as it directly explores the component containing city 1.

### Complexity Analysis

*   **Time Complexity:** $O(V + E)$, where $V$ is the number of cities and $E$ is the number of roads. We perform a single BFS or DFS traversal, visiting each node and edge at most once.
*   **Space Complexity:** $O(V + E)$ to store the graph as an adjacency list and $O(V)$ for the visited array/queue used in traversal.