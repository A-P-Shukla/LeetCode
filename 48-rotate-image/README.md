# 48. Rotate Image

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Math, Matrix |
| Date | May 4, 2026 |
| LeetCode Link | [https://leetcode.com/problems/rotate-image/](https://leetcode.com/problems/rotate-image/) |

## Intuition

Rotating a matrix 90 degrees clockwise manually involves moving elements from $(row, col)$ to $(col, n - 1 - row)$. While we could perform this rotation layer by layer using a four-way swap, a more elegant and readable approach involves two basic linear algebra transformations:

1.  **Transpose the Matrix:** Convert all rows into columns (swap `matrix[i][j]` with `matrix[j][i]`). This effectively reflects the matrix over its main diagonal.
2.  **Reverse Each Row:** Flip each row horizontally.

**Why this works:**
After transposing, the element that was at $(i, j)$ moves to $(j, i)$. After reversing the row, the element moves from $(j, i)$ to $(j, n - 1 - i)$. This matches the desired transformation for a 90-degree clockwise rotation. This method is preferred in technical interviews because it is less error-prone than complex index manipulation.

## Complexity Analysis

-   **Time Complexity:** $O(n^2)$, where $n$ is the number of rows/columns. We traverse the matrix twice: once for the transposition (visiting roughly half the elements) and once for reversing the rows.
-   **Space Complexity:** $O(1)$ as the operations are performed in-place without allocating any additional data structures proportional to the input size.