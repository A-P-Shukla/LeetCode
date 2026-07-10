# 3534. Path Existence Queries in a Graph II

| Property | Value |
| --- | --- |
| Difficulty | Hard |
| Topics | Array, Sorting, Graph Theory, Connected Components |
| Date | 2026-07-10 |
| LeetCode Link | [Path Existence Queries in a Graph II](https://leetcode.com/problems/path-existence-queries-in-a-graph-ii/) |

### Intuition

The condition `|nums[i] - nums[j]| <= maxDiff` implies that if we sort the nodes based on their `nums` values, the graph becomes a collection of connected components where edges only exist between nodes "close" to each other in sorted order.

Specifically, if we sort the indices based on their corresponding `nums` values, say we get a sorted array of pairs `(val, original_index)`, we can iterate through this list. If the difference between consecutive values is `> maxDiff`, a "gap" is formed, and no path can pass through this gap. This effectively segments our nodes into disjoint groups (components). 

Within each group, nodes are connected. However, this is not a general graph; it's a line-like structure of components. Because an edge exists between any $i$ and $j$ if $|nums[i] - nums[j]| \le maxDiff$, nodes within a component are *fully connected* (clique) if the condition holds transitively. But wait—actually, the condition $|nums[i] - nums[j]| \le maxDiff$ only guarantees edges between values within that range. Because we can move between any $i, j$ such that $|nums[i] - nums[j]| \le maxDiff$, this defines a graph where nodes are connected if they belong to the same "chain" where each consecutive step is $\le maxDiff$.

Crucially, in this problem, the shortest path between any two nodes $u$ and $v$ in the *same* component is 1 if $|nums[u] - nums[v]| \le maxDiff$, and 2 if they are in the same component but $|nums[u] - nums[v]| > maxDiff$ (because they can jump through an intermediate node). If they are in different components, the distance is -1.

1. Sort the nodes by `nums[i]`.
2. Identify contiguous segments where $nums[sorted[i+1]] - nums[sorted[i]] \le maxDiff$. These form connected components.
3. For each query $(u, v)$:
    - If $u == v$, distance is 0.
    - If $u$ and $v$ belong to different components, return -1.
    - If $u$ and $v$ belong to the same component:
        - If $|nums[u] - nums[v]| \le maxDiff$, return 1.
        - Else, return 2.

### Complexity Analysis

- **Time Complexity**: $O(N \log N + Q)$, where $N$ is the number of nodes and $Q$ is the number of queries. Sorting takes $O(N \log N)$, and processing components takes $O(N)$. Each query is answered in $O(1)$ after $O(N)$ preprocessing.
- **Space Complexity**: $O(N)$ to store the components, mapping of nodes, and sorted data.