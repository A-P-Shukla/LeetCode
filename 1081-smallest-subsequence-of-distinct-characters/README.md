# 1081. Smallest Subsequence of Distinct Characters

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | String, Stack, Greedy, Monotonic Stack |
| Date | 2026-07-19 |
| LeetCode Link | https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/ |

### Intuition

The goal is to pick each unique character from the input string exactly once while maintaining a lexicographical order that is as small as possible. 

This problem is a classic application of a **Monotonic Stack**. To achieve the lexicographically smallest result, we want smaller characters to appear as early as possible in our output sequence. As we iterate through the string, we maintain a stack of characters that represent our current subsequence.

For every character `c` in the string:
1. **Check for existence:** If `c` is already in our stack, we skip it because we need each character only once, and we assume we have already found an optimal position for it.
2. **Maintain monotonicity:** If the current character `c` is smaller than the character at the top of the stack, we can potentially achieve a smaller lexicographical result by popping the top character—*but only if* that popped character appears again later in the string.
3. **Track frequency:** To know if a character will appear later, we pre-calculate the last index of every character in the string. If the character at the top of the stack has a last index greater than our current position, it is safe to remove it and add it back later.

By using a `visited` set (or boolean array) to keep track of characters currently in the stack and a `last_occurrence` map, we ensure an efficient $O(N)$ traversal.

### Complexity Analysis

*   **Time Complexity:** $O(N)$, where $N$ is the length of the string. We iterate through the string once to map the last occurrences, and then iterate again to build the stack. Each character is pushed and popped from the stack at most once.
*   **Space Complexity:** $O(K)$, where $K$ is the size of the alphabet (constant 26 in this case). We store the frequency/last index map, the `visited` set, and the stack, all of which are bounded by the number of unique characters in the input.