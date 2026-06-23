# 3699. Number of ZigZag Arrays I

| Property | Value |
| --- | --- |
| Difficulty | Hard |
| Topics | Dynamic Programming, Prefix Sum |
| Date | 2026-06-23 |
| LeetCode Link | [Number of ZigZag Arrays I](https://leetcode.com/problems/number-of-zigzag-arrays-i/) |

### Intuition

A ZigZag array must satisfy two constraints regarding the relationship between adjacent elements:
1. No two adjacent elements are equal ($a_i \neq a_{i+1}$).
2. No three consecutive elements are monotonic. This means if $a_{i-1} < a_i$, then $a_i > a_{i+1}$ (must go down), and if $a_{i-1} > a_i$, then $a_i < a_{i+1}$ (must go up).

Let $S = r - l + 1$ be the number of possible values. We can define a DP state: `dp[i][val][state]`, where:
- `i` is the current index in the array (from $0$ to $n-1$).
- `val` is the value assigned to `arr[i]` (mapped from $l$ to $r$).
- `state` represents the relationship between `arr[i-1]` and `arr[i]`:
    - `0`: `arr[i-1] < arr[i]` (the last step was up).
    - `1`: `arr[i-1] > arr[i]` (the last step was down).

If the last step was `up` (state 0), the next step *must* be `down`. So for `i+1`, we need `arr[i+1] < arr[i]`.
If the last step was `down` (state 1), the next step *must* be `up`. So for `i+1`, we need `arr[i+1] > arr[i]`.

This structure allows us to use prefix sums to optimize the transition from $O(S^2)$ to $O(S)$ per index. Specifically, if we are at `dp[i][curr_val][0]`, we need to sum `dp[i-1][prev_val][1]` for all `prev_val > curr_val`. This can be done efficiently using precomputed suffix/prefix sums of the previous DP layer.

### Complexity Analysis

- **Time Complexity:** $O(n \cdot S)$, where $S = r - l + 1$. For each of the $n$ positions, we update the DP states for $S$ possible values. The prefix/suffix sum optimization allows calculating these updates in constant time per state. Given $n, S \leq 2000$, $O(n \cdot S) \approx 4 \times 10^6$, which fits well within the time limits.
- **Space Complexity:** $O(n \cdot S)$ to store the DP table. This can be optimized to $O(S)$ by only keeping the current and previous DP rows, but $O(n \cdot S)$ is acceptable under the constraints.