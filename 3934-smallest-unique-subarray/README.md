# 3934. Smallest Unique Subarray
| Property | Value |
| --- | --- |
| Difficulty | Hard |
| Topics | Array, Hash Table, Binary Search, Rolling Hash |
| Date | 2026-11-25 |
| LeetCode Link | https://leetcode.com/problems/smallest-unique-subarray/ |

## Intuition & Approach
1. **What we need** – the smallest length `L` for which **at least one** subarray of length `L` occurs exactly once in the whole array.  
2. **Monotonicity** – If a length `L` admits a unique subarray, any larger length `L' > L` also admits a unique subarray (the whole array of length `N` is always unique). Hence the answer lies on a monotone predicate `P(L) = “∃ unique subarray of length L”`. This permits a binary search on `L` in `O(log N)` steps.  
3. **Checking a fixed length efficiently** – For a given `L` we must count occurrences of *all* subarrays of that length. A naïve O(N·L) scan is too slow.  
   - Use a **rolling (polynomial) hash**: treat each subarray as a base‑`B` number.  
   - Pre‑compute prefix hashes `pref[i] = hash of nums[0…i‑1]` and powers `pow[i] = B^i`.  
   - Hash of subarray `nums[i…i+L‑1]` is `h = pref[i+L] − pref[i]·pow[L]` (mod `2^64`).  
   - Because we work with unsigned 64‑bit arithmetic, overflow implements the modulo automatically; the probability of a collision is negligible for the given constraints.  
4. **Counting hashes** – Insert each hash into an `unordered_map` (C++) / `dict` (Python) and increment its frequency. After the scan, if any frequency equals 1, `P(L)` is true.  
5. **Overall algorithm**  
   - Compute `pref` and `pow` once (O(N)).  
   - Binary search `L` in `[1, N]`. For each mid, run the linear scan described above (O(N)).  
   - Return the smallest `L` for which the check succeeds.  

Why simpler approaches fail:  
- Brute‑force enumeration of subarrays with direct comparison costs `O(N^2)` time and memory – impossible for `N = 10^5`.  
- Using a suffix array or suffix automaton yields `O(N log N)` but incurs heavyweight implementation; rolling hash gives the same asymptotic bound with far less code and constant factors.

## Complexity Analysis
- **Time**: Pre‑processing `O(N)`. Each binary‑search step scans the array once, thus `O(N)`. With `log₂ N` steps the total is `O(N log N)`.  
- **Space**: Prefix array `O(N)`, power array `O(N)`, and a hash‑frequency table of at most `N` entries → `O(N)` auxiliary space. Call‑stack depth is `O(1)`.