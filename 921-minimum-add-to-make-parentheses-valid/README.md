# 921. Minimum Add to Make Parentheses Valid

Metadata Table:
Property | Value
--- | ---
Difficulty | Medium
Topics | String, Stack, Greedy, Bracket Sequences
Date | 2026-10-06
LeetCode Link | https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

## Intuition
A valid parentheses string never has a closing bracket `)` that does not have a matching opening bracket `(` before it, and it never ends with unmatched opening brackets.  
Scanning the string from left to right we can keep a counter `balance` that represents how many unmatched `'('` we have seen so far.

* When we see `'('`, we increment `balance` because we now have one more opening bracket that needs a partner.
* When we see `')'`:
  * If `balance > 0`, there is an unmatched `'('` available, so we pair it and decrement `balance`.
  * If `balance == 0`, the current `')'` has nothing to match, so we must insert a `'('` before it. This contributes one required insertion (`additions++`).

After the full pass, any remaining `balance` indicates that many `'('` still lack a closing partner, each requiring one `')'` insertion. The answer is `additions + balance`.

This greedy one‑pass solution is optimal because each time we encounter an impossible closing bracket we are forced to add a matching opening bracket, and each leftover opening bracket forces a closing bracket. No later decisions can reduce these counts.

## Complexity Analysis
* **Time Complexity:** O(n), where n is the length of the string – we traverse it once.
* **Space Complexity:** O(1), only a few integer variables are used.