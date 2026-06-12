# 3559. Number of Ways to Assign Edge Weights II

| Property | Value |
| --- | --- |
| Difficulty | Hard |
| Topics | Array, Math, Dynamic Programming, Bit Manipulation, Tree, Depth-First Search |
| Date | 2026-06-12 |
| LeetCode Link | [Number of Ways to Assign Edge Weights II](https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-ii/) |

### Intuition

The problem asks for the number of ways to assign weights $\{1, 2\}$ to edges on a path between two nodes such that the total sum is odd. Let $k$ be the number of edges on the path between $u$ and $v$. If $k=0$ (i.e., $u=v$), the sum is $0$, which is even, so the answer is $0$.

If $k > 0$, let $x$ be the number of edges assigned weight $1$, and $(k-x)$ be the number of edges assigned weight $2$. The total cost is:
$\text{Cost} = 1 \cdot x + 2 \cdot (k - x) = x + 2k - 2x = 2k - x$

For the cost to be odd, $2k - x$ must be odd. Since $2k$ is always even, $x$ must be odd.
We need to choose an odd number of edges to have weight $1$, out of a total of $k$ edges. The number of ways to choose $x$ edges is $\binom{k}{x}$. Thus, the total number of ways is the sum of $\binom{k}{x}$ for all odd $x \le k$:
$\sum_{x \in \{1, 3, 5, \dots\}, x \le k} \binom{k}{x}$

Using the binomial theorem, we know:
$(1 + 1)^k = \sum_{i=0}^k \binom{k}{i} = 2^k$
$(1 - 1)^k = \sum_{i=0}^k \binom{k}{i} (-1)^i = 0$
Subtracting the second from the first:
$2^k - 0 = \sum_{i=0}^k \binom{k}{i} (1 - (-1)^i) = 2 \cdot \sum_{i \text{ is odd}} \binom{k}{i}$
So, $\sum_{i \text{ is odd}} \binom{k}{i} = 2^{k-1}$.

Therefore, if the path length $k > 0$, the answer is always $2^{k-1} \pmod{10^9 + 7}$. We simply need to find the distance between nodes $u$ and $v$ in the tree. This can be done using Lowest Common Ancestor (LCA) with binary lifting or depth information.

### Complexity Analysis

- **Time Complexity**: $O(N \log N + Q \log N)$, where $N$ is the number of nodes and $Q$ is the number of queries. $O(N \log N)$ is required to build the LCA table using binary lifting, and $O(\log N)$ to answer each query.
- **Space Complexity**: $O(N \log N)$ to store the binary lifting table (upward ancestors).