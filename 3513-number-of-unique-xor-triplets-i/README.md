# 3513. Number of Unique XOR Triplets I

Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Math, Bit Manipulation
Date | July 23, 2026
LeetCode Link | [Number of Unique XOR Triplets I](https://leetcode.com/problems/number-of-unique-xor-triplets-i/)

## Intuition

The problem asks for the number of unique XOR values formed by picking any three numbers $a, b, c$ with replacement from the array `nums`. Because `nums` is a permutation of integers from $1$ to $n$, the specific order and elements of `nums` are fixed—it simply contains the set of integers $\{1, 2, \dots, n\}$. Furthermore, since XOR is commutative and associative, choosing three elements with indices $i \le j \le k$ is equivalent to choosing any three elements from $\{1, 2, \dots, n\}$ with replacement.

Let $B$ be the bit length of $n$ (i.e., $B = \lfloor \log_2 n \rfloor + 1$).

1. **Upper Bound**: Since all numbers in $\{1, \dots, n\}$ are strictly less than $2^B$, any XOR combination $a \oplus b \oplus c$ must also be strictly less than $2^B$. Thus, at most $2^B$ distinct values (from $0$ to $2^B - 1$) can ever be formed.
2. **Base Cases**:
   - For $n = 1$, the set is $\{1\}$. $1 \oplus 1 \oplus 1 = 1$, yielding **1** unique value.
   - For $n = 2$, the set is $\{1, 2\}$. The possible XOR values are $1 \oplus 1 \oplus 1 = 1$, $1 \oplus 1 \oplus 2 = 2$, $1 \oplus 2 \oplus 2 = 1$, $2 \oplus 2 \oplus 2 = 2$, yielding **2** unique values $\{1, 2\}$.
3. **General Case ($n \ge 3$)**:
   - **Forming values in $[0, 2^{B-1} - 1]$**:
     - $0$ can be formed by $1 \oplus 2 \oplus 3 = 0$ (since $1, 2, 3 \le n$).
     - Any $x \in [1, 2^{B-1}-1]$ can be formed by $x \oplus 1 \oplus 1 = x$.
   - **Forming values in $[2^{B-1}, 2^B - 1]$**:
     - Let $M = 2^{B-1}$. For any target $M + k$ where $k \in [0, M - 1]$, we can pick $a = M$ and two elements $b, c \in [1, M - 1]$ such that $b \oplus c = k$.
     - When $k = 0$, pick $b = 1, c = 1 \implies M \oplus 1 \oplus 1 = M$.
     - When $k > 0$, we can easily find $b, c \in [1, M - 1]$ such that $b \oplus c = k$.
   - Thus, ALL integers from $0$ to $2^B - 1$ can be formed, giving a total of **$2^B$** unique values.

Hence, for $n \ge 3$, the answer is simply $2^{\text{bit\_length}(n)} = 1 \ll \text{bit\_length}(n)$.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(1)$ — Determining $n$ and calculating its bit length takes constant time.
- **Space Complexity:** $\mathcal{O}(1)$ — No additional data structures or memory are allocated.