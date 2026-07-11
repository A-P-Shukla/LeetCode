# 2685. Count the Number of Complete Components

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Depth-First Search, Breadth-First Search, Union-Find, Graph Theory |
| Date | 2026-07-11 |
| LeetCode Link | [https://leetcode.com/problems/count-the-number-of-complete-components/](https://leetcode.com/problems/count-the-number-of-complete-components/) |

### Intuition

To solve this problem, we need to identify each connected component in the graph and verify if each component is "complete." A component is complete if and only if every pair of distinct vertices within that component is connected by an edge.

For a connected component with $V$ vertices, a complete graph (clique) must have exactly $\frac{V(V - 1)}{2}$ edges. 

The approach is:
1. **Represent the Graph:** Use an adjacency list to store the graph structure.
2. **Identify Components:** Perform a traversal (DFS or BFS) to find all vertices belonging to each connected component.
3. **Verify Completeness:** For each component identified:
   - Count the number of vertices ($V_{comp}$).
   - Count the number of edges ($E_{comp}$) within the component. Note that summing the degrees of all vertices in the component and dividing by 2 gives $E_{comp}$.
   - Check if $E_{comp} == \frac{V_{comp}(V_{comp} - 1)}{2}$.
4. **Aggregate:** Maintain a counter to keep track of how many components satisfy this condition.

This approach is efficient because we visit each node and edge exactly once during the traversal.

### Complexity Analysis

*   **Time Complexity:** $O(V + E)$, where $V$ is the number of vertices ($n$) and $E$ is the number of edges. We visit each vertex and each edge during the traversal to identify components and calculate their metrics.
*   **Space Complexity:** $O(V + E)$ to store the adjacency list and the `visited` array (or a set) to keep track of processed vertices.