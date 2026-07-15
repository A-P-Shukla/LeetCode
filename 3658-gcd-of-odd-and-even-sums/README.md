# 3658. GCD of Odd and Even Sums

| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | Math, Number Theory |
| Date | 2026-07-15 |
| LeetCode Link | [https://leetcode.com/problems/gcd-of-odd-and-even-sums/](https://leetcode.com/problems/gcd-of-odd-and-even-sums/) |

### Intuition

To solve this problem, we first determine the mathematical formulas for the sum of the first $n$ odd and even numbers:

1.  **Sum of the first $n$ odd numbers ($sumOdd$):** 
    The sequence is $1, 3, 5, \dots, (2n-1)$. This is an arithmetic progression. The sum is given by:
    $sumOdd = \frac{n}{2}(1 + (2n-1)) = \frac{n}{2}(2n) = n^2$.

2.  **Sum of the first $n$ even numbers ($sumEven$):**
    The sequence is $2, 4, 6, \dots, 2n$. This is an arithmetic progression. The sum is given by:
    $sumEven = \frac{n}{2}(2 + 2n) = n(1 + n) = n^2 + n$.

3.  **Calculating the GCD:**
    We need to compute $\gcd(n^2, n^2 + n)$.
    Using the Euclidean property $\gcd(a, b) = \gcd(a, b - a)$, we can simplify:
    $\gcd(n^2, n^2 + n) = \gcd(n^2, (n^2 + n) - n^2) = \gcd(n^2, n)$.
    Since $n$ divides $n^2$, the GCD is simply $n$.

Therefore, the problem reduces to returning the input $n$ itself.

### Complexity Analysis

*   **Time Complexity:** $O(1)$. Since we have derived a direct mathematical formula, the result is computed in constant time regardless of the size of $n$.
*   **Space Complexity:** $O(1)$. We do not use any additional data structures that scale with input size.