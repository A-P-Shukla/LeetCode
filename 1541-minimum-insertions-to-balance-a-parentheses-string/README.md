# 1541. Minimum Insertions to Balance a Parentheses String

Metadata Table:
Property | Value
--- | ---
Difficulty | Medium
Topics | String, Stack, Greedy, Bracket Sequences
Date | 2026-10-09
LeetCode Link | https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/

## Intuition
A balanced string requires every `'('` to be followed by **two consecutive** `')'`.  
Scanning the string left‑to‑right we keep track of how many `')'` we are currently waiting for (`need`).  

* When we see `'('` we know it will need two `')'` later, so `need += 2`.  
* When we see `')'` we satisfy one pending `')'` (`need--`).  

Two special cases appear:

1. **Odd `need` before processing a `')'`** –  
   The previous `'('` expects a pair `"))"`. If we have only one slot left, the current `')'` would become the first of that pair, leaving a single `')'` dangling. We can fix this by inserting a `'('` **before** the current `')'`, which adds one insertion and flips the required count from odd to even (`need--`).

2. **`need` becomes negative** –  
   We encountered a `')'` that has no matching `'('`. The cheapest fix is to insert a `'('` right before it (one insertion). After that insertion the current `')'` serves as the first `')'` of the required pair, so we set `need = 1` (still waiting for the second `')'`).

At the end of the scan, any remaining `need` represents missing `')'` that must be appended. The total answer is the insertions made during the scan plus `need`.

This greedy, single‑pass method uses only a few integer counters – no stack is needed.

## Complexity Analysis
- **Time:** O(n) – each character is examined once.  
- **Space:** O(1) – only a few integer variables are stored.