# 3644. Maximum K to Sort a Permutation
| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Bit Manipulation |
| Date | 2026-10-23 |
| LeetCode Link | https://leetcode.com/problems/maximum-k-to-sort-a-permutation/ |

## Intuition & Approach
1. **Swap feasibility graph** –  
   Consider each *value* `v` (0 ≤ v < n) as a vertex.  
   An undirected edge is present between vertices `a` and `b` iff  
   `a & b == k`.  
   Performing a swap exchanges the two vertices, so after any number of swaps any permutation that respects the connected components of this graph is reachable.

2. **Connectivity requirement** –  
   To sort, for every index `i` we must be able to move the value `i` to position `i`.  
   Therefore `i` and the value currently at position `i` (`nums[i]`) must lie in the *same* connected component of the graph defined by `k`.

3. **Impact of bits of `k`** –  
   *If a bit is set in `k`, every vertex participating in an edge must also have that bit set* (otherwise the AND could never equal `k`).  
   Consequently any vertex that **lacks** a bit of `k` becomes isolated and can only stay at its original position.  
   Hence **every misplaced value** (both the index `i` and `nums[i]` for which `i != nums[i]`) must contain all bits of `k`.

4. **Maximum possible `k`** –  
   The bits that appear in **all** misplaced values are exactly the bitwise AND of those values.  
   Let  

   ```
   M = AND over all numbers that appear in a misplaced pair (i, nums[i])
   ```

   Any `k` must be a sub‑mask of `M`. The largest such `k` is `M` itself.

5. **Why the graph becomes fully connected for this `k`** –  
   The permutation contains **every** number from `0` to `n‑1`, therefore the number `k` itself is present.  
   For any vertex `x` that contains all bits of `k`, we have `x & k == k`; thus `x` is directly adjacent to `k`.  
   The vertex `k` acts as a universal hub, making the whole set of vertices that contain `k` belong to a single component.  
   Consequently, when `k = M`, the condition “`i` and `nums[i]` lie in the same component” is automatically satisfied.

6. **Edge case – already sorted** –  
   If no index is misplaced, the set over which we compute the AND is empty.  
   By definition the answer must be `0`.

**Algorithm**  
* Scan the array once.  
* Whenever `nums[i] != i`, incorporate both `i` and `nums[i]` into a running bitwise AND.  
* If no such index exists, return `0`; otherwise return the computed AND.

The algorithm is linear in time and constant in auxiliary space.

## Complexity Analysis
*Time*: `O(n)` – a single pass over the `n` elements.  
*Space*: `O(1)` – only a few integer variables are used irrespective of `n`.