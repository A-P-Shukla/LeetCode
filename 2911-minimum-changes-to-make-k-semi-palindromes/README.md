# 2911. Minimum Changes to Make K Semi-palindromes
| Property | Value |
| --- | --- |
| Difficulty | Hard |
| Topics | Two Pointers, String, Dynamic Programming |
| Date | 2026-11-17 |
| LeetCode Link | https://leetcode.com/problems/minimum-changes-to-make-k-semi-palindromes/ |

## Intuition & Approach
1. **Semi‑palindrome cost for a fixed string**  
   For a string `t` of length `m` we may pick any divisor `d` (`1 ≤ d < m`, `d | m`).  
   The characters are split into `d` groups, each group being the characters of an arithmetic progression with step `d`.  
   Within a group we must obtain a palindrome, i.e. each symmetric pair of positions must hold the same letter.  
   The cheapest way to enforce this is to count mismatched pairs inside the group; each mismatch can be fixed with a single character change.  
   The cost for a divisor `d` is the sum of mismatches over all groups.  
   The minimal cost for `t` is the minimum over all its valid divisors.

2. **Pre‑computing substring costs**  
   `n = |s| ≤ 200`.  
   For every interval `[l, r]` (0‑based, inclusive) we compute `cost[l][r]` – the minimum number of changes required to turn `s[l..r]` into a semi‑palindrome.  
   For each interval we enumerate its divisors (O(√m) per interval) and, for each divisor, scan the groups in O(m) time.  
   Overall pre‑computation is `O(n³)` in the worst case, which is ≤ 8 × 10⁶ operations for `n = 200` – comfortably fast.

3. **Dynamic programming over partitions**  
   Let `dp[i][p]` be the minimal total changes needed to partition the prefix `s[0..i‑1]` into exactly `p` semi‑palindromic substrings.  
   Transition: choose the last cut at position `j` ( `0 ≤ j < i` )  

   ```
   dp[i][p] = min_{j} dp[j][p‑1] + cost[j][i‑1]
   ```

   Initialise `dp[0][0] = 0` and other states as INF.  
   The answer is `dp[n][k]`.

   Complexity of the DP is `O(k·n²)` ≤ `O(n³)`.

4. **Why greedy / simple two‑pointer fails**  
   A greedy choice of the smallest possible divisor for each substring ignores interactions between adjacent parts: a slightly more expensive divisor in an early part may enable a dramatically cheaper split later. Only the exhaustive DP guarantees optimal global cost.

5. **Data structures**  
   * A 2‑D vector `cost[n][n]` (int) for substring costs.  
   * A 2‑D DP table `dp[n+1][k+1]`.  
   Both fit easily into memory (`≈ 200·200·4 bytes`).

## Complexity Analysis
- **Pre‑computation:**  
  For each of the `O(n²)` substrings we enumerate at most `O(√n)` divisors and scan `O(m)` characters → `O(n³)` time.  
  Space: `O(n²)` for `cost`.

- **Dynamic programming:** `O(k·n²)` ≤ `O(n³)` time, `O(n·k)` space (reduced to two rows if desired).  

- **Overall:**  
  Time `O(n³)` (worst‑case ≈ 8 × 10⁶ operations for `n = 200`).  
  Space `O(n²)`.