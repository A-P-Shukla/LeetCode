# 3551. Minimum Swaps to Sort by Digit Sum
| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Hash Table, Sorting |
| Date | 2026-10-17 |
| LeetCode Link | https://leetcode.com/problems/minimum-swaps-to-sort-by-digit-sum/ |

## Intuition & Approach
The goal is to rearrange `nums` into the order obtained by sorting the numbers **first** by the sum of their decimal digits and **second** by their numeric value (to break ties).  
Because all numbers are distinct, the target order is a **permutation** of the original array. The minimal number of swaps required to transform one permutation into another equals the sum over all disjoint cycles of `(cycle_length − 1)`.  

**Why naïve swapping fails**  
A greedy “swap any out‑of‑order pair” may perform extra swaps because it does not respect the global cycle structure. Only by examining the permutation as a whole can we guarantee optimality.

**Algorithm**
1. **Digit‑sum computation** – For each element `x` compute `digitSum(x)`. O(number of digits) per element, overall O(n).
2. **Determine target order** – Build a vector of pairs `(digitSum, value)` and sort it with the comparator `(a.digitSum < b.digitSum) || (a.digitSum == b.digitSum && a.value < b.value)`. The sorted values give the desired final array.
3. **Map each value to its target index** – Since values are unique, a hash table `value → targetIdx` is sufficient.
4. **Cycle decomposition** – Walk through the original indices. For each unvisited index `i`, follow the chain `i → targetIdx[nums[i]] → …` until returning to `i`. A cycle of length `k` needs `k‑1` swaps. Accumulate this count.
5. Return the total swaps.

The algorithm runs in `O(n log n)` due to sorting and uses `O(n)` extra space for the mapping and visitation flags.

## Complexity Analysis
- **Time Complexity:** `O(n log n)` – sorting dominates; digit‑sum computation and cycle traversal are linear.
- **Space Complexity:** `O(n)` – stores sorted order, mapping from value to target index, and a visited boolean array.