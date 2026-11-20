# 3041. Maximize Consecutive Elements in an Array After Modification
| Property | Value |
| --- | --- |
| Difficulty | Hard |
| Topics | Array, Dynamic Programming, Sorting |
| Date | 2026-11-20 |
| LeetCode Link | https://leetcode.com/problems/maximize-consecutive-elements-in-an-array-after-modification/ |

## Intuition & Approach
1. **What can an element become?**  
   Each `nums[i]` may stay as `v` or become `v+1`. Therefore an index can contribute to at most two consecutive values: `v` (its original) or `v+1` (after increment).

2. **Re‑formulation**  
   After the optional increments we need a subset whose *sorted* values are a consecutive interval `[L, R]`.  
   For every integer `x` in that interval we must assign a distinct index whose original value is either `x` or `x‑1`.

3. **Supply view**  
   For a concrete integer `x` the pool of usable indices is `cnt[x]` (original `x`) plus `cnt[x‑1]` (original `x‑1` that we may have increased).  
   However an index that was used as `x‑1 → x` cannot be used again for `x+1`. The “carry” from one value can be used **once** for the next value only.

4. **Greedy construction of a run**  
   Scan the values in increasing order while maintaining a *carry* – the number of original `v‑1` elements that were increased to `v` and are still available for the current `v`.  
   - If `carry > 0`, we first consume a carried element for the current integer. All original `v` elements stay untouched and can be carried forward to `v+1`.  
   - If `carry == 0`, we must consume one of the original `v` elements; the remaining `cnt[v]‑1` originals become the new carry.

   This “use‑carry‑first” rule is optimal because it preserves as many original elements as possible for future positions, maximising the length of the consecutive run.

5. **Running the scan**  
   *Initialize* `carry = 0`, `cur_len = 0`, `ans = 0`.  
   For each integer `v` from `1` up to `max(nums)+1` (the extra slot is needed because a value can be increased to the next integer):
   - `supply = cnt[v] + carry`.  
   - If `supply == 0` the current run cannot be extended; reset `carry` and `cur_len`.  
   - Otherwise extend the run (`cur_len++`) and update `carry` according to the rule above.  
   - Update `ans = max(ans, cur_len)`.

   The scan is linear in the range of possible values (≤ 10⁶ + 1), well within limits.

6. **Why sub‑optimal methods fail**  
   - *Brute‑force selection* of subsets is exponential.  
   - *Sorting and then greedy pick* without accounting for the one‑step increment constraint may double‑use an element, violating the problem’s rule.  
   - *Dynamic programming over indices* would be O(n²). The presented frequency‑based linear scan leverages the limited modification (+1) to achieve O(maxV) time.

## Complexity Analysis
- **Time Complexity:** `O(maxV)` where `maxV = max(nums) + 1 ≤ 10⁶ + 1`. The scan touches each possible integer once.  
- **Space Complexity:** `O(maxV)` for the frequency array (`int` per value). No recursion, so call‑stack depth is `O(1)`.