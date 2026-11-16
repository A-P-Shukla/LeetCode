# 2243. Calculate Digit Sum of a String

| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | String, Simulation |
| Date | 2026-11-16 |
| LeetCode Link | https://leetcode.com/problems/calculate-digit-sum-of-a-string/ |

## Intuition & Approach
The process described is a pure simulation: repeatedly partition the current string into consecutive blocks of size k (the final block may be shorter), replace each block by the decimal representation of the sum of its digits, and stop when the string length no longer exceeds k.

A naïve approach might try to pre‑compute all intermediate strings or use recursion with heavy copying. However, each round only needs the current string; older versions are irrelevant. Hence we can iteratively overwrite the string, keeping the implementation simple and memory‑efficient.

Key observations:
1. **Digit‑wise sum is independent of block boundaries** – we only need to scan each character once per round.
2. **String length strictly decreases after a round** unless the sum of a block is a single digit that does not shrink the block size; nevertheless, with the given constraints (|s| ≤ 100) the number of rounds is bounded by |s|.
3. **Using `to_string` (C++) / `str()` (Python) automatically handles multi‑digit sums** – no manual conversion is required.

Algorithm steps:
1. While `s.length() > k`:
   - Initialise an empty result string `next`.
   - Iterate over `s` with step size k:
     - Compute the digit sum of the slice `s[i : i+k]`.
     - Append `to_string(sum)` (or `str(sum)`) to `next`.
   - Replace `s` with `next`.
2. Return `s`.

The algorithm uses only O(1) extra space besides the output string for the next round and runs in O(n × r) time where `n` is the original length and `r` is the number of rounds (worst‑case O(n²) but ≤ 10⁴ operations for the constraints).

## Complexity Analysis
- **Time Complexity:**  
  Each round scans the current string once ⇒ O(current length).  
  In the worst case the length decreases by at most 1 per round, yielding a harmonic series sum ⇒ O(n²) where n = initial |s| (n ≤ 100, so ≤ 10⁴ operations).
- **Space Complexity:**  
  Only the new string for the next round is stored ⇒ O(n) auxiliary space (dominates by the output string itself). Call‑stack depth is O(1).