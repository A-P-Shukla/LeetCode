# 3886. Sum of Sortable Integers
| Property | Value |
| --- | --- |
| Difficulty | Hard |
| Topics | Array, Math, Sorting, Enumeration |
| Date | 2026-10-20 |
| LeetCode Link | https://leetcode.com/problems/sum-of-sortable-integers/ |

**Intuition & Approach**  
A divisor *k* of the array length *n* is *sortable* if we can rotate each consecutive block of length *k* independently and obtain the globally non‑decreasing order.  
Let `sorted = sorted(nums)`. After the rotations the whole array must equal `sorted`. Therefore, for each block `b` (starting at index `b*k`) the final contents must be exactly the sorted slice `sorted[b*k … (b+1)*k)`. The only freedom inside a block is a cyclic shift, i.e. the target slice must be a **cyclic rotation** of the original block.

Consequently, for a given *k* we only need to verify, for every block, that its target slice is a cyclic rotation of its original slice. If any block fails, *k* is not sortable.

Testing cyclic equality can be done in linear time with KMP: a pattern `T` (the target slice) occurs in the text `A+A` (the original block concatenated with itself) iff `T` is a rotation of `A`. We restrict matches to start positions `< k` to avoid the trivial duplicate at index *k*.

The algorithm:

1. Compute `sorted` once.  
2. Enumerate all divisors of *n* (≤ ~128 for *n* ≤ 10⁵).  
3. For each divisor *k*:  
   * Iterate over blocks (`start = 0, k, 2k, …`).  
   * Extract `A = nums[start:start+k]` and `T = sorted[start:start+k]`.  
   * Run KMP to check whether `T` is a rotation of `A`.  
   * If every block passes, add *k* to the answer.  

Overall work is `O(n * d)` where `d` is the number of divisors, well within limits.

**Complexity Analysis**  
- **Time:** `O(n * d)` ≤ `O(n * 128)` ≈ `1.3·10⁷` operations.  
- **Space:** `O(n)` for the sorted copy plus `O(k)` auxiliary space for the KMP prefix table (reused per block).