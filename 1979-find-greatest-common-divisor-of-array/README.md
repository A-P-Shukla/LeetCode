# 1979. Find Greatest Common Divisor of Array

| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | Array, Math, Number Theory |
| Date | 2026-07-18 |
| LeetCode Link | [https://leetcode.com/problems/find-greatest-common-divisor-of-array/](https://leetcode.com/problems/find-greatest-common-divisor-of-array/) |

### Intuition

To solve this problem, we need to extract two specific values from the array: the minimum element and the maximum element. Once these two values are identified, the problem reduces to finding their Greatest Common Divisor (GCD).

1.  **Finding Min and Max**: We can iterate through the array once to track the minimum and maximum values. Since the array length is up to 1000, a single linear pass ($O(N)$) is very efficient.
2.  **Calculating GCD**: The standard algorithm for finding the GCD of two numbers $a$ and $b$ is the **Euclidean Algorithm**. The algorithm is based on the principle that the GCD of two numbers also divides their difference, specifically: $\text{gcd}(a, b) = \text{gcd}(b, a \pmod b)$. This process repeats until the remainder becomes zero, at which point the divisor is the GCD.

### Complexity Analysis

*   **Time Complexity**: $O(N + \log(\min(\text{min\_val}, \text{max\_val})))$.
    *   $O(N)$ to scan the array to find the minimum and maximum elements.
    *   $O(\log(\min(\text{min\_val}, \text{max\_val})))$ for the Euclidean algorithm to compute the GCD.
*   **Space Complexity**: $O(1)$.
    *   We only use a constant amount of extra space for variables to store the minimum, maximum, and the GCD calculation.