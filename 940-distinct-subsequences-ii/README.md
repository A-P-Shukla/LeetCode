# 94
0. Distinct Subsequences II

Property | Value
--- | ---
Difficulty | Hard
Topics | String, Dynamic Programming
Date | September 7, 2026
LeetCode Link | https://leetcode.com/problems/distinct-subsequences-ii/

## Intuition

When processing the characters of a string one by one, each new character `c` can be appended to all previously generated distinct subsequences (including the empty sequence) to form new subsequences ending with `c`.

Let's maintain the count of distinct non-empty subsequences ending with each character of the alphabet. 
- Suppose we have an array `ends_with` of size 26, where `ends_with[ch]` stores the number of distinct subsequences that end with the character `ch`.
- When encountering a character `c`, we can append `c` to any existing valid subsequence, or form the single-character subsequence `"c"`.
- Therefore, the new total number of distinct subsequences ending in `c` becomes:
  $$\text{ends\_with}[c] = 1 + \sum_{k=0}^{25} \text{ends\_with}[k]$$
- Notice that this automatically replaces the previous value of `ends_with[c]`. By overwriting it, we avoid double-counting duplicate subsequences created by earlier occurrences of character `c`.

The final answer is simply the sum of all values in `ends_with` modulo $10^9 + 7$.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N \cdot |\Sigma|)$ where $N$ is the length of string `s` and $|\Sigma| = 26$ is the size of the English alphabet. This can also be optimized to $\mathcal{O}(N)$ by maintaining a running sum of all elements in `ends_with`.
- **Space Complexity:** $\mathcal{O}(|\Sigma|) = \mathcal{O}(1)$ since the state array only requires 26 entries regardless of the length of the string.