# 874. Walking Robot Simulation

Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Hash Table, Simulation
Date | April 6, 2026
LeetCode Link | [https://leetcode.com/problems/walking-robot-simulation/](https://leetcode.com/problems/walking-robot-simulation/)

## Intuition

The problem is a direct simulation of a robot's movement on a 2D plane. To solve this efficiently, we need to handle three main components:
1.  **Direction Management:** The robot can face North, East, South, or West. We can represent these directions as vectors: `(0, 1)`, `(1, 0)`, `(0, -1)`, and `(-1, 0)`. Turning left or right simply cycles through these vectors in a specific order.
2.  **Obstacle Detection:** Since we move step-by-step, we need to check if the next coordinate is an obstacle. To make this check $O(1)$, we store the obstacle coordinates in a Hash Set. In C++, we can pack the $(x, y)$ coordinates into a single `long long` to avoid custom hash functions for pairs.
3.  **Distance Tracking:** The goal is to find the *maximum* squared Euclidean distance reached at any point. We calculate $x^2 + y^2$ after every successful step and update our global maximum.

The "step-by-step" movement is feasible here because each move command is small (at most 9 units), making the total number of steps roughly $9 \times 10^4$, which easily fits within time limits.

## Complexity Analysis
- **Time Complexity:** $O(N + M)$, where $N$ is the number of commands and $M$ is the number of obstacles. We iterate through obstacles once to store them ($O(M)$) and iterate through commands, performing a constant number of steps (max 9) per move command ($O(N)$).
- **Space Complexity:** $O(M)$ to store the coordinates of the obstacles in a hash set.