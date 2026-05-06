# 1861. Rotating the Box

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Two Pointers, Matrix |
| Date | May 6, 2026 |
| LeetCode Link | [https://leetcode.com/problems/rotating-the-box/](https://leetcode.com/problems/rotating-the-box/) |

## Intuition

The problem requires two main transformations: simulating gravity and rotating the matrix 90 degrees clockwise. 

1.  **Gravity Simulation**: In a 90-degree clockwise rotation, the "bottom" of the box corresponds to the right side of the original rows. Therefore, gravity pulls stones (`#`) to the right until they hit an obstacle (`*`), another stone, or the boundary of the box. 
    *   We can process each row independently. 
    *   Using a two-pointer approach within each row allows us to move stones to their lowest possible position (rightmost) in $O(N)$ time. We keep track of an `emptyPos` pointer representing the rightmost available slot.

2.  **Matrix Rotation**: A standard 90-degree clockwise rotation transforms a matrix of size $M \times N$ into $N \times M$.
    *   The element at original position `(row, col)` moves to the new position `(col, (M - 1) - row)`.

By applying gravity first on the horizontal rows and then performing the rotation, we simplify the coordinate mapping.

## Complexity Analysis

-   **Time Complexity**: $O(M \times N)$, where $M$ is the number of rows and $N$ is the number of columns. We iterate through every cell once for gravity simulation and once more for the rotation.
-   **Space Complexity**: $O(M \times N)$ if we count the space required for the output matrix. The gravity simulation itself is performed in-place on the input grid.