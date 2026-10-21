# 3863. Minimum Operations to Sort a String
| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | String |
| Date | 2026-10-21 |
| LeetCode Link | https://leetcode.com/problems/minimum-operations-to-sort-a-string/ |

## Intuition & Approach
1. **Goal** – Transform `s` into its globally non‑descending version `t` (the sorted characters of `s`).  
2. **Zero operations** – If `s` already equals `t`, answer `0`.  
3. **One operation feasibility** – Sorting any *proper* substring (`[l, r]` where `0 ≤ l ≤ r < n` and the substring is not the whole string) will reorder the characters inside that interval into ascending order, while leaving the rest untouched.  
   * Let `L` be the first index where `s` and `t` differ, and `R` the last such index.  
   * The multiset of characters in `s[L..R]` is exactly the multiset required for `t[L..R]` because `t` is the sorted version of the whole string.  
   * Consequently, sorting the substring `s[L..R]` yields `t` **iff** the interval `[L,R]` is a proper substring (i.e., it does **not** cover the entire string).  
   * Therefore, if `L > 0` or `R < n‑1`, a single operation suffices.  
4. **Impossibility for length 2** – When `n = 2` and `s` is not already sorted, the only substrings are single characters, which cannot change order. Hence answer `-1`.  
5. **Two operations are always enough for longer strings** –  
   * Sort the suffix `s[1…n‑1]`. After this, positions `1…n‑1` are sorted, but position `0` may still be out of place.  
   * Then sort the prefix `s[0…n‑2]`. This fixes the remaining disorder.  
   * For any `n ≥ 3` this construction works, guaranteeing an answer of `2` whenever `1` is impossible.  

The algorithm therefore reduces to:
* Compute `t = sorted(s)`.
* If `s == t` → `0`.
* If `n == 2` and `s != t` → `-1`.
* Find leftmost and rightmost mismatching indices `L` and `R`.
* If `[L,R]` is a proper substring → `1`, else → `2`.

## Complexity Analysis
*Sorting* the copy of `s` costs `O(n log n)` time and `O(n)` auxiliary space.  
Scanning for mismatches is `O(n)` time and `O(1)` extra space.  
Overall:  
- **Time Complexity:** `O(n log n)`  
- **Space Complexity:** `O(n)` (the sorted copy).