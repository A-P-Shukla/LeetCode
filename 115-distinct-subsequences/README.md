# 115. Distinct Subsequences

Property | Value
--- | ---
Difficulty | Hard
Topics | String, Dynamic Programming
Date | September 6, 2026
LeetCode Link | https://leetcode.com/problems/distinct-subsequences/

## Intuition

The problem asks for the number of distinct subsequences of a string `s` that are identical to a target string `t`. Because we are dealing with counting matching subsequences that can be formed by deciding whether to include or exclude characters, this naturally suggests a Dynamic Programming (DP) approach.

Let `dp[i][j]` represent the number of distinct subsequences of `s[0...i-1]` that equal `t[0...j-1]`.

1. **Base Cases**:
   - `dp[i][0] = 1` for all `0 <= i <= len(s)`. An empty target string `t` can always be formed by picking an empty subsequence
 from `s` (exactly 1 way).
   - `dp[0][j] = 0` for all `j > 0`. A non-empty target `t` cannot be formed from an empty source string `s`.

2. **Transition**:
   For any pair of characters `s[i - 1]` and `t[j - 1]`:
   - We can always choose to skip the character `s[i - 1]`. The number of ways to form `t[0...j-1]` without using `s[i - 1]` is `dp[i - 1][j]`.
   - If `s[i - 1] == t[j - 1]`, we have the additional option to match this character. If we match them, the remaining prefix `t[0...j-2]` must be formed by `s[0...i-2]`, which gives `dp[i - 1][j - 1]` ways.
   - Therefore:
     - If `s[i - 1] == t[j - 1]`: `dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]`
     - If `s[i - 1] != t[j - 1]`: `dp[i][j] = dp[i - 1][j]`

3. **Space Optimization**:
   Notice that `dp[i][j]` only depends on values from the previous row `dp[i - 1]`. We can reduce the 2D DP table to a 1D array of size `len(t) + 1`. By iterating `j` backwards from `len(t)` down to `1`, we ensure that `dp[j - 1]` represents the value from the previous row (`dp[i - 1][j - 1]`), avoiding overwriting values we still need.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(m \times n)$, where $m$ is the length of string `s` and $n$ is the length of string `t`. We iterate through every character of `s` and for each, we process up to all characters of `t`.
- **Space Complexity:** $\mathcal{O}(n)$, where $n$ is the length of string `t`. By using a 1D dynamic programming array and updating it in reverse, we only store the counts corresponding to prefixes of `t`.