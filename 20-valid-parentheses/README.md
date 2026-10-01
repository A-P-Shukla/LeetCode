# 20. Valid Parentheses

Property | Value
--- | ---
Difficulty | Easy
Topics | String, Stack, Bracket Sequences
Date | 2026-10-01
LeetCode Link | https://leetcode.com/problems/valid-parentheses/

## Intuition
The problem asks us to verify that every opening bracket has a matching closing bracket **of the same type** and that the pairs are correctly nested.  
A **stack** models exactly this behavior: we push an opening bracket when we see it, and when we encounter a closing bracket we check the top of the stack. If the top matches the current closing bracket, we pop it; otherwise the string is invalid. At the end the stack must be empty, meaning all opens were closed.

Key points:

1. Only three types of brackets exist, so we can map each closing bracket to its corresponding opening one.
2. If we ever try to pop from an empty stack or the types don’t match, the string is invalid.
3. The algorithm runs in a single left‑to‑right pass.

## Complexity Analysis
- **Time:** O(n) – each character is processed once, where *n* is the length of the string.
- **Space:** O(n) in the worst case (e.g., `"(((...)))"`), because the stack may hold all opening brackets.