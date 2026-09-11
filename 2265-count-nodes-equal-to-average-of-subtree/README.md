# 2265. Count Nodes Equal to Average of Subtree

### Metadata Table
Property | Value
--- | ---
Difficulty | Medium
Topics | Tree, Depth-First Search, Binary Tree
Date | September 10, 2026
LeetCode Link | https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/

### Intuition

To determine if a node's value equals the integer average of its subtree, we need two fundamental properties from the subtree rooted at that node:
1. **Sum of values** in the subtree.
2. **Total count of nodes** in the subtree.

Because a node's subtree consists of the node itself plus its left and right subtrees, a **post-order traversal (Depth-First Search)** is ideal. By traversing from the leaf nodes up to the root, we can collect the `(sum, count)` pair from both the left and right child subtrees. 

For any node `curr`:
- `total_sum = left_sum + right_sum + curr.val`
- `total_count = left_count + right_count + 1`
- `average = floor(total_sum / total_count)` (achieved via integer division since node values are non-negative)

If `curr.val == average`, we increment our answer counter and pass `(total_sum, total_count)` up to the parent.

### Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the number of nodes in the binary tree. We visit each node exactly once during the post-order traversal.
- **Space Complexity:** $\mathcal{O}(H)$, where $H$ is the height of the tree. This space is consumed by the recursive function call stack. In the worst case (skewed tree), $H = \mathcal{O}(N)$; in the best case (balanced tree), $H = \mathcal{O}(\log N)$.

---