# 3532. Path Existence Queries in a Graph I

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Binary Search, Union-Find, Graph Theory |
| Date | 2026-07-09 |
| LeetCode Link | [Path Existence Queries in a Graph I](https://leetcode.com/problems/path-existence-queries-in-a-graph-i/) |

### Intuition

The problem asks whether two nodes $u$ and $v$ belong to the same connected component. The nodes are connected if $|nums[i] - nums[j]| \le maxDiff$. Since the `nums` array is already sorted, this condition simplifies significantly.

If we consider the sorted nodes as a sequence $nums[0], nums[1], \dots, nums[n-1]$, an edge exists between adjacent nodes $i$ and $i+1$ if $nums[i+1] - nums[i] \le maxDiff$. If this condition holds for all $i$ between two indices $j$ and $k$ ($j < k$), it implies that all nodes from $j$ to $k$ form a connected chain. 

Therefore, two nodes $u$ and $v$ are in the same connected component if and only if for every consecutive pair of sorted indices between $\min(u, v)$ and $\max(u, v)$, the difference between their `nums` values is at most `maxDiff`. Since the nodes are provided as indices, and the array `nums` is sorted, we can pre-calculate the connected components using a Disjoint Set Union (DSU) or a simple prefix sum/array approach. Given the sorted constraint, we can create an array `component_id` of length $n$, where all nodes in a contiguous block of "connected" indices share the same ID.

### Complexity Analysis

*   **Time Complexity:** $O(n + q)$, where $n$ is the number of elements in `nums` and $q$ is the number of queries. We iterate through the `nums` array once to identify components ($O(n)$) and then answer each query in constant time ($O(1)$) using the precomputed component IDs.
*   **Space Complexity:** $O(n)$, to store the `component_id` array that maps each index to its connected component.