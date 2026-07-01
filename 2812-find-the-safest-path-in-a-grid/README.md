# 2812. Find the Safest Path in a Grid

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Binary Search, Breadth-First Search, Union-Find, Heap (Priority Queue), Matrix |
| Date | 2026-07-01 |
| LeetCode Link | [https://leetcode.com/problems/find-the-safest-path-in-a-grid/](https://leetcode.com/problems/find-the-safest-path-in-a-grid/) |

### Intuition

This problem requires finding a path from (0,0) to (n-1, n-1) that maximizes the minimum distance to any thief. This is a classic "bottleneck path" problem, which can be solved effectively using a two-step approach:

1.  **Precompute Distances**: Since we need the distance of every cell to the nearest thief, we can use a **Multi-Source Breadth-First Search (BFS)**. We initialize the queue with all thief positions (`grid[i][j] == 1`) and compute the shortest distance from these sources to all other cells.
2.  **Find the Maximum Safeness**: Now that each cell $(r, c)$ has a "safeness score" (its distance to the nearest thief), we want to find a path where the *minimum* score on the path is maximized.
    *   **Option A (Priority Queue)**: Use a Max-Heap (Dijkstra-like) to greedily pick the path that keeps the minimum distance as high as possible.
    *   **Option B (Binary Search)**: Binary search on the possible safeness factor $k$. For a fixed $k$, check if a path exists from $(0,0)$ to $(n-1, n-1)$ using only cells with a safeness score $\ge k$ using standard BFS or DFS.

Using a Priority Queue is generally more intuitive for "widest path" problems as it explores cells in descending order of their safeness.

### Complexity Analysis

*   **Time Complexity**: $O(n^2 \log n)$. 
    *   Multi-source BFS takes $O(n^2)$ to visit every cell.
    *   The Priority Queue approach explores each cell once, performing $O(\log(n^2)) = O(\log n)$ operations per cell.
*   **Space Complexity**: $O(n^2)$ to store the distance matrix and the visited state for BFS/Dijkstra.