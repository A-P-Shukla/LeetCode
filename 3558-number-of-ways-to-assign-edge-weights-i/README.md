# 3558. Number of Ways to Assign Edge Weights I

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Math, Tree, Depth-First Search |
| Date | 2026-06-11 |
| LeetCode Link | [Number of Ways to Assign Edge Weights I](https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i/) |

### Intuition

The problem asks for the number of ways to assign weights (either 1 or 2) to edges along a path from the root (node 1) to any node at the maximum depth, such that the total path cost is odd.

1.  **Identify the Path Length:** First, we need to find the length of the path from the root to the deepest node. Since it is a tree rooted at node 1, we can use Breadth-First Search (BFS) or Depth-First Search (DFS) to determine the depth of every node and identify the length $L$ of the path to the deepest nodes.
2.  **Combinatorial Analysis:** Let $L$ be the number of edges on the path. We have $L$ edges, and each can be assigned weight 1 (odd) or 2 (even).
    *   Let $k$ be the number of edges assigned weight 1.
    *   The total cost is the sum of these weights. Since weight 2 is even, it does not change the parity of the sum. Only the number of 1s (odd weights) matters.
    *   The total cost is odd if and only if the number of edges assigned weight 1 is **odd**.
    *   We need to calculate the number of ways to choose an odd number of edges to have weight 1 from a total of $L$ edges.
3.  **Mathematical Insight:** The number of ways to choose an odd number of items from a set of $L$ items is given by the sum of binomial coefficients: $\sum_{i \text{ is odd}} \binom{L}{i}$.
    *   Using the Binomial Theorem, we know $(1+1)^L = \sum_{i=0}^L \binom{L}{i} = 2^L$.
    *   We also know $(1-1)^L = \sum_{i=0}^L \binom{L}{i}(-1)^i = 0$ (for $L > 0$).
    *   Subtracting these two equations: $2^L - 0 = 2 \times (\sum_{i \text{ is odd}} \binom{L}{i})$.
    *   Therefore, the sum of odd-indexed binomial coefficients is $2^{L-1}$.

### Complexity Analysis

*   **Time Complexity:** $O(n)$, where $n$ is the number of nodes. We perform one DFS/BFS traversal to determine the maximum depth of the tree, which visits each node and edge exactly once.
*   **Space Complexity:** $O(n)$ to store the adjacency list representation of the tree and the recursion stack (or queue) during the traversal.