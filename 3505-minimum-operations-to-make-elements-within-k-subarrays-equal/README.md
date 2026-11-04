# 3505. Minimum Operations to Make Elements Within K Subarrays Equal
| Property | Value |
| --- | --- |
| Difficulty | Hard |
| Topics | Array, Hash Table, Math, Dynamic Programming, Sliding Window, Heap (Priority Queue) |
| Date | 2026-11-04 |
| LeetCode Link | https://leetcode.com/problems/minimum-operations-to-make-elements-within-k-subarrays-equal/ |

## Intuition & Approach
1. **Cost of a single window**  
   For a fixed window of length `x`, the cheapest way to make all its elements equal is to turn every element into the **median** of that window.  
   *Proof*: The sum of absolute deviations `∑|a_i‑v|` is a convex, piece‑wise linear function of `v`. Its minimum is attained at any median of the multiset `{a_i}`.  

   Therefore the minimal operations for a window =  
   `median * cntLow – sumLow + sumHigh – median * cntHigh`,  
   where `low` holds the `⌈x/2⌉` smallest elements (including the median) and `high` the rest.

2. **Sliding‑window median with two heaps**  
   We must evaluate this cost for **every** window start `s ∈ [0, n‑x]`.  
   - `low` – max‑heap (implemented as a min‑heap of negatives) storing the smaller half.  
   - `high` – min‑heap storing the larger half.  
   - `sumLow`, `sumHigh` track the sums of elements in each heap.  
   - After each insertion/deletion we rebalance so that `|low| = ⌈x/2⌉`.  
   - The median is `-low[0]`.  
   This yields `O(log x)` per slide, total `O(n log x)`.

3. **Choosing `k` non‑overlapping windows**  
   After we have an array `cost[i]` (cost to homogenize the window starting at `i`), the problem reduces to selecting `k` disjoint windows of length `x` with minimum total cost.  

   Let `dp[i][j]` be the minimal operations using the prefix `nums[0…i‑1]` (first `i` elements) and forming exactly `j` windows.  
   Transition (1‑based `i` for convenience):
   - **Skip** `i‑1`: `dp[i][j] = dp[i‑1][j]`.  
   - **Take** a window ending at `i‑1`: if `i ≥ x` and `j ≥ 1`  
     `dp[i][j] = min(dp[i][j], dp[i‑x][j‑1] + cost[i‑x])`.  

   Base: `dp[0][0] = 0`, `dp[0][j>0] = INF`.  
   Because `k ≤ 15`, the DP runs in `O(n k)` (≈ 1.5 M steps) which is trivial.

4. **Why greedy fails**  
   Picking the cheapest windows greedily can lead to overlap that precludes reaching `k` windows, or may force a later expensive window. The DP guarantees the global optimum under the non‑overlap constraint.

5. **Overall algorithm**
   - Compute `cost[s]` for all window starts `s` using the two‑heap sliding median.
   - Run the DP described above.
   - Answer = `dp[n][k]`.

## Complexity Analysis
- **Sliding‑window median**: `O(n log x)` time, `O(x)` auxiliary space for the two heaps.
- **Dynamic programming**: `O(n k)` time, `O(n k)` space (`≈ 12 MiB` for `n = 10⁵`, `k = 15`).  
  Space can be reduced to `O(n)` or `O(k)` with rolling arrays, but the full table remains well within limits.
- **Total**: `O(n (log x + k))` time, `O(n k + x)` memory.