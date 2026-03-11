# 1009. Complement of Base 10 Integer

Property | Value
--- | ---
Difficulty | Easy
Topics | Bit Manipulation
Date | March 11, 2026
LeetCode Link | [https://leetcode.com/problems/complement-of-base-10-integer/](https://leetcode.com/problems/complement-of-base-10-integer/)

### Intuition
The complement of a binary number is obtained by flipping all its bits (0 to 1, and 1 to 0). Mathematically, flipping a bit is equivalent to performing an XOR operation with 1. To flip all bits in an integer $n$, we need to XOR it with a bitmask of the same length consisting entirely of 1s.

For example, if $n = 5$ (binary `101`), the required bitmask is `111` (decimal 7). 
Performing $5 \oplus 7$ ( `101` ^ `111` ) results in `010` (decimal 2).

The core challenge is constructing a mask that has the same number of bits as $n$. We can achieve this by starting with a mask of 1 and shifting it left while OR-ing it with 1 until it is greater than or equal to $n$. A special edge case is $n = 0$, where the binary representation is "0" and its complement is "1".

### Complexity Analysis
- **Time Complexity:** $O(\log n)$, as the number of iterations required to build the bitmask is proportional to the number of bits in $n$. Since $n < 10^9$, there are at most 30 bits to process.
- **Space Complexity:** $O(1)$, as we only use a single integer variable to store the bitmask.