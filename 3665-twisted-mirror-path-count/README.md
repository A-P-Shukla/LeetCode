# 3665. Twisted Mirror Path Count
| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Dynamic Programming, Matrix |
| Date | 2026-10-31 |
| LeetCode Link | https://leetcode.com/problems/twisted-mirror-path-count/ |

## Intuition & Approach
The robot may only **intend** to move right or down.  
When the intended neighbor cell contains a mirror (`1`), the robot does **not** enter that cell – it is reflected and continues from the mirror cell in the *other* direction.  
If the next cell after reflection is also a mirror, the process repeats until a non‑mirror cell is reached or the robot leaves the board.  

Because each reflection moves strictly **right** or **down**, coordinates are monotonic; cycles are impossible and a chain of reflections is at most `m + n` long.

The problem therefore reduces to two sub‑tasks:

1. **Resolve the effect of a single intended step**  
   For every board position `(i, j)` and for both intended directions (`right`, `down`) compute the *landing cell* after processing all required reflections, or mark the step as *invalid* (out of bounds).  
   This can be done with a memoised recursion:
   * attempt the neighbor cell;
   * if it is empty → landing cell is that neighbor;
   * if it is a mirror → recurse from the mirror cell with the opposite direction.

   Since each `(i, j, dir)` is evaluated once, the total work for this pre‑computation is `O(m·n)`.

2. **Count paths using dynamic programming**  
   Let `dp[i][j]` be the number of ways to reach cell `(i, j)`.  
   Starting with `dp[0][0] = 1`, iterate cells in row‑major order (which respects the monotonic order of moves).  
   For each cell propagate its count to the two possible landing cells obtained from step 1:
   ```
   (ni, nj) = resolve(i, j, RIGHT)
   dp[ni][nj] += dp[i][j]
   (ni, nj) = resolve(i, j, DOWN)
   dp[ni][nj] += dp[i][j]
   ```
   All additions are performed modulo `10⁹+7`.  
   The answer is `dp[m‑1][n‑1]`.

The DP traversal never revisits a cell that could affect earlier cells because every propagation moves to a strictly larger row‑plus‑col index.

## Complexity Analysis
*Time* –  
Resolving each of the `2·m·n` `(cell, direction)` pairs once: `O(m·n)`.  
DP propagation scans the board once: `O(m·n)`.  
Overall: **`O(m·n)`**.

*Space* –  
`dp` array (`m·n` integers) and a memo table storing two landing cells per board position (`2·m·n` pairs).  
Overall: **`O(m·n)`** auxiliary space (besides the input grid).