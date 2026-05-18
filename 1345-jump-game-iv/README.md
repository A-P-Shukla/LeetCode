# 1345. Jump Game IV

| Property | Value |
| --- | --- |
| Difficulty | Hard |
| Topics | Array, Hash Table, Breadth-First Search |
| Date | May 18, 2026 |
| LeetCode Link | [https://leetcode.com/problems/jump-game-iv/](https://leetcode.com/problems/jump-game-iv/) |

## Intuition

The problem asks for the minimum number of steps to reach the end of an array, which is a classic shortest-path problem on an unweighted graph. In such scenarios, **Breadth-First Search (BFS)** is the most efficient approach as it explores all nodes at the current distance before moving to nodes further away, guaranteed to find the shortest path first.

The graph is defined as follows:
1. Each index $i$ is a node.
2. Edges exist between $i$ and $i+1$, and between $i$ and $i-1$.
3. Edges exist between any two indices $i$ and $j$ if `arr[i] == arr[j]`.

**Key Challenge & Optimization:**
A naive BFS would iterate through all indices with the same value every time it encounters that value. If the array contains many identical values (e.g., `[7, 7, 7, ..., 7]`), the complexity could spiral into $O(N^2)$. 

To achieve $O(N)$ performance:
- We use a Hash Map to pre-compute the indices for every unique value.
- **Crucial Step:** Once we have explored all jump options for a specific value $v$, we remove the list of indices for $v$ from our map. This prevents the BFS from redundantly checking the same set of indices multiple times, ensuring each edge in the graph is traversed at most once.

## Complexity Analysis

- **Time Complexity:** $O(N)$, where $N$ is the length of the array. We visit each index at most once and traverse each edge (neighbor or value-jump) at most once due to the map-clearing optimization.
- **Space Complexity:** $O(N)$ to store the hash map of value indices, the BFS queue, and the visited array.