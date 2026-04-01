# 2751. Robot Collisions

Property | Value
--- | ---
Difficulty | Hard
Topics | Array, Stack, Sorting, Simulation
Date | April 1, 2026
LeetCode Link | [https://leetcode.com/problems/robot-collisions/](https://leetcode.com/problems/robot-collisions/)

## Intuition

The problem describes a physical simulation where robots move along a 1D line and collide. Key observations are:
1. Collisions only occur between a robot moving Right ('R') and a robot moving Left ('L') that is currently to its right.
2. When two robots move in the same direction, they will never collide because they move at the same speed.
3. When two robots move away from each other (an 'L' robot to the left of an 'R' robot), they will never collide.

To handle collisions efficiently, we must process robots in the order they appear on the line (sorted by position). This allows us to use a **Stack** to manage robots moving 'R'. As we iterate through the sorted robots:
- If we encounter an 'R' robot, we push it onto the stack because it might collide with any 'L' robot appearing later in the sequence.
- If we encounter an 'L' robot, it will potentially collide with the most recent 'R' robot (the top of the stack). We resolve these collisions one by one until either the 'L' robot is destroyed, the stack of 'R' robots is empty, or the 'L' robot destroys the 'R' robot and moves on to the next one in the stack.

## Complexity Analysis

- **Time Complexity:** $O(N \log N)$, where $N$ is the number of robots. Sorting the indices based on positions takes $O(N \log N)$. The subsequent pass through the robots involves each robot being pushed and popped from the stack at most once, resulting in $O(N)$ for the simulation.
- **Space Complexity:** $O(N)$ to store the indices for sorting and the stack used for simulation.