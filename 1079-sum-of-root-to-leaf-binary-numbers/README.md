# 1079. Sum of Root To Leaf Binary Numbers

| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | Tree, Depth-First Search, Binary Tree |
| Date | February 24, 2026 |
| LeetCode Link | [https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/](https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/) |

## Intuition

The problem asks us to traverse every path from the root to the leaves, constructing a binary number along the way and summing these values. 

In a binary representation, moving down one level in the tree (from parent to child) is equivalent to a bitwise left shift. For example, if we have the path `1 -> 0`, the value at the first node is $1$. When we move to the next node $0$, the previous value is shifted left (multiplied by 2) and the new node's value is added: $(1 \times 2) + 0 = 2$ (which is $10_2$).

A **Depth-First Search (DFS)** approach is ideal here because it naturally explores a path from the root to a leaf before backtracking. We can pass the "running sum" down the recursion stack. Once we reach a leaf node (a node with no children), we return the accumulated value. If a node is not a leaf, we recursively calculate the sum of its left and right subtrees.

## Complexity Analysis

- **Time Complexity:** $O(N)$, where $N$ is the number of nodes in the binary tree. We visit each node exactly once during the DFS traversal.
- **Space Complexity:** $O(H)$, where $H$ is the height of the tree. This space is consumed by the implicit recursion stack. In the worst case (a skewed tree), $H = N$; in the best case (a balanced tree), $H = \log N$.