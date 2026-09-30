# 1111. Maximum Nesting Depth of Two Valid Parentheses Strings

Property | Value
--- | ---
Difficulty | Medium
Topics | String, Stack, Bracket Sequences
Date | 2026-09-30
LeetCode Link | https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/

## Intuition
The original sequence is a valid parentheses string (VPS).  
If we traverse it while keeping the current nesting depth, each opening ‘(’ pushes the depth up by 1 and each closing ‘)’ pulls it down by 1.  

A simple way to split the sequence is to put a parenthesis into group 0 when the *current* depth is even and into group 1 when it is odd.  
Implementation details:

* For ‘(’: increase depth first, then assign `group = depth % 2`.
* For ‘)’: assign `group = depth % 2` **before** decreasing depth.

Why does this work?

* Both groups independently form a VPS because every opening parenthesis is matched with a closing parenthesis that shares the same parity of depth.
* The maximum depth of each group is at most `⌈originalDepth / 2⌉`.  
  This is optimal because any split must distribute the original nesting levels between the two groups, and the best we can hope for is to halve the deepest level.

Thus the parity‑based assignment yields a minimal possible `max(depth(A), depth(B))`.

## Complexity Analysis
*Time* – We scan the string once, performing O(1) work per character: **O(n)** where *n* is `seq.length`.  
*Space* – The answer array of length *n* is stored: **O(n)** auxiliary space.