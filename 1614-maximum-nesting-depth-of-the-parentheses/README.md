# 1614. Maximum Nesting Depth of the Parentheses

Metadata Table:
Property | Value
--- | ---
Difficulty | Easy
Topics | String, Stack, Bracket Sequences
Date | 2026-09-28
LeetCode Link | https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

## Intuition
The string is guaranteed to be a *valid* parentheses string (VPS).  
Whenever we encounter a `'('` we go one level deeper, and when we see a `')'` we retreat one level.  
The maximum depth reached during this walk is precisely the nesting depth we need.  
Because we only care about the count of open parentheses at any point, a full stack is unnecessary—an integer counter suffices.

## Complexity Analysis
- **Time:** O(n) – we scan the string once, where *n* is `s.length`.
- **Space:** O(1) – only two integer variables are used regardless of input size.