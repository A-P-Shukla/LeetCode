# 1886. Determine Whether Matrix Can Be Obtained By Rotation

Property | Value
--- | ---
Difficulty | Easy
Topics | Array, Matrix
Date | March 22, 2026
LeetCode Link | [https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/](https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/)

### Intuition
The problem asks if we can transform a source matrix `mat` into a `target` matrix using only 90-degree clockwise rotations. Since a rotation of 360 degrees returns the matrix to its original state, there are only four possible orientations to check: 0°, 90°, 180°, and 270°.

To implement the 90-degree clockwise rotation efficiently in-place:
1. **Transpose the matrix**: Swap elements across the main diagonal ($mat[i][j]$ with $mat[j][i]$).
2. **Reverse each row**: This completes the clockwise rotation.

Given the small constraints ($n \le 10$), we can simply perform these operations up to three times, checking for equality with the `target` matrix at each step (including the initial 0° state).

### Complexity Analysis
- **Time Complexity**: $O(n^2)$. In the worst case, we rotate the matrix 3 times and check for equality 4 times. Each rotation and each equality check involves visiting every element in the $n \times n$ matrix. Since 4 is a constant, the complexity remains $O(n^2)$.
- **Space Complexity**: $O(1)$. The rotation is performed in-place (if we modify the input) or uses a negligible amount of auxiliary variables.