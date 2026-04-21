# 1722. Minimize Hamming Distance After Swap Operations

Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Depth-First Search, Union-Find, Hash Table
Date | April 21, 2026
LeetCode Link | [Minimize Hamming Distance After Swap Operations](https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/)

## Intuition

The core of this problem lies in understanding the transitive property of the swap operations. If we can swap the element at index $A$ with index $B$, and the element at index $B$ with index $C$, we can effectively move the element at $A$ to $C$ (and vice versa) through a series of swaps. This implies that any indices that are connected through `allowedSwaps` form a **connected component**.

Within any connected component of indices, we can rearrange the elements of `source` in any permutation we desire. To minimize the Hamming distance, our goal is to maximize the number of positions $i$ where `source[i] == target[i]`. 

For each connected component, we look at the multiset of values present in `source` at those indices and the multiset of values present in `target` at those same indices. The maximum number of matches we can achieve for that component is the size of the intersection of these two multisets. The total minimum Hamming distance is then the total number of elements minus the sum of these maximum matches across all components.

## Complexity Analysis

### Time Complexity
- **Union-Find Operations:** We perform $E$ unions (where $E$ is the number of allowed swaps) and $N$ find operations. With path compression and union by rank/size, this is nearly $O(E \alpha(N) + N \alpha(N))$, where $\alpha$ is the inverse Ackermann function.
- **Grouping and Matching:** We iterate through all $N$ indices to group them by their component root and count frequencies. This takes $O(N)$ time.
- **Total:** $O((N + E) \alpha(N))$, which is effectively linear for practical constraints.

### Space Complexity
- **Union-Find Data Structure:** $O(N)$ to store the parent and rank/size arrays.
- **Frequency Maps:** $O(N)$ to store the values of `source` and `target` associated with each component.
- **Total:** $O(N)$.