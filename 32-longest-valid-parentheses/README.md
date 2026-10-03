# 32. Longest Valid Parentheses

Metadata Table:
Property | Value
--- | ---
Difficulty | Hard
Topics | String, Dynamic Programming, Stack, Bracket Sequences
Date | 2026-10-03
LeetCode Link | https://leetcode.com/problems/longest-valid-parentheses/

## Intuition
The problem asks for the length of the longest contiguous substring that forms a correctly balanced parenthesis sequence.  
All linear‑time solutions rely on the fact that a valid substring can be identified by matching each closing `)` with a preceding unmatched opening `(`.  
Two common linear approaches are:

1. **Stack** – keep indices of characters that could start a valid substring. The distance between the current index and the index on the top of the stack gives the length of the current valid block.
2. **Two‑pass scan** – count left/right parentheses while scanning left‑to‑right and then right‑to‑left. Whenever the counts match we have a valid block; when the right count exceeds left we reset because a future match is impossible.

Both run in O(n) time and O(n) or O(1) extra space. The stack solution is easy to understand and works directly with indices, so we implement it for both C++ and Python.

## Complexity Analysis
- **Time:** O(n) – each character is processed once.
- **Space:** O(n) in the worst case for the stack (when the string consists solely of `'('`). The two‑pass method would use O(1), but the stack method is equally optimal for the given constraints.