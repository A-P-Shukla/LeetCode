# 3783. Mirror Distance of an Integer

| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | Math |
| Date | April 18, 2026 |
| LeetCode Link | [https://leetcode.com/problems/mirror-distance-of-an-integer/](https://leetcode.com/problems/mirror-distance-of-an-integer/) |

## Intuition

The problem asks us to compute the "Mirror Distance" of an integer $n$, defined as the absolute difference between the number and its reverse.

To solve this, we follow a two-step process:
1. **Calculate the Reverse**: Reversing an integer involves extracting digits from the end and building a new number. For example, if $n = 123$, we extract 3, then 2, then 1, constructing the sequence $3 \to 32 \to 321$. Mathematically, this is done using the modulo operator (`% 10`) to get the last digit and integer division (`/ 10`) to remove it.
2. **Calculate the Absolute Difference**: Once we have $n$ and $reverse(n)$, we simply find $|n - reverse(n)|$.

**Key Consideration**:
While the input $n$ fits within a standard 32-bit integer ($n \le 10^9$), the process of reversing it or calculating the difference is safer when using 64-bit integers (`long long` in C++) to prevent potential overflow during intermediate steps, although for $n \le 10^9$, the maximum reversed value is also within bounds.

## Complexity Analysis

- **Time Complexity**: $O(\log_{10} n)$. The number of operations is proportional to the number of digits in $n$. Since a number $n$ has $\lfloor \log_{10} n \rfloor + 1$ digits, the digit extraction loop runs in logarithmic time relative to the value of $n$.
- **Space Complexity**: $O(1)$. We only store a few variables (`reversedN`, `temp`) regardless of the size of the input.