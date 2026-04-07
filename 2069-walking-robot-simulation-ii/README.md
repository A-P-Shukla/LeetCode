# 2069. Walking Robot Simulation II

Property | Value
--- | ---
Difficulty | Medium
Topics | Design, Simulation
Date | April 7, 2026
LeetCode Link | [Walking Robot Simulation II](https://leetcode.com/problems/walking-robot-simulation-ii/)

## Intuition
The robot moves along the perimeter of a `width x height` grid. Instead of simulating every single step (which could be up to $10^5$ per call), we can model the robot's movement using its position on the perimeter path.

1.  **Perimeter Calculation**: The path is a loop. The number of unique steps required to return to the start $(0,0)$ is $P = 2 \times (width - 1) + 2 \times (height - 1)$.
2.  **Modular Arithmetic**: Since the path is a loop, any number of steps $N$ can be reduced using $idx = (idx + N) \mod P$.
3.  **Direction Logic**: The robot only turns when it attempts to move out of bounds. This means its direction is determined by which segment of the perimeter it is currently on. 
    *   Bottom edge (East)
    *   Right edge (North)
    *   Top edge (West)
    *   Left edge (South)
4.  **Corner Case (0,0)**: Initially, the robot is at $(0,0)$ facing "East". However, if the robot completes one or more full laps and returns to $(0,0)$, it arrives from the "South" and stays facing "South" because it hasn't yet attempted a move that would force it to turn "East" again.

## Complexity Analysis
- **Time Complexity**: 
    - `Robot()` constructor: $O(1)$
    - `step()`: $O(1)$
    - `getPos()`: $O(1)$
    - `getDir()`: $O(1)$
    All operations are constant time as they rely on simple arithmetic and range checks.
- **Space Complexity**: $O(1)$ as we only store a few integers and a boolean flag.