# 301. Remove Invalid Parentheses

Metadata Table:
Property | Value
--- | ---
Difficulty | Hard
Topics | String, Backtracking, Breadth-First Search
Date | 2026-10-07
LeetCode Link | https://leetcode.com/problems/remove-invalid-parentheses/

## Intuition
The task is to delete the fewest parentheses so that the remaining string becomes valid.  
Because every removal reduces the length by exactly one, the **minimum** number of deletions corresponds to the **first** level in a breadth‑first search (BFS) where we encounter any valid strings.  

The BFS starts from the original string and generates all possible strings by removing one character at each position (skipping duplicate removals).  
All strings are stored in a `visited` set to avoid re‑processing.  
When a level yields at least one valid string, we stop – deeper levels would remove more characters, which is unnecessary.  
Validity is checked by scanning the string and maintaining a counter: `(` increments, `)` decrements, and the counter must never become negative; it must end at zero.

Because the input length is ≤ 25 and there are at most 20 parentheses, the search space is small enough for BFS to finish quickly.

## Complexity Analysis
*Time*: In the worst case we explore every subset of the parentheses → **O(2ⁿ)** where *n* is the number of parentheses (≤ 20). With BFS we stop early once the minimal removal level is found, making the practical running time far lower.  
*Space*: We store visited strings and a queue for the current BFS frontier → **O(2ⁿ)** in the worst case.