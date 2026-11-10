# 3693. Climbing Stairs II

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Dynamic Programming |
| Date | 2026-11-10 |
| LeetCode Link | https://leetcode.com/problems/climbing-stairs-ii/ |

## Intuition & Approach
The staircase can be represented as a directed acyclic graph where each step *i* (0 ≤ *i* ≤ *n*) has outgoing edges to *i+1*, *i+2*, *i+3*.  
The edge weight from *i* to *j* is  
`costs[j] + (j‑i)²`.  
Because every edge points forward, the optimal cost to reach a step depends **only** on the optimal costs of the three preceding steps. This is the classic recurrence of a one‑dimensional DP.

A naïve BFS/DFS would explore exponentially many paths. The DP recurrence collapses this exponential search space to linear time:

```
dp[0] = 0
dp[i] = min_{k∈{1,2,3}, i‑k≥0}  dp[i‑k] + costs[i] + k²      (1 ≤ i ≤ n)
```

`costs` is 1‑indexed in the statement; in code we use `costs[i‑1]`.  
The recurrence accesses only the three previous states, so we can keep a rolling array of size three, achieving O(1) auxiliary space.

The algorithm proceeds forward from step 1 to step *n*, applying (1) at each iteration and finally returning `dp[n]`.

## Complexity Analysis
- **Time Complexity:** Each step evaluates up to three candidate jumps ⇒ **O(n)**.
- **Space Complexity:** Only three previous DP values are stored ⇒ **O(1)** auxiliary space (output value excluded).