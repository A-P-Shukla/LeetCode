# 1477. Find Two Non-overlapping Sub-arrays Each With Target Sum

### Metadata Table
Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Hash Table, Binary Search, Dynamic Programming, Sliding Window
Date | September 17, 2026
LeetCode Link | [Find Two Non-overlapping Sub-arrays Each With Target Sum](https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/)

---

### Intuition

The problem requires us to find two **non-overlapping** sub-arrays, each summing up to a given `target`, such that the sum of their lengths is minimized.

Since all numbers in `arr` are strictly positive integers ($arr[i] \ge 1$), any sub-array sum increases monotonically as we expand its right boundary. This allows us to find all sub-arrays with a sum equal to `target` in linear time using a **Sliding Window / Two-Pointer** approach.

To find two non-overlapping sub-arrays:
1. As we iterate through the array with a right pointer `r` and maintain a left pointer `l`, whenever `current_sum == target`, we identify a valid sub-array spanning from index `l` to `r` of length `curr_len = r - l + 1`.
2. To ensure non-overlapping pairs, we need to quickly find the shortest valid sub-array that **ends strictly before index `l`** (i.e., at or before `l - 1`).
3. We can maintain a dynamic programming array `min_len`, where `min_len[i]` represents the minimum length of a target sub-array found within `arr[0...i]`.
4. Whenever we discover a valid sub-array `[l, r]`:
   - If a valid sub-array exists prior to index `l` (checked via `min_len[l - 1]`), the combined length of these two non-overlapping sub-arrays is `curr_len + min_len[l - 1]`. We update our global minimum answer with this value.
   - We then update `min_len[r]` to be `min(min_len[r - 1], curr_len)` to carry forward the best sub-array length found so far.

---

### Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the number of elements in `arr`. Both the left and right pointers traverse the array at most once, and dynamic programming lookups/updates run in $\mathcal{O}(1)$ per step.
- **Space Complexity:** $\mathcal{O}(N)$ to store the DP array `min_len` of size $N$.

---