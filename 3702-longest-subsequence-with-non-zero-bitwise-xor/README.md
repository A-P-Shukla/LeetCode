# Longest Subsequence With Non-Zero Bitwise XOR

### Metadata Table
Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Math, Bit Manipulation
Date | August 15, 2026
LeetCode Link | https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/

---

### Intuition

The bitwise XOR operation has a key property: for any subset of numbers with XOR sum $S$, removing a single element $x$ from the subset results in a new XOR sum of $S \oplus x$.

Let $S$ be the total XOR sum of all elements in `nums` and $n$ be the total number of elements:

1. **All elements are zero:** If every element in the array is `0`, any non-empty subsequence will only contain zeros, resulting in an XOR sum of `0`. Thus, no valid subsequence exists, and the answer is `0`.
2. **Total XOR sum $S \neq 0$:** The entire array of length $n$ is itself a subsequence with a non-zero XOR sum. The maximum possible length is therefore $n$.
3. **Total XOR sum $S = 0$ (and at least one non-zero element exists):** 
   - The entire array of length $n$ cannot be chosen because its XOR sum is $0$.
   - However, if we remove any non-zero element $x$ from the array, the XOR sum of the remaining $n - 1$ elements becomes $S \oplus x = 0 \oplus x = x \neq 0$.
   - Thus, a valid subsequence of length $n - 1$ is always achievable.

---

### Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n)$, where $n$ is the length of `nums`. We perform a single pass over the array to compute the cumulative XOR sum and verify if any element is non-zero.
- **Space Complexity:** $\mathcal{O}(1)$, as only a few scalar variables are used.

---