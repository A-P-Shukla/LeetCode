# 1967. Number of Strings That Appear as Substrings in Word

Property | Value
--- | ---
Difficulty | Easy
Topics | Array, String
Date | 2026-06-29
LeetCode Link | [/problems/number-of-strings-that-appear-as-substrings-in-word/](https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/)

### Intuition

The problem asks us to count how many strings from a given list (`patterns`) exist within a target string (`word`). Since the constraints are small (both the number of patterns and the lengths of strings are at most 100), we can iterate through each pattern and check if it is contained within `word` using standard library string-searching methods.

The mental model is a simple linear scan over the `patterns` array. For each pattern, we perform a substring search. Because we are looking for a substring (a contiguous sequence of characters), we can leverage the built-in `find` or `in` operations provided by modern programming languages, which are highly optimized.

### Complexity Analysis

*   **Time Complexity:** O(N * M * K), where N is the number of patterns, M is the length of `word`, and K is the maximum length of a pattern. For each of the N patterns, we perform a string search in `word`, which typically takes O(M * K) in the worst case using naive matching. Given the constraints (all <= 100), this approach is well within the acceptable execution limits.
*   **Space Complexity:** O(1), as we are only using a counter variable to track the number of matches and are not allocating any significant additional data structures that scale with the input size.