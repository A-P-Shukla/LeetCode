# 1674. Minimum Moves to Make Array Complementary

Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Hash Table, Prefix Sum
Date | May 13, 2026
LeetCode Link | [https://leetcode.com/problems/minimum-moves-to-make-array-complementary/](https://leetcode.com/problems/minimum-moves-to-make-array-complementary/)

## Intuition

To make the array complementary, every pair $(a, b)$ at indices $(i, n-1-i)$ must sum to the same target value $S$, where $2 \le S \le 2 \cdot \text{limit}$. For each pair, the number of moves required to reach a specific sum $S$ varies:

1.  **0 Moves**: If $a + b = S$.
2.  **1 Move**: If we can change either $a$ or $b$ to reach $S$. The range of sums achievable with exactly one move is $[\min(a, b) + 1, \max(a, b) + \text{limit}]$, excluding the point where $S = a + b$.
3.  **2 Moves**: If we must change both $a$ and $b$. This happens when $S$ is very small ($2 \le S \le \min(a, b)$) or very large ($\max(a, b) + \text{limit} < S \le 2 \cdot \text{limit}$).

Since we need to find the minimum moves across all pairs for every possible $S \in [2, 2 \cdot \text{limit}]$, we can use a **Difference Array** (or Prefix Sum technique). Instead of calculating moves for every $S$ per pair (which would be $O(N \cdot L)$), we mark the boundaries where the required moves change.

For each pair $(a, b)$:
- Start by assuming **2 moves** for the entire range $[2, 2 \cdot \text{limit}]$.
- Reduce to **1 move** for the range $[\min(a, b) + 1, \max(a, b) + \text{limit}]$.
- Reduce to **0 moves** for the specific point $a + b$.

## Complexity Analysis

- **Time Complexity**: $O(n + \text{limit})$, where $n$ is the length of the array. We iterate through $n/2$ pairs once and then iterate through the difference array of size $2 \cdot \text{limit}$.
- **Space Complexity**: $O(\text{limit})$ to store the difference array.