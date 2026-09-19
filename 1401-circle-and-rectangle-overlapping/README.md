# 1401. Circle and Rectangle Overlapping

### Metadata Table
Property | Value
--- | ---
Difficulty | Medium
Topics | Math, Geometry
Date | September 19, 2026
LeetCode Link | https://leetcode.com/problems/circle-and-rectangle-overlapping/

### Intuition
To check if a circle and an axis-aligned rectangle overlap, we need to determine if any point inside or on the boundary of the rectangle is within a distance of `radius` from the center of the circle `(xCenter, yCenter)`.

Instead of checking all infinite points, we can solve this by finding the single point $(x_p, y_p)$ on or inside the rectangle that is **closest** to the center of the circle. Since the rectangle is aligned with the coordinate axes, we can determine $x_p$ and $y_p$ independently by clamping the circle's center coordinates to the bounds of the rectangle:
- $x_p = \max(x_1, \min(xCenter, x_2))$
- $y_p = \max(y_1, \min(yCenter, y_2))$

Once we find this closest point $(x_p, y_p)$, we calculate the squared Euclidean distance between $(xCenter, yCenter)$ and $(x_p, y_p)$. If this squared distance is less than or equal to $radius^2$, the circle and rectangle overlap.

### Complexity Analysis
- **Time Complexity:** $\mathcal{O}(1)$. Calculating the clamped coordinates and squared distance involves a fixed number of basic arithmetic and comparison operations.
- **Space Complexity:** $\mathcal{O}(1)$. No additional data structures or memory are required.