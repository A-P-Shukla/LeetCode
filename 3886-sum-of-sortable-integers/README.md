# 3886. Sum of Sortable Integers
| Property | Value |
| --- | --- |
| Difficulty | Hard |
| Topics | Array, Math, Sorting, Enumeration |
| Date | 2026-10-20 |
| LeetCode Link | https://leetcode.com/problems/sum-of-sortable-integers/ |

## Intuition & Approach
The operation allowed for a divisor `k` is **independent cyclic rotation of each consecutive subarray of length `k`**.  
After all rotations the whole array must be non‑decreasing.  
If we sort the original array once, obtaining `sorted = sorted(nums)`, the final configuration of any successful process **must equal** this sorted array – any other non‑decreasing permutation would still be a permutation of `nums` and therefore also be a rotation of some block, but the sorted order is the unique global target that can be reached by permuting the whole multiset while preserving the block boundaries.

Hence, for a fixed `k` the task reduces to the following deterministic check:

*Partition `nums` and `sorted` into the same blocks of size `k`.  
For each block `i` verify that the block from `sorted` is a **cyclic rotation** of the original block `nums[i·k … i·k+k‑1]`.*

A block `A` (size `k`) can be turned into another block `B` by rotation **iff** `B` appears as a contiguous sub‑array in `A+A` (the concatenation of `A` with itself).  
A linear scan suffices: locate a position where the first element matches, then verify the whole length. Because we stop at the first successful offset, the total work per block is `O(k)`. Summed over all blocks the check for a single divisor costs `O(n)`.  

The number of divisors of an integer ≤ 10⁵ is at most 128, so an overall `O(n·d)` algorithm (≈ 10⁷ operations) easily fits the limits.

Algorithm steps:

1. Store `sorted = nums` sorted in non‑decreasing order.
2. Enumerate every divisor `k` of `n`.
3. For each divisor run the block‑wise rotation test described above.
4. If every block passes, add `k` to the answer sum.
5. Return the accumulated sum.

Edge cases:
- When `nums` is already sorted, every divisor works (the test trivially succeeds).
- If all elements of a block are identical, any rotation matches; our scan stops after the first offset, keeping the complexity linear.

## Complexity Analysis
- **Time:** For each divisor `k` we examine all `n` elements once → `O(n · d)`, where `d` is the number of divisors of `n` ( ≤ 128 for `n ≤ 10⁵`).  
- **Space:** `O(n)` for the sorted copy and a few auxiliary vectors; recursion depth is constant → `O(n)` total auxiliary space.