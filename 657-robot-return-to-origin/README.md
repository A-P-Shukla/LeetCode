# 657. Robot Return to Origin

Property | Value
--- | ---
Difficulty | Easy
Topics | String, Simulation
Date | April 5, 2026
LeetCode Link | [Robot Return to Origin](https://leetcode.com/problems/robot-return-to-origin/)

### Intuition
The problem asks whether a sequence of movements on a 2D plane results in a net displacement of zero. To return to the origin $(0, 0)$, every step taken in one direction must be balanced by an equal number of steps in the opposite direction.

Specifically:
1.  **Vertical Axis:** The number of 'Up' ($U$) moves must equal the number of 'Down' ($D$) moves.
2.  **Horizontal Axis:** The number of 'Left' ($L$) moves must equal the number of 'Right' ($R$) moves.

We can model this using a coordinate system $(x, y)$. 
- 'U' increments $y$.
- 'D' decrements $y$.
- 'R' increments $x$.
- 'L' decrements $x$.

If the final values of $x$ and $y$ are both $0$, the robot has returned to its starting point.

### Complexity Analysis
- **Time Complexity:** $O(n)$, where $n$ is the length of the string `moves`. We iterate through the string exactly once to update the coordinates.
- **Space Complexity:** $O(1)$ because we only store two integer variables ($x$ and $y$) regardless of the input size.