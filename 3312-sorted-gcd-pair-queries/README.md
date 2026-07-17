# 3312. Sorted GCD Pair Queries

| Property | Value |
| --- | --- |
| Difficulty | Hard |
| Topics | Array, Hash Table, Math, Binary Search, Combinatorics, Counting, Number Theory, Prefix Sum |
| Date | 2026-07-17 |
| LeetCode Link | [https://leetcode.com/problems/sorted-gcd-pair-queries/](https://leetcode.com/problems/sorted-gcd-pair-queries/) |

### Intuition

The number of pairs in an array of length $N$ is $N(N-1)/2$. With $N=10^5$, calculating all pairs directly is $O(N^2)$, which is too slow. Instead, we should count how many pairs have a GCD equal to some value $g$.

Let $M$ be the maximum value in `nums`. We can define:
1. `freq[x]`: The number of elements in `nums` that are multiples of $x$. This is computed by iterating through `nums` and incrementing counts for all divisors of each number.
2. `pairs_with_gcd_multiple[g]`: The number of pairs whose GCD is a multiple of $g$. Since a pair has a GCD that is a multiple of $g$ if and only if both numbers are multiples of $g$, this is simply $\binom{freq[g]}{2}$.
3. `count[g]`: The actual number of pairs where the GCD is exactly $g$. Using the Principle of Inclusion-Exclusion (or working backwards from $M$ to $1$), we can derive `count[g]` by subtracting `count[multiple]` for all multiples of $g$ from `pairs_with_gcd_multiple[g]`.

Once we have the frequency distribution of GCDs, we can compute the prefix sum of these counts to efficiently answer each query using binary search (or by pre-calculating the positions).

### Complexity Analysis

*   **Time Complexity:** $O(M \log M + N \sqrt{M} + Q \log M)$, where $M = 5 \times 10^4$ (the maximum element value), $N$ is the size of `nums`, and $Q$ is the number of queries. The $M \log M$ term comes from divisor counting and the inclusion-exclusion step, $N \sqrt{M}$ from finding divisors of every number in `nums`, and $Q \log M$ from binary searching through the GCD counts.
*   **Space Complexity:** $O(M)$, used to store frequencies, GCD counts, and the prefix sum array.