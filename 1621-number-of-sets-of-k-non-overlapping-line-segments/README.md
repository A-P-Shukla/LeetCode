# 1621. Number of Sets of K Non-overlapping Line Segments

### Metadata
Property | Value
--- | ---
Difficulty | Medium
Topics | Math, Dynamic Programming, Combinatorics
Date | September 16, 2026
LeetCode Link | [1621. Number of Sets of K Non-overlapping Line Segments](https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/)

---

## Intuition

The problem asks for the number of ways to place $k$ non-overlapping line segments onto $n$ integral points ($0$ to $n-1$), where segments are allowed to share endpoints. 

While this problem can be framed as a Dynamic Programming problem, a mathematical formulation using **Combinatorics (Stars and Bars)** yields a much simpler $O(k)$ solution.

### 1. Mathematical Reduction

The distance between point $0$ and point $n-1$ is $n-1$ units.
Let:
- $d_1, d_2, \dots, d_k$ be the lengths of the $k$ segments. Each segment must cover at least two points, so $d_i \ge 1$ for all $i$.
- $g_0$ be the gap before the first segment ($g_0 \ge 0$).
- $g_1, g_2, \dots, g_{k-1}$ be the gaps between consecutive segments ($g_i \ge 0$).
- $g_k$ be the gap after the last segment ($g_k \ge 0$).

Since the total distance spanned by all segments and gaps must equal $n - 1$:
$$g_0 + d_1 + g_1 + d_2 + \dots + d_k + g_k = n - 1$$

Substitute $d_i = d_i' + 1$ (where $d_i' \ge 0$):
$$g_0 + (d_1' + 1) + g_1 + (d_2' + 1) + \dots + (d_k' + 1) + g_k = n - 1$$
$$g_0 + d_1' + g_1 + d_2' + \dots + d_k' + g_k = n - 1 - k$$

Now we have $2k + 1$ non-negative variables ($g_0, \dots, g_k$ and $d_1', \dots, d_k'$) that sum to $n - 1 - k$.

### 2. Stars and Bars Formula

Using the Stars and Bars theorem, the number of non-negative integer solutions to $x_1 + x_2 + \dots + x_m = S$ is given by $\binom{S + m - 1}{m - 1}$.

Here:
- $S = n - 1 - k$
- $m = 2k + 1$
- $m - 1 = 2k$
- $S + m - 1 = (n - 1 - k) + 2k = n + k - 1$

Thus, the answer is simply:
$$\binom{n + k - 1}{2k} \pmod{10^9 + 7}$$

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(k \log(\text{MOD}))$ using modular inverse via Fermat's Little Theorem, or $\mathcal{O}(k)$ if precomputing inverses.
- **Space Complexity:** $\mathcal{O}(1)$ as only a few variables are used to compute the combination formula.

---