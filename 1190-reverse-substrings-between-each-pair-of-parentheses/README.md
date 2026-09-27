# 1190. Reverse Substrings Between Each Pair of Parentheses  

Metadata Table:
Property | Value
--- | ---
Difficulty | Medium
Topics | String, Stack, Bracket Sequences
Date | 2026-09-27
LeetCode Link | https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

## Intuition  
The string contains balanced parentheses and we must reverse the characters inside each matching pair, starting from the innermost pair and moving outward.  
A direct “reverse‑and‑remove” using a stack of substrings works but may repeatedly reverse the same characters, leading to O(n²) time in pathological cases (e.g., many nested parentheses).  

A linear‑time alternative is to **pre‑compute the matching partner for every parenthesis**. While scanning the string we keep a direction (`+1` for forward, `-1` for backward). When we hit a parenthesis we instantly jump to its partner and flip the direction, effectively simulating the nested reversals without performing any explicit string reversals. All characters that are not parentheses are appended to the answer in the order they are visited.  

This approach visits each index at most twice, giving O(n) time and O(n) extra space for the partner table.

## Complexity Analysis  
- **Time Complexity:** O(n), where n = s.length. Each index is processed a constant number of times.  
- **Space Complexity:** O(n) for the array that stores matching parenthesis indices and for the output string.