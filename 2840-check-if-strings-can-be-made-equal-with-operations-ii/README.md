# 2840. Check if Strings Can be Made Equal With Operations II

Property | Value
--- | ---
Difficulty | Medium
Topics | Hash Table, String, Sorting, Counting
Date | March 30, 2026
LeetCode Link | [https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/](https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/)

### Intuition

The core of this problem lies in understanding the constraints imposed by the allowed operation. We can swap characters at indices `i` and `j` only if the difference `j - i` is even. This parity constraint divides the indices of the string into two disjoint sets:
1.  **Even Indices:** {0, 2, 4, ...}
2.  **Odd Indices:** {1, 3, 5, ...}

Characters at even indices can be moved to any other even index through a series of swaps, but they can *never* move to an odd index. The same logic applies to characters at odd indices.

Consequently, for `s1` to be transformed into `s2`, the following two conditions must be met:
-   The multiset of characters at even indices in `s1` must be identical to the multiset of characters at even indices in `s2`.
-   The multiset of characters at odd indices in `s1` must be identical to the multiset of characters at odd indices in `s2`.

The most efficient way to verify if two multisets are identical is to use a frequency count (hash map or a fixed-size array for the alphabet).

### Complexity Analysis

-   **Time Complexity:** $O(N + \Sigma)$, where $N$ is the length of the strings and $\Sigma$ is the size of the alphabet (26). We perform a single pass over the strings to count character frequencies and then a constant-time check over the frequency arrays.
-   **Space Complexity:** $O(\Sigma)$, which simplifies to $O(1)$ as the alphabet size is constant. We only store counts for the 26 lowercase English letters.
