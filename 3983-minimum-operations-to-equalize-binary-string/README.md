# 3983. Minimum Operations to Equalize Binary String

Property | Value
--- | ---
Difficulty | Hard
Topics | Math, String, Breadth-First Search, Union-Find
Date | February 27, 2025
LeetCode Link | [Minimum Operations to Equalize Binary String](https://leetcode.com/problems/minimum-operations-to-equalize-binary-string/)

### Intuition
The problem asks for the minimum number of operations to make all characters in a binary string equal to '1'. In each operation, we flip exactly $k$ bits. This can be framed as a shortest path problem in a graph where each state represents the current number of zeros in the string.

**State Representation:**
A string of length $n$ can have anywhere from $0$ to $n$ zeros. Let $z$ be the current number of zeros. Our goal is to reach state $z=0$ starting from the initial count of zeros in the input string $s$.

**State Transitions:**
When we perform an operation on a string with $z$ zeros, we must choose $k$ indices to flip. Suppose we flip $x$ zeros and $k-x$ ones:
- The $x$ zeros become ones (count of zeros decreases by $x$).
- The $k-x$ ones become zeros (count of zeros increases by $k-x$).
- The new count of zeros $z' = z - x + (k - x) = z + k - 2x$.

**Constraints on $x$:**
1. $0 \le x \le z$ (we cannot flip more zeros than currently exist).
2. $0 \le k - x \le n - z$ (we cannot flip more ones than currently exist, which implies $x \ge k - n + z$).

Combining these, $x \in [\max(0, k-n+z), \min(z, k)]$.
Substituting these limits into $z' = z + k - 2x$, we find that the reachable states $z'$ lie in the range:
- $L = |z - k|$
- $R = \min(z + k, 2n - z - k)$

Furthermore, $z' = z + k - 2x$ implies that $z'$ always has the same parity as $z + k$. All values within $[L, R]$ with this parity are reachable in one step.

**Efficiency:**
A standard Breadth-First Search (BFS) would visit $O(n)$ states, but since each state can transition to $O(n)$ other states, a naive BFS would be $O(n^2)$. To optimize this, we use a **Union-Find (DSU)** structure to skip already visited states within the parity-aligned range $[L, R]$, bringing the complexity down to nearly $O(n)$.

### Complexity Analysis
- **Time Complexity:** $O(n \cdot \alpha(n))$, where $n$ is the length of the string and $\alpha$ is the inverse Ackermann function. This is because each state (number of zeros) is added to the BFS queue at most once, and the DSU ensures we only process unvisited states.
- **Space Complexity:** $O(n)$ to store the distance array, the BFS queue, and the DSU parent pointers.