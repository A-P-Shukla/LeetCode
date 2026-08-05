# 3310. Remove Methods From Project

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Depth-First Search, Breadth-First Search, Graph, Graph Theory |
| Date | August 5, 2026 |
| LeetCode Link | https://leetcode.com/problems/remove-methods-from-project/ |

## Intuition

The problem models methods and their invocation dependencies as a directed graph where an edge $u \to v$ means method $u$ invokes method $v$.

1. **Identifying Suspicious Methods**: We are given that method `k` is suspicious. Any method reachable directly or indirectly from `k` via directed invocation edges is also considered suspicious. We can find all suspicious methods by performing a standard Breadth-First Search (BFS) or Depth-First Search (DFS) starting from node `k`.
2. **Checking Removal Condition**: A set of suspicious methods can **only** be removed if no non-suspicious method invokes any method within the suspicious set. This means if there exists any directed edge $u \to v$ where method $u$ is **not** suspicious and method $v$ **is** suspicious, the removal condition is violated.
3. **Determining Outcome**:
   - If a non-suspicious method invokes a suspicious method, we cannot remove any methods. The result should contain all original methods from `0` to `n - 1`.
   - If no non-suspicious method invokes a suspicious method, we safely remove all suspicious methods and return only the non-suspicious methods.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n + m)$ where $n$ is the number of methods and $m$ is the total number of invocation pairs (`invocations.length`).
  - Building the adjacency list representation takes $\mathcal{O}(n + m)$ time.
  - The BFS/DFS traversal visits each reachable node and edge at most once, which takes $\mathcal{O}(n + m)$ time.
  - Validating edge dependencies takes $\mathcal{O}(m)$ time.
  - Constructing the final result takes $\mathcal{O}(n)$ time.
- **Space Complexity:** $\mathcal{O}(n + m)$ to store the graph adjacency list, the boolean state array indicating suspicious nodes, and the BFS traversal queue.