# 2267. Check if There Is a Valid Parentheses String Path

Metadata Table:
Property | Value
--- | ---
Difficulty | Hard
Topics | Array, Dynamic Programming, Matrix, Bracket Sequences
Date | 2026-09-29
LeetCode Link | https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/

## Intuition
A parentheses string is valid iff every prefix has at least as many `'('` as `')'` and the total number of opening and closing brackets are equal.  
While walking from the top‑left to the bottom‑right cell we can treat the **balance** `b = #('(') – #(')')` as a state:

* `b` must never become negative (otherwise a prefix is invalid).
* At the destination we need `b == 0`.

The path length is at most `m + n – 1 ≤ 199`, therefore the balance never exceeds this bound.  
We can perform a DP over the grid, storing for each cell all balances that are reachable with a valid prefix. The transition is simple:

```
new_balance = old_balance + (grid[i][j] == '(' ? 1 : -1)
```

Only non‑negative balances are kept.  
Optionally we discard balances that are larger than the number of steps still available, because they can never be closed later.

If after processing the bottom‑right cell balance `0` is reachable, a valid path exists.

## Complexity Analysis
*Time*:  `O(m * n * L)` where `L = m + n` (maximum possible balance, ≤ 200).  
*Space*: `O(m * n * L)` booleans, which is at most `100 * 100 * 200 ≈ 2·10⁶` bits ≈ 250 KB; a `bitset` implementation reduces it further.