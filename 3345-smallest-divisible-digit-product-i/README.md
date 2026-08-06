# 3345. Smallest Divisible Digit Product I

### Metadata Table
Property | Value
--- | ---
Difficulty | Easy
Topics | Math, Enumeration
Date | 2026-08-06
LeetCode Link | https://leetcode.com/problems/smallest-divisible-digit-product-i/

### Intuition

The problem asks us to find the smallest integer $x \ge n$ such that the product of the digits of $x$ is divisible by $t$.

Given the constraints ($1 \le n \le 100$ and $1 \le t \le 10$), a direct simulation/enumeration approach is optimal and fully sufficient:
1. Start checking numbers $x$ beginning from $n$.
2. For each number $x$, compute the product of its digits.
3. Check if this product is divisible by $t$ (`product % t == 0`).
4. The first number $x$ that satisfies this condition is our answer.

Notice that any multiple of 10 (e.g., 10, 20, 30, ..., 100) contains the digit `0`, which makes the digit product equal to `0`. Since `0 % t == 0` for any $t \ge 1$, we are guaranteed to find a valid answer within at most $10$ steps from $n$.

### Complexity Analysis

- **Time Complexity:** $\mathcal{O}(1)$. In the worst-case scenario, we iterate at most $10$ numbers before encountering a number with a digit `0` (whose product is $0$, divisible by any $t$). For each number up to $100$, computing the product takes at most $3$ digit operations ($\log_{10}(n)$). Thus, the runtime is bounded by a small constant.
- **Space Complexity:** $\mathcal{O}(1)$. The algorithm uses only a few integer variables for loop counters and digit arithmetic, consuming constant memory.