# 102. Binary Tree Level Order Traversal

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Tree, Breadth-First Search, Binary Tree |
| Date | May 31, 2026 |
| LeetCode Link | [https://leetcode.com/problems/binary-tree-level-order-traversal/](https://leetcode.com/problems/binary-tree-level-order-traversal/) |

## Intuition

Level-order traversal visits all nodes at depth $d$ before any node at depth $d+1$. This is exactly what **Breadth-First Search (BFS)** with a queue achieves.

**The level-separation trick:**
A standard BFS queue mixes nodes from different levels. To separate them, we snapshot the queue size at the start of each iteration — this size equals the number of nodes on the current level. We process exactly that many nodes, collecting their values into a level list, and enqueue their children (which form the next level). After processing, we append the level list to the result.

**Why this works:** At the start of each outer iteration, the queue contains exactly all nodes of the current level and nothing else. Processing `levelSize` nodes dequeues the entire current level and enqueues the entire next level atomically.

**Alternative:** A recursive DFS approach (as in the original standalone file) also works by passing the depth as a parameter and expanding the result vector when a new depth is first encountered. BFS is more natural and avoids recursion stack overhead.

## Complexity Analysis

- **Time Complexity:** $O(n)$ — each node is enqueued and dequeued exactly once.
- **Space Complexity:** $O(w)$ — where $w$ is the maximum width of the tree (maximum nodes on any single level). For a complete binary tree, $w = \lceil n/2 \rceil$, so worst case is $O(n)$.
