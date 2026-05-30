# 3161. Block Placement Queries

Property | Value
--- | ---
Difficulty | Hard
Topics | Array, Binary Search, Segment Tree, Binary Indexed Tree
Date | May 30, 2026
LeetCode Link | [Block Placement Queries](https://leetcode.com/problems/block-placement-queries/)

## Intuition

The problem asks us to dynamically manage obstacles on a 1D line and find the maximum gap between consecutive obstacles within a range $[0, x]$. 

Let $S$ be the set of active obstacles. Initially, $S = \{0\}$.
When we query if a block of size $sz$ can be placed in $[0, x]$:
1. Find the largest active obstacle $prev \in S$ such that $prev \le x$.
2. The remaining space to the right of this obstacle is $[prev, x]$, which has length $x - prev$.
3. We also need to check if there is any interval of size $\ge sz$ between any two adjacent obstacles completely within $[0, prev]$. This is equivalent to finding:
   $$\max \{ v - \text{prev\_obstacle}(v) \mid v \in S, v \le prev \}$$
4. If either the maximum gap in $[0, prev]$ or the remaining space $x - prev$ is $\ge sz$, then we can place the block.

To handle these operations efficiently:
- We can maintain the active obstacles in a ordered container (`std::set` in C++, or a sorted list with `bisect` in Python).
- We can use a **Segment Tree** where each index $i$ stores the gap between $i$ and its immediate left neighbor if $i$ is an obstacle, and $0$ otherwise.
  - When we insert a new obstacle at $x$ between $prev$ and $next$:
    - The gap at $x$ becomes $x - prev$.
    - The gap at $next$ updates from $next - prev$ to $next - x$.
  - When we query, a range maximum query in the Segment Tree for $[0, prev]$ will give us the maximum gap in $O(\log N)$ time.

Since $x \le 50,000$ is relatively small, we can size our Segment Tree up to the maximum $x$ found in the queries.

## Complexity Analysis

- **Time Complexity:** 
  - **Finding max coordinate:** $O(Q)$ where $Q$ is the number of queries.
  - **Type 1 (Obstacle Placement):** $O(\log |S| + \log M)$ to search/insert into our set and perform point updates on the Segment Tree (where $M = \max(x) \le 50,000$).
  - **Type 2 (Range Query):** $O(\log |S| + \log M)$ to find the predecessor obstacle and perform range maximum query on the Segment Tree.
  - **Overall Time Complexity:** $O(Q \log M)$, which takes around 30-50ms in C++ and easily passes within the time limit.

- **Space Complexity:** $O(M + Q)$ to store the Segment Tree of size $O(M)$, the active obstacles, and the results.