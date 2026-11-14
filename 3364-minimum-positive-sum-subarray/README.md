# 3364. Minimum Positive Sum Subarray
| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | Array, Sliding Window, Prefix Sum |
| Date | 2026-11-14 |
| LeetCode Link | https://leetcode.com/problems/minimum-positive-sum-subarray/ |

## Intuition & Approach
We must examine every contiguous subarray whose length lies in the inclusive interval **[l, r]** and whose sum is strictly positive, then pick the smallest such sum.  
Because the array size is at most 100, a naïve double‑loop that enumerates all possible start‑end pairs is already optimal in practice ( ≤ 10⁴ iterations).  

A more systematic view uses prefix sums: `pref[i]` stores the sum of the first `i` elements (`pref[0]=0`). The sum of a subarray `[i, j)` equals `pref[j] - pref[i]`. For a fixed end index `j`, every valid start index `i` satisfies `j-i ∈ [l, r]`. Enumerating these `i` values yields all candidate sums.  

Why not a classic sliding‑window? A sliding window maintains a single contiguous segment while its length changes, but the sign of elements can be arbitrary; shrinking or expanding the window does not guarantee monotonicity of the sum, so the minimal positive sum cannot be found without checking all admissible lengths. Hence exhaustive enumeration is both correct and simple given the constraints.

The algorithm therefore:

1. Compute prefix sums.
2. For each end index `j` from `l` to `n`:
   * For each length `len` in `[l, r]` where `i = j - len ≥ 0`:
     * Compute `sum = pref[j] - pref[i]`.
     * If `sum > 0` and smaller than the current answer, update the answer.
3. Return the answer if found; otherwise return `-1`.

Both C++ and Python implementations follow this exact logic.

## Complexity Analysis
- **Time Complexity:**  
  The double loop iterates over at most `n` end positions and up to `r-l+1 ≤ n` lengths, giving a worst‑case of `O(n·r) = O(n²)`. With `n ≤ 100` this is ≤ 10⁴ operations.
- **Space Complexity:**  
  Prefix array of size `n+1` → `O(n)` auxiliary space. No additional recursion or data structures.