# 3619. Count Islands With Total Value Divisible by K
| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix |
| Date | 2026-10-26 |
| LeetCode Link | https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/ |

## Intuition & Approach
The grid defines land cells as any positive integer. An island is a maximal set of 4‑directionally connected land cells. The problem reduces to two sub‑tasks:

1. **Component Identification** – Traverse the matrix and discover each connected component of positive cells exactly once.
2. **Aggregate Check** – While discovering a component, accumulate the sum of its cell values and test divisibility by *k*.

A naïve recursive DFS risks stack overflow because *m·n* can reach 10⁵. Iterative BFS/DFS using an explicit queue avoids recursion limits and yields linear time. Union‑Find is also linear but requires two passes (union then aggregation) and extra bookkeeping; BFS is simpler and has lower constant factors.

Algorithm outline:
- Allocate a boolean `visited` array of size *m·n*.
- Iterate over every cell `(i, j)`. If `grid[i][j] > 0` and not visited, start a BFS.
- In the BFS:
  * Push the starting cell into a queue.
  * While the queue is non‑empty, pop a cell, add its value to a running `sum`, and explore its four neighbours (up, down, left, right) that are within bounds, positive, and unvisited.
- After the BFS finishes, `sum` equals the total value of the current island. Increment the answer if `sum % k == 0`.
- Continue scanning the grid; each land cell is visited exactly once.

The algorithm touches each cell a constant number of times → **O(m·n)** time, **O(m·n)** auxiliary space for the visited mask and BFS queue.

## Complexity Analysis
- **Time Complexity:** `O(m·n)`. Each cell is enqueued and dequeued at most once; neighbour checks are constant work.
- **Space Complexity:** `O(m·n)`. The `visited` bitmap consumes one byte per cell; the BFS queue’s peak size is bounded by the size of the largest island (≤ m·n).