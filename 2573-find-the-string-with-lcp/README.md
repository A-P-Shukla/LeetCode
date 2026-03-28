# 2573. Find the String with LCP

Property | Value
--- | ---
Difficulty | Hard
Topics | Array, String, Dynamic Programming, Greedy, Union-Find, Matrix
Date | March 28, 2026
LeetCode Link | [https://leetcode.com/problems/find-the-string-with-lcp/](https://leetcode.com/problems/find-the-string-with-lcp/)

### Intuition
The core of this problem lies in understanding the constraints imposed by the Longest Common Prefix (LCP) matrix. By definition, `lcp[i][j]` is the length of the longest common prefix of suffixes starting at `i` and `j`. This implies:
1. If `lcp[i][j] > 0`, then `word[i]` must equal `word[j]`.
2. If `lcp[i][j] == 0`, then `word[i]` must not equal `word[j]`.
3. The matrix must be consistent with the recursive property: if `word[i] == word[j]`, then `lcp[i][j] = 1 + lcp[i+1][j+1]` (with appropriate boundary checks).

To find the **lexicographically smallest** string, we use a greedy approach. We iterate through the indices from $0$ to $n-1$. For every unassigned index, we assign the smallest available character ('a' through 'z'). If we find an index $i$ that should have a character, we propagate that character to all indices $j$ where `lcp[i][j] > 0`.

Since the greedy step only considers the necessity of equality, we must perform a secondary validation step. We reconstruct the LCP matrix for our candidate string using Dynamic Programming and compare it against the input matrix to ensure all constraints (including inequalities and specific prefix lengths) are satisfied.

### Complexity Analysis
- **Time Complexity:** $O(n^2)$, where $n$ is the length of the string. The greedy construction takes $O(n^2)$ and the dynamic programming verification takes $O(n^2)$.
- **Space Complexity:** $O(n)$, if we only store the generated string, or $O(n^2)$ if we treat the input matrix as our DP table or create a new one for verification. Given $n = 1000$, $O(n^2)$ space is well within limits.