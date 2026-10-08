# 1021. Remove Outermost Parentheses

Property | Value
--- | ---
Difficulty | Easy
Topics | String, Stack, Bracket Sequences
Date | 2026-10-08
LeetCode Link | https://leetcode.com/problems/remove-outermost-parentheses/

## Intuition
The string `s` is guaranteed to be a valid parentheses sequence.  
A *primitive* segment starts when the nesting level goes from `0` to `1` and ends when the level returns to `0`.  
The outermost pair of each primitive is precisely the first `'('` that raises the depth from `0` to `1` and the matching `')'` that brings the depth back to `0`.  
Therefore, while scanning the string we can keep a counter `depth` that represents the current nesting level:

* When we see `'('` we increase `depth`.  
  * If `depth` was already positive **before** the increment, the `'('` belongs to the inner part of a primitive and should be kept.  
* When we see `')'` we decrease `depth`.  
  * After decrementing, if `depth` is still positive, the `')'` is an inner closing bracket and should be kept.

Appending only those characters builds the answer without the outermost parentheses of every primitive.

## Complexity Analysis
* **Time:** `O(n)` – each character is inspected once, where `n = s.length`.  
* **Space:** `O(n)` – the result string may store up to `n‑2·k` characters (`k` is the number of primitives), which is linear in the input size.