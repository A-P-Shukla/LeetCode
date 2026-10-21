# 3863. Minimum Operations to Sort a String
| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | String |
| Date | 2026-10-21 |
| LeetCode Link | https://leetcode.com/problems/minimum-operations-to-sort-a-string/ |

## Intuition & Approach
The operation can sort **any proper substring** (any contiguous block that is not the whole string).  
Sorting a substring puts its characters in non‑decreasing order, i.e. exactly the order they would have in the globally sorted string `t = sort(s)`.

* If `s` is already equal to `t`, no operation is needed ⇒ answer 0.

* Otherwise locate the leftmost index `L` and the rightmost index `R` where `s` differs from `t`.  
  All mismatched characters lie inside the interval `[L, R]`.

  *If `[L, R]` is **not** the whole string* (`L > 0` or `R < n‑1`), we can sort this single proper substring once; after sorting it becomes identical to `t`. Hence answer 1.

* The only remaining case is when the whole string differs from the sorted version (`L = 0` and `R = n‑1`).  
  - For `n = 2` the only proper substrings are single characters, which never change the order, so sorting is impossible ⇒ answer ‑1.  
  - For `n ≥ 3` we can always achieve the goal in two operations.  
    One operation can bring the smallest character to the front (by sorting a prefix that excludes the last character), and a second operation can place the largest character at the end (by sorting a suffix that excludes the first character). After these two steps the string becomes completely sorted. Hence answer 2.

The algorithm therefore reduces to checking these three simple conditions.

## Complexity Analysis
*Time*: Sorting a copy of the string costs `O(n log n)`. All other scans are linear, yielding total `O(n log n)`.  
*Space*: An extra string of length `n` for the sorted copy ⇒ `O(n)` auxiliary space.