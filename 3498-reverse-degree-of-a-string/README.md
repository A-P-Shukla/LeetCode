# Calculate Reverse Degree of a String

Property | Value
--- | ---
Difficulty | Easy
Topics | String, Simulation, Math
Date | September 20, 2026
LeetCode Link | https://leetcode.com/problems/calculate-reverse-degree-of-a-string/

## Intuition

The problem asks us to evaluate a weighted sum over all characters of a string $s$. Each character contributes a value that depends on two factors:
1. **Reversed Alphabet Rank**: The letter `'a'` maps to $26$, `'b'` to $25$, down to `'z'` mapping to $1$. Mathematically, for any lowercase English letter $c$, this rank can be calculated as:
   $$\text{Rank}(c) = 26 - (c - \text{'a'}) = \text{'z'} - c + 1$$
2. **String Position**: The 1-based index of the character within the string (i.e., $1, 2, \dots, n$).

For each character at index $i$ ($0$-indexed), its position in the string is $i + 1$. We multiply this position by the character's reversed alphabet rank and accumulate these products to obtain the total reverse degree.

Since the constraints specify a maximum string length of $1,000$, a single linear scan is completely optimal and straightforward to implement.

## Complexity Analysis

- **Time Complexity:** $O(n)$, where $n$ is the length of the string $s$. We perform a single pass through the string, performing $O(1)$ arithmetic operations for each character.
- **Space Complexity:** $O(1)$ auxiliary space, as only a few scalar variables are maintained to keep track of the running sum and indices.