# 2075. Decode the Slanted Ciphertext

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | String, Simulation |
| Date | April 4, 2026 |
| LeetCode Link | [https://leetcode.com/problems/decode-the-slanted-ciphertext/](https://leetcode.com/problems/decode-the-slanted-ciphertext/) |

## Intuition

The problem asks us to reverse a "slanted transposition cipher." To do this, we first need to understand the structure of the encoded matrix. We are given the `encodedText` and the number of `rows`. Since the encoding process fills a matrix row by row to create the `encodedText`, we can calculate the number of columns:
$$\text{cols} = \frac{\text{length of encodedText}}{\text{rows}}$$

The `originalText` was written into this matrix diagonally. Specifically, the first character was at $(0, 0)$, the second at $(1, 1)$, the third at $(2, 2)$, and so on. When a diagonal reached the bottom row or the rightmost column, the next character of the `originalText` started at the top of the next diagonal (e.g., $(0, 1), (1, 2), \dots$).

To decode:
1.  Imagine the `encodedText` laid out in a grid of `rows` $\times$ `cols`.
2.  The character at row $r$ and column $c$ can be accessed at `encodedText[r * cols + c]`.
3.  Iterate through each possible starting column `j` from $0$ to `cols - 1`.
4.  For each starting column, follow the diagonal: move to the next row and next column $(r+1, c+1)$ until you hit the boundary.
5.  Append characters to a result string and finally trim trailing spaces, as the problem specifies the `originalText` had no trailing spaces.

## Complexity Analysis

- **Time Complexity:** $O(N)$, where $N$ is the length of `encodedText`. We iterate through the string to extract characters diagonally and once more (conceptually) to remove trailing spaces.
- **Space Complexity:** $O(N)$ to store the decoded `originalText` before returning it.