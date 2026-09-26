# 1807. Evaluate the Bracket Pairs of a String

Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Hash Table, String
Date | 2026-09-26
LeetCode Link | https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/

## Intuition
The string contains independent bracket pairs – no nesting – so each pair can be processed independently in a single left‑to‑right scan.  
1. Store all `(key, value)` pairs from `knowledge` in a hash map for O(1) look‑ups.  
2. Walk through `s`.  
   * If the current character is not `'('`, it belongs to the final answer unchanged.  
   * When `'('` is seen, find the matching `')'` (the next `')'` because there is no nesting), extract the key between them, and replace the whole `(key)` with the mapped value or `"?"` if the key is unknown.  
3. Append everything to a result string.

Because each character is visited at most once and each lookup is O(1), the algorithm is linear in the length of `s`.

## Complexity Analysis
- **Time:** O(|s| + |knowledge|) – one pass to build the map and one pass to build the answer.  
- **Space:** O(|knowledge| + |answer|) – hash map for knowledge and the output string.