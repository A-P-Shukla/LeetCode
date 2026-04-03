# 3661. Maximum Walls Destroyed by Robots

Property | Value
--- | ---
Difficulty | Hard
Topics | Array, Binary Search, Dynamic Programming, Sorting
Date | April 3, 2026
LeetCode Link | [Maximum Walls Destroyed by Robots](https://leetcode.com/problems/maximum-walls-destroyed-by-robots/)

## Intuition

The problem asks us to find the maximum number of unique walls destroyed by a set of robots, where each robot can fire a single bullet either to the left or to the right. The bullet stops if it hits another robot, meaning robots act as fixed barriers.

### Key Observations:
1.  **Robot Barriers:** Because robots stop bullets, the decisions of one robot only affect the walls in the immediate gaps to its left and right. Robot $i$ can only destroy walls between itself and Robot $i-1$ (if firing left) or between itself and Robot $i+1$ (if firing right).
2.  **Wall Types:** We can categorize walls into two types:
    *   **Robot-Walls:** Walls located exactly at a robot's position. Since a robot fires either left or right, it will *always* destroy a wall at its own position (as long as its range is $\ge 0$, and the problem states distance $\ge 1$).
    *   **Gap-Walls:** Walls located in the open spaces between robots.
3.  **Independence of Gaps:** A wall in the gap $(R_{i-1}, R_i)$ can only be destroyed by Robot $i-1$ firing right or Robot $i$ firing left. No other robot can reach this gap because the bullet would be blocked by Robot $i-1$ or Robot $i$.

### Approach:
Since the state of a robot only influences the gaps adjacent to it, we can use **Dynamic Programming**.
*   **State:** Let $DP[i][0]$ be the max walls destroyed by robots $0 \dots i$ where Robot $i$ fires **Left**.
*   **State:** Let $DP[i][1]$ be the max walls destroyed by robots $0 \dots i$ where Robot $i$ fires **Right**.

When moving from robot $i-1$ to robot $i$, we consider the walls destroyed in the gap $G_i = (R_{i-1}, R_i)$. The number of walls hit in $G_i$ depends on whether $i-1$ fired right and whether $i$ fired left.
*   If $D_{i-1} = \text{Left}, D_i = \text{Left}$: Only $i$ hits walls in $G_i$ (suffix of the gap).
*   If $D_{i-1} = \text{Right}, D_i = \text{Right}$: Only $i-1$ hits walls in $G_i$ (prefix of the gap).
*   If $D_{i-1} = \text{Left}, D_i = \text{Right}$: No walls in $G_i$ are hit.
*   If $D_{i-1} = \text{Right}, D_i = \text{Left}$: The union of the prefix and suffix is hit.

We use **Binary Search** (lower_bound/upper_bound) to quickly count walls within specific coordinate ranges.

## Complexity Analysis
- **Time Complexity:** $O((N+M) \log (N+M))$, where $N$ is the number of robots and $M$ is the number of walls. We sort both arrays ($O(N \log N + M \log M)$) and then iterate through robots once, performing $O(1)$ binary searches ($O(\log M)$) at each step.
- **Space Complexity:** $O(N + M)$ to store the sorted robots and walls.