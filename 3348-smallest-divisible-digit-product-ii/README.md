# 3343. Count Number of Balanced Permutations / Smallest Zero-Free Number

### Metadata
Property | Value
--- | ---
Difficulty | Hard
Topics | String, Dynamic Programming, Greedy, Math, Backtracking
Date | August 7, 2026
LeetCode Link | [Smallest Zero-Free Number With Product Divisible by T](https://leetcode.com/problems/smallest-zero-free-number-with-product-divisible-by-t/)

---

### Intuition

We want to find the smallest zero-free string $S \ge \text{num}$ whose digit product is divisible by $t$.

1. **Prime Factor Analysis of $t$**:
   Since digits in a zero-free number range from $1$ to $9$, the only prime factors a digit product can possess are $2, 3, 5,$ and $7$. If $t$ contains any other prime factor (e.g., $11, 13, 17$), no product of digits can ever be divisible by $t$. In such cases, we immediately return `"-1"`.
   
   If $t$ can be factored into $2^a \cdot 3^b \cdot 5^c \cdot 7^d$, we extract the required prime factor counts $(a, b, c, d)$. Note that since $t \le 10^{14}$, $a \le 47$ and $b \le 30$.

2. **Digit Factor Distribution (Dynamic Programming)**:
   - Factors of $5$ and $7$ can **only** be provided by digits '5' and '7' respectively. Thus, we must include at least $c$ copies of '5' and $d$ copies of '7'.
   - Factors of $2$ and $3$ can be contributed by digits $\{2, 3, 4, 6, 8, 9\}$. To make the overall number as small as possible, we want to minimize the number of non-'1' digits (which maximizes leading '1's). If two multiset choices have the same number of non-'1' digits, we choose the one that is lexicographically smaller when sorted.
   - We can precompute a small 2D DP table `dp[u][v]` representing the optimal multiset of digits from $\{2, 3, 4, 6, 8, 9\}$ to supply $u$ factors of $2$ and $v$ factors of $3$, for $0 \le u \le 47$ and $0 \le v \le 30$.

3. **Constructing the Smallest Valid Number**:
   - **Same Length ($|num|$)**: We iterate from the rightmost possible matching prefix index $i$ down to $0$. Index $i$ can match $num[0 \dots i-1]$ if $num[0 \dots i-1]$ contains no '0's. At position $i$, we test digits $d_{pos} \in [num[i] + 1, 9]$ (or $[1, 9]$ if $num[i] == '0'$). For each choice, we determine the remaining factor requirements and look up the optimal non-'1' multiset $M$. If $|M| \le \text{remaining\_length}$, we pad with leading '1's and sorted $M$. The very first valid string found in this search order is guaranteed to be the smallest valid number of length $|num|$.
   - **Larger Length ($> |num|$)**: If no candidate of length $|num|$ exists, we pick the optimal multiset $M$ for the full requirements of $t$. The minimum valid length is $L = \max(|num| + 1, |M|)$. The answer consists of $(L - |M|)$ copies of '1' followed by sorted $M$.

---

### Complexity Analysis

- **Time Complexity**:
  - **DP Precomputation**: The state space is $48 \times 31 \approx 1488$ states, each taking $O(1)$ transitions. This takes $O(1)$ time (less than 1 ms).
  - **Prefix Search**: We loop over string length $N = |num|$, testing at most 9 digits per position. Inside the loop, factor calculations and string operations take $O(1)$ time (since non-'1' multiset length $\le 70$).
  - Total Time Complexity: $\mathcal{O}(N)$, where $N = |num|$.

- **Space Complexity**:
  - The DP table requires $O(48 \times 31) = O(1)$ space.
  - Prefix factor arrays and output string construction require $\mathcal{O}(N)$ auxiliary space.
  - Total Space Complexity: $\mathcal{O}(N)$.

---