# 856. Score of Parentheses

Property | Value
--- | ---
Difficulty | Medium
Topics | String, Stack, Bracket Sequences
Date | 2026-10-05
LeetCode Link | https://leetcode.com/problems/score-of-parentheses/

## Intuition
The score can be built from the innermost pairs outward.  
* "`()`" contributes **1**.  
* When a pair wraps a balanced substring `A`, the score becomes `2 * score(A)`.  
* Concatenated balanced parts simply add their scores.

A stack naturally mirrors the nesting structure: push a marker for each `'('`. When a `')'` is seen we either have the immediate pair "`()`" (top of stack is the marker) → push **1**, or we have a nested block: pop all scores accumulated inside the current pair, sum them, double the sum, and push the result back. At the end, the stack contains the scores of top‑level components; summing them yields the final answer.

The algorithm is linear, using only a single pass and a stack of at most *n* elements.

## Complexity Analysis
- **Time:** O(n) – each character is processed once, and each stack element is pushed and popped at most once.  
- **Space:** O(n) – in the worst case (e.g., all `'('` followed by all `')'`) the stack depth equals the length of the string.