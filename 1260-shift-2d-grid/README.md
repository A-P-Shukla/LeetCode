# 1260. Shift 2D Grid

| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | Array, Matrix, Simulation |
| Date | 2026-07-20 |
| LeetCode Link | [https://leetcode.com/problems/shift-2d-grid/](https://leetcode.com/problems/shift-2d-grid/) |

### Intuition

The "shifting" operation described is equivalent to a cyclic shift of a 1D array. A 2D grid of size `m x n` has `N = m * n` total elements. If we imagine the grid flattened into a single row of length `N`, shifting the grid `k` times is the same as rotating this flattened array to the right by `k` positions.

Since shifting by `N` positions results in the original grid, we only care about `k % N` shifts. To solve this efficiently, we can map every cell in the original grid to its new position in the resulting grid without performing `k` physical shift operations.

For any cell `(i, j)` in the original grid, its index in a flattened representation is `index = i * n + j`. After shifting by `k`, its new index becomes `(index + k) % N`. We can then convert this new index back into 2D coordinates `(new_i, new_j)` using:
- `new_i = new_index / n`
- `new_j = new_index % n`

This mathematical mapping approach is optimal because it allows us to construct the result grid in a single pass.

### Complexity Analysis

*   **Time Complexity:** $O(m \cdot n)$, where $m$ is the number of rows and $n$ is the number of columns. We visit every element exactly once to calculate its new position.
*   **Space Complexity:** $O(m \cdot n)$ to store the resulting grid. If we consider the output space requirement, this is optimal; otherwise, the auxiliary space used is $O(1)$.