# 3700. Number of ZigZag Arrays II

| Property | Value |
| --- | --- |
| Difficulty | Hard |
| Topics | Math, Dynamic Programming |
| Date | 2026-06-24 |
| LeetCode Link | [https://leetcode.com/problems/number-of-zigzag-arrays-ii/](https://leetcode.com/problems/number-of-zigzag-arrays-ii/) |

### Intuition

A ZigZag array requires that for any three consecutive elements $a, b, c$, we cannot have $a < b < c$ or $a > b > c$. This means every element $b$ must be a "peak" ($a < b$ and $c < b$) or a "valley" ($a > b$ and $c > b$). Consequently, the array must strictly alternate between increasing and decreasing steps.

Let $K = r - l + 1$ be the number of available integers.
Given $n$ can be up to $10^9$ and $K$ is small ($K \le 75$), this problem calls for Matrix Exponentiation.

1. **State Definition**: We need to know the value of the last element $x$ and whether the last step was increasing or decreasing to determine the next valid moves.
   - State: `(value, direction)` where `value` $\in [0, K-1]$ and `direction` $\in \{0 (down), 1 (up)\}$.
   - Total states: $2K$.

2. **Transitions**:
   - If the last step was "Up" ($a < b$), the next step must be "Down" ($b > c$).
   - If the last step was "Down" ($a > b$), the next step must be "Up" ($b < c$).
   - Matrix $M$ of size $2K \times 2K$ represents transitions. $M[i][j]$ is 1 if moving from state $i$ to $j$ is valid, 0 otherwise.

3. **Computation**:
   - Start vector $V_0$: For a sequence of length 2, all $K(K-1)$ pairs are valid. We initialize our DP based on length 2 arrays and use matrix exponentiation to compute the state vector for length $n$.

### Complexity Analysis

*   **Time Complexity**: $O((2K)^3 \log n)$, where $K = r-l+1$. Given $K \le 75$, $2K \le 150$, $150^3 \approx 3.3 \times 10^6$, which easily passes within the time limit.
*   **Space Complexity**: $O((2K)^2)$ to store the transition matrix.