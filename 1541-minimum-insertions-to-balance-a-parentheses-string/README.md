# 1541. Minimum Insertions to Balance a Parentheses String

Metadata Table:
Property | Value
--- | ---
Difficulty | Medium
Topics | String, Stack, Greedy, Bracket Sequences
Date | 2026-10-09
LeetCode Link | https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/

## Intuition
The string is *balanced* when every `'('` is paired with **two consecutive** `')'`.  
Think of the algorithm as maintaining how many right‑parentheses we *still need* to close the opened left‑parentheses.

- `need` – the number of `')'` required at the current position.
- `ans` – total insertions performed so far.

Scanning the string left‑to‑right:

1. When we see `'('` we now require **two** more `')'` (`need += 2`).  
   If `need` becomes odd, the previous requirement was for an odd number of `')'`, which is impossible because `')'` come in pairs. We therefore insert one `')'` immediately (`ans++`) and reduce `need` by one to make it even.

2. When we see `')'` we consume one required closing (`need--`).  
   If `need` drops to `-1` we have an extra `')'` that cannot belong to any pending `'('`. The only way to fix this is to insert a `'('` before this `')'` (`ans++`). That new `'('` now expects two `')'`, but we have already used one, so `need` becomes `1`.

After the scan, any remaining `need` indicates missing `')'` at the end; we insert them directly (`ans += need`).

The greedy decisions are locally optimal and never hurt later characters, guaranteeing a global optimum.

## Complexity Analysis
- **Time:** O(n) – each character is processed once.  
- **Space:** O(1) – only a few integer counters are used.