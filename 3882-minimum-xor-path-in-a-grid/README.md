# 3882. Minimum XOR Path in a Grid

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Dynamic Programming, Bit Manipulation, Matrix |
| Date | 2026-10-28 |
| LeetCode Link | https://leetcode.com/problems/minimum-xor-path-in-a-grid/ |

## Intuition & Approach
The path restriction (only right or down) makes the grid a DAG.  
For each cell we can ask: *what XOR values are attainable when we arrive here?*  
Because every grid entry is ≤ 1023, any XOR of a path is also bounded by 10 bits, i.e. `0 … 1023`.  
Thus we can store, for every cell, a **bitset of size 1024** indicating reachable XOR totals.

Transition:
- From the top neighbour `(i‑1, j)` any reachable XOR `x` yields `x ^ grid[i][j]` at `(i, j)`.
- From the left neighbour `(i, j‑1)` the same rule applies.

The start cell `(0,0)` can only produce the XOR equal to its own value.  
Iterate rows then columns, merging the two predecessor bitsets via the XOR transformation.  
At the destination cell the smallest index whose bit is set is the answer.

Why not Dijkstra or BFS on the exponential state space?  
Because edge weights are XOR, which is not additive; traditional shortest‑path algorithms fail.  
The bounded‑bit observation reduces the state space to a constant factor (1024), making DP linear in `m·n·1024`, well within limits (`m·n ≤ 1000`).

## Complexity Analysis
- **Time:** `O(m · n · B)` where `B = 1024` (the size of the XOR domain). With the given constraints this is ≤ 1 024 000 operations.
- **Space:** `O(m · n · B)` bits, i.e. `O(m·n·1024)` ≈ 125 KB – 1 MB depending on representation; auxiliary space is `O(1)` beyond the DP table.