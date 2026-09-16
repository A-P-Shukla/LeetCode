# 104. Maximum Depth of Binary Tree

| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | Tree, Depth-First Search, Breadth-First Search, Binary Tree |
| Date | May 31, 2026 |
| LeetCode Link | [https://leetcode.com/problems/maximum-depth-of-binary-tree/](https://leetcode.com/problems/maximum-depth-of-binary-tree/) |

## Intuition

The maximum depth of a tree is defined recursively: it is 1 (for the current node) plus the maximum depth of its deeper subtree. This maps directly to a **post-order DFS** — we compute the depths of both subtrees before combining them at the current node.

**Recurrence:**
$$\text{depth}(\text{node}) = \begin{cases} 0 & \text{if node is null} \\ 1 + \max(\text{depth}(\text{left}),\ \text{depth}(\text{right})) & \text{otherwise} \end{cases}$$

**Why post-order:** We need the results from both children before we can compute the current node's depth. This is a bottom-up computation.

**BFS alternative:** A level-order BFS that counts levels also gives the maximum depth in $O(n)$ time and $O(w)$ space (where $w$ is the max width). The recursive DFS is simpler to write and uses $O(h)$ stack space.

## Complexity Analysis

- **Time Complexity:** $O(n)$ — every node is visited exactly once.
- **Space Complexity:** $O(h)$ — the recursion stack depth equals the tree height $h$. Worst case $O(n)$ for a completely skewed tree; $O(\log n)$ for a balanced tree.
