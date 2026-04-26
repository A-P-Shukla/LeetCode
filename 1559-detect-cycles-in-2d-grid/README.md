# 1559. Detect Cycles in 2D Grid

Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix
Date | April 26, 2026
LeetCode Link | [https://leetcode.com/problems/detect-cycles-in-2d-grid/](https://leetcode.com/problems/detect-cycles-in-2d-grid/)

## Intuition

The problem asks us to find a cycle of the same character in a 2D grid. A cycle is defined as a path of length 4 or more that returns to the starting cell without moving back directly to the immediate parent cell.

This is fundamentally a cycle detection problem in an undirected graph. Each cell $(r, c)$ in the grid represents a node, and an edge exists between two adjacent cells if they contain the same character.

### Approaches:
1.  **Depth-First Search (DFS):** We can traverse the grid using DFS. For each unvisited cell, we start a DFS traversal. We keep track of the `parent` cell from which we arrived at the current cell. If we encounter a neighbor that is already `visited` and is **not** the parent of the current cell, we have found a cycle.
2.  **Union-Find (Disjoint Set Union):** We can iterate through every cell and its neighbors (specifically, right and down to avoid duplicate processing). If two adjacent cells have the same character, we check if they already belong to the same disjoint set. If they do, adding the current edge completes a cycle. If they don't, we union the two sets.

Given the constraints ($500 \times 500$), both methods are efficient. In Python, Union-Find is often preferred to avoid hitting the default recursion depth limit.

## Complexity Analysis

### Time Complexity
**$O(M \times N \cdot \alpha(M \times N))$**
Where $M$ is the number of rows and $N$ is the number of columns.
- For Union-Find, we iterate through all cells once and perform `find` and `union` operations. $\alpha$ is the inverse Ackermann function, which is nearly constant.
- For DFS, we visit each cell and each edge once, resulting in $O(M \times N)$.

### Space Complexity
**$O(M \times N)$**
- For Union-Find, we store the `parent` (and optionally `rank`) array of size $M \times N$.
- For DFS, the recursion stack and the `visited` matrix both take $O(M \times N)$ space.