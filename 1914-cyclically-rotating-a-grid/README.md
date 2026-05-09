# 1914. Cyclically Rotating a Grid

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Matrix, Simulation |
| Date | May 9, 2026 |
| LeetCode Link | [https://leetcode.com/problems/cyclically-rotating-a-grid/](https://leetcode.com/problems/cyclically-rotating-a-grid/) |

## Intuition

The problem asks us to rotate concentric layers of a matrix counter-clockwise $k$ times. Since $k$ can be as large as $10^9$, we must optimize. The key insight is that rotating a layer of size $L$ by $k$ positions is equivalent to rotating it by $k \pmod L$ positions.

To solve this efficiently:
1.  **Decompose the Matrix**: Treat the matrix as a collection of nested rectangular rings (layers). Since both $m$ and $n$ are even, the number of layers is $\min(m, n) / 2$.
2.  **Extract Layers**: For each layer, traverse its perimeter in a fixed order (e.g., top row $\to$ right column $\to$ bottom row $\to$ left column) and store the elements in a 1D array.
3.  **Perform Rotation**: Calculate the effective rotation $k_{eff} = k \pmod L$. Rotating counter-clockwise means shifting elements "forward" in our traversal path. In a 1D array representation, the element at index $i$ after rotation was originally at index $(i + k_{eff}) \pmod L$.
4.  **Re-insert Elements**: Place the rotated elements back into the original grid structure using the same traversal path.

## Complexity Analysis

- **Time Complexity**: $O(M \times N)$, where $M$ is the number of rows and $N$ is the number of columns. We visit every cell in the grid exactly twice: once to extract the layers and once to write the rotated values back.
- **Space Complexity**: $O(M + N)$ for the temporary storage of a single layer's elements. While we process all cells, we only need to store one layer at a time in a 1D vector/list.