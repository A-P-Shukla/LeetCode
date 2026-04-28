# 2033. Minimum Operations to Make a Uni-Value Grid

| Property | Value |
--- | ---
| Difficulty | Medium |
| Topics | Array, Math, Sorting, Matrix |
| Date | April 28, 2026 |
| LeetCode Link | [https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/](https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/) |

## Intuition

To make all elements in a grid equal by adding or subtracting a fixed value $x$, two conditions must be met:

1.  **Feasibility**: Every element in the grid must be reachable from every other element via steps of $x$. Mathematically, this means all elements must share the same remainder when divided by $x$. If any element $v$ has $v \pmod x \neq \text{reference} \pmod x$, it is impossible to make the grid uni-value, and we return -1.
2.  **Optimality**: We need to find a target value $T$ that minimizes the total number of operations. The number of operations for a single element $v$ is $\frac{|v - T|}{x}$. Therefore, we want to minimize $\sum \frac{|v_i - T|}{x}$. Since $x$ is constant, this is equivalent to minimizing the sum of absolute differences: $\sum |v_i - T|$.

A classic statistical property is that the sum of absolute deviations from a set of numbers is minimized when the target value $T$ is the **median** of those numbers. By sorting the flattened grid and selecting the middle element, we find our optimal target.

## Complexity Analysis

-   **Time Complexity**: $O(N \log N)$, where $N = m \times n$ is the total number of elements in the grid. This is dominated by the sorting step. Note that we could achieve $O(N)$ average time using a selection algorithm (like `std::nth_element` in C++), but $O(N \log N)$ is well within the limits for $N = 10^5$.
-   **Space Complexity**: $O(N)$ to store the flattened version of the grid for sorting.