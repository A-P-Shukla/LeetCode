# 1306. Jump Game III

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Depth-First Search, Breadth-First Search |
| Date | May 17, 2026 |
| LeetCode Link | [Jump Game III](https://leetcode.com/problems/jump-game-iii/) |

## Intuition

The problem can be modeled as a graph traversal problem where each index in the array represents a node. From any given index `i`, there are at most two directed edges to other nodes: `i + arr[i]` and `i - arr[i]`. The goal is to determine if there exists a path from the `start` node to any node whose value is `0`.

Since we need to explore reachable nodes, both **Breadth-First Search (BFS)** and **Depth-First Search (DFS)** are suitable candidates. 

1.  **State Space**: Every index is a state.
2.  **Transitions**: From index `i`, we can move to `left = i - arr[i]` or `right = i + arr[i]`, provided these indices are within the array bounds `[0, arr.length - 1]`.
3.  **Cycle Prevention**: To prevent infinite loops (jumping back and forth between the same indices), we must keep track of visited indices. We can do this using a separate boolean array/set or by modifying the input array in-place (e.g., flipping the sign of the value) if the problem constraints allow.

## Complexity Analysis

- **Time Complexity**: $O(N)$, where $N$ is the number of elements in the array. In the worst case, we visit every index at most once.
- **Space Complexity**: $O(N)$. In the case of DFS, the recursion stack can go up to $N$ deep. In the case of BFS, the queue can store up to $N$ indices.