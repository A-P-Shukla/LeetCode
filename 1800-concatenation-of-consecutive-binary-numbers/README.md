# 1680. Concatenation of Consecutive Binary Numbers

Property | Value
--- | ---
Difficulty | Medium
Topics | Math, Bit Manipulation, Simulation
Date | February 28, 2026
LeetCode Link | [Concatenation of Consecutive Binary Numbers](https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/)

### Intuition

The problem asks us to concatenate the binary representations of integers from $1$ to $n$ and find the resulting decimal value modulo $10^9 + 7$. 

A key observation is that concatenating a binary string is mathematically equivalent to shifting the existing number to the left and adding the new number. Specifically, if we have a current value `res` and we want to append the binary representation of the next integer `i`, the transformation is:
$$res = (res \times 2^{\text{length}(i)} + i) \pmod{MOD}$$
where $\text{length}(i)$ is the number of bits in the binary representation of $i$.

To implement this efficiently:
1. **Bit Length Calculation**: Instead of recalculating the number of bits for every integer using log functions, we can notice that the bit length increases by 1 every time $i$ is a power of 2 (e.g., 1, 2, 4, 8, ...). A simple bitwise check `(i & (i - 1)) == 0` allows us to detect these transitions in $O(1)$.
2. **Modulo Arithmetic**: Since the numbers grow extremely large, we must apply the modulo operator at each step. Using a `long long` in C++ ensures that the intermediate shift operation `res << length` does not overflow before the modulo is applied.

### Complexity Analysis

*   **Time Complexity**: $O(n)$, where $n$ is the input integer. We iterate through each number from $1$ to $n$ exactly once, performing constant-time bitwise operations and arithmetic.
*   **Space Complexity**: $O(1)$, as we only store a few primitive variables (`res`, `length`, `MOD`) regardless of the size of $n$.