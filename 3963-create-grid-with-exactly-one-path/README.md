# 3963. Create Grid With Exactly One Path

| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | Array, Construction |
| Date | 2026-10-27 |
| LeetCode Link | https://leetcode.com/problems/create-grid-with-exactly-one-path/ |

## Intuition & Approach
The only moves allowed are **right** and **down**, which forces any feasible path to be monotone (row and column indices never decrease).  
If we make **every** cell an obstacle (`'#'`) except the cells along a single monotone route from the start to the finish, there cannot exist any alternative route: deviating from the designated cells would immediately hit a `'#'`. Therefore the constructed grid has **exactly one** valid path.

A straightforward monotone route is:
1. Move **down** from `(0,0)` to `(m‑1,0)`.
2. Move **right** from `(m‑1,0)` to `(m‑1,n‑1)`.

All cells on this L‑shaped corridor are set to `'.'`; the rest stay `'#'`.  
Edge cases (`m == 1` or `n == 1`) are naturally handled because the “down” segment collapses to a single cell or the “right” segment collapses, leaving a straight line of `'.'`.

## Complexity Analysis
*Time*: Initializing the grid costs `O(m·n)`. Marking the L‑shaped path touches `O(m+n)` cells, which is dominated by the initialization.  
*Space*: The output grid itself uses `O(m·n)` space; auxiliary variables use `O(1)`.