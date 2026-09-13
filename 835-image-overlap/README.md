# 835. Image Overlap

### Metadata Table
Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Matrix
Date | September 13, 2026
LeetCode Link | [Image Overlap - LeetCode](https://leetcode.com/problems/image-overlap/)

## Intuition

The problem asks for the maximum number of overlapping `1`s between two $n \times n$ binary matrices, `img1` and `img2`, when `img1` is translated in any direction.

Instead of testing all possible shift vectors $(dr, dc)$ and iterating through the matrices to count overlapping `1`s (which takes $O(n^4)$ operations), we can invert our perspective:

1. **Focus on active pixels**: We only care about the coordinates where `1`s exist in both images.
2. **Translate to relative offsets**: For every `1` at position $(r_1, c_1)$ in `img1` and every `1` at position $(r_2, c_2)$ in `img2`, the shift required to align $(r_1, c_1)$ onto $(r_2, c_2)$ is precisely $(dr, dc) = (r_2 - r_1, c_2 - c_1)$.
3. **Count shift frequencies**: If multiple pairs of `1`s share the exact same shift vector $(dr, dc)$, it means applying that translation will align all those `1`s simultaneously.
4. **Identify the maximum**: The shift vector with the highest frequency represents the optimal translation, and its count is the maximum possible overlap.

This coordinate-filtering approach is especially fast when the matrices contain few `1`s, while remaining well within time limits even in the worst-case dense matrices ($n \le 30$).

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(M_1 \cdot M_2 + n^2)$, where $n$ is the dimension of the matrix, $M_1$ is the number of `1`s in `img1`, and $M_2$ is the number of `1`s in `img2`. In the worst case where all entries are `1`s ($M_1 = M_2 = n^2$), the complexity is $\mathcal{O}(n^4)$. Given $n \le 30$, $n^4 = 810,000$, which comfortably executes within milliseconds.
- **Space Complexity:** $\mathcal{O}(M_1 + M_2 + \text{unique shifts})$, required to store the list of `1` coordinates and the frequency hash map for shift vectors. In the worst case, this uses $\mathcal{O}(n^2)$ extra space.