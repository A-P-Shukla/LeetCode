# 3488. Closest Equal Element Queries

Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Hash Table, Binary Search
Date | April 16, 2026
LeetCode Link | [https://leetcode.com/problems/closest-equal-element-queries/](https://leetcode.com/problems/closest-equal-element-queries/)

## Intuition

The problem asks for the minimum circular distance to the nearest identical element for a given set of indices. Since the array is circular, for any two indices $i$ and $j$ in an array of length $n$, the distance can be calculated in two directions:
1.  **Linear Distance:** $|i - j|$
2.  **Circular Wrap-around Distance:** $n - |i - j|$

The "closest" element with the same value will always be one of the immediate neighbors in the sorted list of indices where that value occurs. For example, if value $v$ exists at indices $[p_0, p_1, p_2, \dots, p_{k-1}]$, the closest occurrence to $p_1$ must be either $p_0$ or $p_2$. For the boundary elements ($p_0$ and $p_{k-1}$), we consider the circular distance between them.

The strategy is to:
1.  Group all indices by the value they contain.
2.  For each group of indices, calculate the distance to the left and right neighbors (including wrap-around).
3.  Pre-calculate the minimum of these two distances for every index.
4.  Answer the queries in $O(1)$ time using the pre-calculated results.

## Complexity Analysis

-   **Time Complexity:** $O(N + Q)$, where $N$ is the size of the input array and $Q$ is the number of queries. We iterate through `nums` once to group indices, once through the groups to calculate distances, and once through the queries.
-   **Space Complexity:** $O(N)$, to store the groups of indices and the pre-calculated minimum distances for each index.