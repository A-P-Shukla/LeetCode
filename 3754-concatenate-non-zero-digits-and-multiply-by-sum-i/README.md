# 3754. Concatenate Non-Zero Digits and Multiply by Sum I

| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | Math |
| Date | 2026-07-07 |
| LeetCode Link | [https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/](https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/) |

### Intuition

The problem requires a two-step transformation of the input integer $n$:
1. **Extraction and Concatenation**: Filter out all zeros from the decimal representation of $n$ and concatenate the remaining digits in their original order to form a new integer $x$.
2. **Calculation**: Compute the sum of the digits of $x$ and multiply it by $x$.

The most straightforward way to handle this is to treat the integer as a string or a sequence of digits. By iterating through the string representation of $n$, we can easily identify non-zero characters. We build the string version of $x$ by appending these characters. Once we have the string for $x$, converting it back to an integer is trivial. The "sum of digits" of $x$ can be computed by iterating through the characters of this new string, converting each back to an integer, and summing them up. 

Since the constraint is $n \le 10^9$, $x$ will also fit within a standard 64-bit integer, ensuring that the multiplication $x \times \text{sum}$ does not overflow.

### Complexity Analysis

*   **Time Complexity**: $O(D)$, where $D$ is the number of digits in $n$. Converting $n$ to a string takes $O(D)$, iterating through it once takes $O(D)$, and calculating the sum also takes $O(D)$. Given $n \le 10^9$, $D \le 10$, making this extremely efficient.
*   **Space Complexity**: $O(D)$, required to store the string representation of $n$ and the string representation of $x$.