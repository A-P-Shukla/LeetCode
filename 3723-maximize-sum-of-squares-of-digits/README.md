# 3723. Maximize Sum of Squares of Digits

Metadata Table:
Property | Value
--- | ---
Difficulty | Medium
Topics | Math, Greedy
Date | 2026-10-14
LeetCode Link | https://leetcode.com/problems/maximize-sum-of-squares-of-digits/

## Intuition
For a fixed total digit sum, the sum of squares grows faster when the sum is concentrated in larger digits because  

\[
(a+b)^2 > a^2 + b^2 \quad\text{for } a,b>0 .
\]

Hence, to obtain the *maximum score* we should make the digits as large as possible, pushing the value 9 to the most‑significant positions first.  
If several digit arrangements give the same score (they are just permutations of the same multiset), the required answer is the **largest integer**, i.e. the digits must be in non‑increasing order.  

Consequently we can build the answer digit‑by‑digit from left to right, always choosing the biggest digit that still allows the remaining positions to satisfy the sum constraint.

Feasibility test for a candidate digit `d` at position `i`:

* `remaining = sum - d`
* `positions_left = num - i - 1`
* It must hold `0 ≤ remaining ≤ 9 * positions_left`.

For the leading digit we also enforce `d ≥ 1` (a number cannot start with zero).  
If at any step no digit satisfies the condition, the whole task is impossible.

The construction runs in linear time with respect to `num`, which is up to 2·10⁵, easily fast enough.

## Complexity Analysis
*Time*: `O(num)` – one pass over all positions, each trying at most 10 digit values.  
*Space*: `O(num)` – the output string (no extra auxiliary structures).