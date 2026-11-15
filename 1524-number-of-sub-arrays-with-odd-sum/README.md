# 1524. Number of Sub-arrays With Odd Sum
| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Math, Dynamic Programming, Prefix Sum |
| Date | 2026-11-15 |
| LeetCode Link | https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/ |

## Intuition & Approach
The sum of a sub‑array **arr[l..r]** equals `prefix[r] - prefix[l-1]`, where `prefix[i]` is the sum of the first *i* elements.  
Parity (odd/even) of a sum is completely determined by the parity of its two prefix sums:

* odd  ⇔  `prefix[r]` and `prefix[l-1]` have **different** parity  
* even ⇔  same parity

Therefore the problem reduces to counting ordered pairs of prefix indices `(i, j)` with `i < j` and opposite parity.  

A linear scan suffices:

1. Initialise `cntEven = 1` (empty prefix has sum 0 → even) and `cntOdd = 0`.  
2. Iterate through the array, maintaining the current prefix parity (`0` for even, `1` for odd).  
3. If the current parity is odd, every earlier even prefix creates an odd‑sum sub‑array ending at the current position ⇒ add `cntEven` to answer.  
   If the current parity is even, add `cntOdd`.  
4. Update the corresponding counter (`cntEven` or `cntOdd`).  
5. Apply modulo `1e9+7` after each addition to avoid overflow.

Why naïve enumeration fails: enumerating all O(n²) sub‑arrays exceeds the limits (`n ≤ 10⁵`). The prefix‑parity method collapses the DP state to two counters, achieving O(n) time and O(1) extra space.

## Complexity Analysis
- **Time Complexity:** O(n) – each element is processed once.  
- **Space Complexity:** O(1) – only a few integer variables are stored regardless of input size.