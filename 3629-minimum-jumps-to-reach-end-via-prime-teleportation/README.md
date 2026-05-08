# 3629. Minimum Jumps to Reach End via Prime Teleportation

| Property | Value |
|---|---|
| **Difficulty** | Medium |
| **Topics** | Array, Hash Table, Math, Breadth-First Search, Number Theory |
| **Date** | May 8, 2026 |
| **LeetCode Link** | [Minimum Jumps to Reach End via Prime Teleportation](https://leetcode.com/problems/minimum-jumps-to-reach-end-via-prime-teleportation/) |

---

## Intuition

The problem asks for the minimum number of jumps to traverse from index $0$ to $n-1$. Since all jumps have a uniform cost of 1, this is a classic shortest path problem on an unweighted graph, making **Breadth-First Search (BFS)** the ideal approach.

The graph consists of $n$ nodes (indices $0$ to $n-1$). There are two types of edges:

1. **Adjacent Edges:**  
   $i \leftrightarrow i+1$ and $i \leftrightarrow i-1$

2. **Teleportation Edges:**  
   If $nums[i]$ is prime $p$, there are directed edges from $i$ to every $j$ where $nums[j]$ is a multiple of $p$.

The challenge lies in the teleportation edges. A naive BFS would check every index $j$ for divisibility by $p$ for every prime encountered, leading to $O(N^2)$ complexity. To optimize, we use number theory:

- Precompute the **Smallest Prime Factor (SPF)** for all numbers up to $10^6$ using a sieve. This allows for $O(\log(\text{max\_val}))$ prime factorization.
- Construct a mapping from each prime $p$ to a list of indices $j$ such that $p$ is a factor of $nums[j]$.
- During BFS, when we land on an index $i$ where $nums[i]$ is prime, we "activate" that prime. We traverse its associated list of indices and add any unvisited indices to the queue.
- To ensure efficiency, we track which primes have already been "activated" so we don't process the same prime's index list multiple times.

---

## Complexity Analysis

- **Time Complexity:**  
  $O(M \log \log M + N \log M)$, where $M$ is the maximum value in `nums` ($10^6$) and $N$ is the length of the array ($10^5$).

  - Sieve of Eratosthenes takes $O(M \log \log M)$.
  - Prime factorization and building the `prime_to_indices` map takes $O(N \log M)$.
  - BFS visits each index once and each prime-to-index edge once, totaling $O(N \log M)$.

- **Space Complexity:**  
  $O(M + N \log M)$.

  - The SPF array takes $O(M)$.
  - The `prime_to_indices` map stores at most $N \times (\text{max prime factors per number})$, which is roughly $7N$ for $M=10^6$.
