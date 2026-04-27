# 1391. Check if There is a Valid Path in a Grid

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix |
| Date | May 23, 2024 |
| LeetCode Link | [https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/](https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/) |

## Intuition

The problem asks whether we can navigate from the top-left corner `(0, 0)` to the bottom-right corner `(m-1, n-1)` of a grid, given specific connectivity rules for each cell (representing street types). 

This is a classic reachability problem on a graph/grid, which can be solved using **Breadth-First Search (BFS)** or **Depth-First Search (DFS)**. The key challenge lies in the "reciprocal connectivity" rule: moving from cell A to cell B is only valid if:
1. Cell A has an exit pointing towards cell B.
2. Cell B has an entrance pointing towards cell A.

To implement this efficiently:
1. **Represent Connections:** We can map each street type (1-6) to the directions it connects (represented as row and column offsets).
2. **Connectivity Check:** When attempting to move from `(r, c)` to a neighbor `(nr, nc)`, we verify if the offset `(nr - r, nc - c)` is a valid exit for the current street and if the reverse offset `(r - nr, c - nc)` is a valid exit for the neighbor's street.

## Complexity Analysis

- **Time Complexity:** $O(M \times N)$, where $M$ is the number of rows and $N$ is the number of columns. In the worst case, we visit every cell in the grid exactly once.
- **Space Complexity:** $O(M \times N)$ to maintain the `visited` array and the queue (for BFS) or recursion stack (for DFS).