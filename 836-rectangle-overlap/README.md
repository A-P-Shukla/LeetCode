# 836. Rectangle Overlap

### Metadata
Property | Value
--- | ---
Difficulty | Easy
Topics | Math, Geometry
Date | September 14, 2026
LeetCode Link | https://leetcode.com/problems/rectangle-overlap/

---

### Intuition
Two 2D axis-aligned rectangles overlap if and only if their 1D projections onto both the x-axis and y-axis overlap with a non-zero length.

For two 1D intervals $[A, B]$ and $[C, D]$ representing the x-coordinates (where $A < B$ and $C < D$):
- They overlap if and only if $\max(A, C) < \min(B, D)$, which is equivalent to $A < D$ and $C < B$.
- If either rectangle is completely to the left/right of the other, they cannot overlap.

The same logic applies independently to the y-coordinates:
- The vertical segments overlap if and only if $\max(\text{rec1}[1], \text{rec2}[1]) < \min(\text{rec1}[3], \text{rec2}[3])$, or equivalently $\text{rec1}[1] < \text{rec2}[3]$ and $\text{rec2}[1] < \text{rec1}[3]$.

By checking if both horizontal and vertical projections overlap simultaneously, we can determine whether the two rectangles have an intersection with positive area.

---

### Complexity Analysis
- **Time Complexity:** $\mathcal{O}(1)$ — The algorithm performs a fixed number of constant-time coordinate comparisons.
- **Space Complexity:** $\mathcal{O}(1)$ — No additional data structures or memory are required.

---