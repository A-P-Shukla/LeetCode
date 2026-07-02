# 3286. Find a Safe Walk Through a Grid

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Breadth-First Search, Graph Theory, Matrix, Shortest Path |
| Date | 2026-07-02 |
| LeetCode Link | [https://leetcode.com/problems/find-a-safe-walk-through-a-grid/](https://leetcode.com/problems/find-a-safe-walk-through-a-grid/) |

### Intuition

The problem asks whether we can reach the bottom-right corner of a grid starting from the top-left while maintaining positive health. An "unsafe" cell (value 1) reduces health by 1. To maximize our chances of success, we want to minimize the total number of "unsafe" cells encountered along any path.

This is a classic shortest-path problem on a grid. Instead of using distance as the metric, we use the number of 1s (unsafe cells) as the cost. Since we want to find *any* path that keeps health > 0 (i.e., cost < initial_health), we can use Dijkstra's algorithm or 0-1 BFS. 

Given that the edge weights are either 0 or 1, a 0-1 BFS using a deque is highly efficient. We maintain the minimum cost (number of 1s) to reach each cell. If a path costs less than `health`, we can reach the goal.

### Complexity Analysis

- **Time Complexity:** O(M * N), where M is the number of rows and N is the number of columns. Each cell is added to and removed from the deque at most once.
- **Space Complexity:** O(M * N) to store the `min_health_lost` matrix and the deque.