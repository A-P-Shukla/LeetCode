# 1871. Jump Game VII

### Property | Value
--- | ---
Difficulty | Medium
Topics | String, Dynamic Programming, Sliding Window, Prefix Sum
Date | May 25, 2026
LeetCode Link | [Jump Game VII](https://leetcode.com/problems/jump-game-vii/)

---

### Intuition

The problem asks whether we can reach the last index of a binary string `s` starting from index `0`. We can only jump from a reachable index `i` to index `j` if `s[j] == '0'` and the distance between them is bounded by `[minJump, maxJump]`.

A naive Dynamic Programming (DP) or Breadth-First Search (BFS) approach checking all valid transitions for each index would take $O(n \cdot (maxJump - minJump))$ time, which can be up to $O(n^2)$ and will result in a Time Limit Exceeded (TLE) error since $n \le 10^5$.

To achieve $O(n)$ time complexity, we can use **Dynamic Programming with a Sliding Window (or Prefix Sum)**:
1. Let `dp[i]` be `true` if index `i` is reachable.
2. An index `i` is reachable if `s[i] == '0'` and there exists at least one reachable index `j` in the range $[i - maxJump, i - minJump]$.
3. Instead of scanning this range for every index `i`, we can maintain a running count of reachable indices (`reachable_count`) inside the sliding window $[i - maxJump, i - minJump]$:
   * As the window shifts to the right for a new index `i`, we include `dp[i - minJump]` in our count.
   * We remove `dp[i - maxJump - 1]` from our count (if it exists).
   * If `reachable_count > 0` and `s[i] == '0'`, then `dp[i] = true`.

This optimization reduces the transition step to $O(1)$, resulting in an optimal $O(n)$ overall runtime.

---

### Complexity Analysis

- **Time Complexity:** $O(n)$ where $n$ is the length of the string `s`. We iterate through the string exactly once, and each state update/sliding window adjustment takes $O(1)$ time.
- **Space Complexity:** $O(n)$ to store the DP array.

---