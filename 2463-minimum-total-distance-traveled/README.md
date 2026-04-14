# 2463. Minimum Total Distance Traveled

### Metadata Table
Property | Value
--- | ---
Difficulty | Hard
Topics | Array, Dynamic Programming, Sorting
Date | October 31, 2024
LeetCode Link | [Minimum Total Distance Traveled](https://leetcode.com/problems/minimum-total-distance-traveled/)

### Intuition
The problem asks us to match robots to factories while minimizing the total distance traveled. Each factory has a specific capacity. A key insight for problems involving matching points on a 1D line is that **relative order is preserved in an optimal solution**. 

Specifically, if we sort both the robots and the factories by their positions, the robots assigned to a specific factory will always be a contiguous segment of the sorted robots array. If robot $i$ is assigned to factory $j$ and robot $i+1$ is assigned to factory $k$, then $j$ must be less than or equal to $k$.

Based on this observation, we can use **Dynamic Programming**. We define a state based on the current robot index and the current factory index. At each step, we decide how many robots (from 0 up to the factory's limit) to assign to the current factory and then move to the next factory.

### Complexity Analysis
- **Time Complexity:** $O(M \cdot N^2)$, where $M$ is the number of factories and $N$ is the number of robots. We have $M \times N$ states in our DP, and for each state, we iterate up to $N$ times (the limit of a factory) to decide how many robots to assign.
- **Space Complexity:** $O(M \cdot N)$ to store the memoization table.