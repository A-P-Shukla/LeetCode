# 3130. Find All Possible Stable Binary Arrays II

Property | Value
--- | ---
Difficulty | Hard
Topics | Dynamic Programming, Prefix Sum
Date | March 10, 2026
LeetCode Link | [Find All Possible Stable Binary Arrays II](https://leetcode.com/problems/find-all-possible-stable-binary-arrays-ii/)

## Intuition

The problem asks us to count the number of binary arrays with a specific count of zeros and ones, such that no contiguous block of identical digits exceeds a given `limit`. This is a classic combinatorial problem that can be modeled using Dynamic Programming.

Let $dp[i][j][k]$ represent the number of stable binary arrays containing exactly $i$ zeros and $j$ ones, where the last digit placed is $k \in \{0, 1\}$.

### Naive DP Approach
To find $dp[i][j][0]$ (ending in 0), we could look at all valid sequences ending in 1 and append a block of zeros of length $1 \le len \le limit$:
$dp[i][j][0] = \sum_{k=1}^{\min(i, limit)} dp[i-k][j][1]$

Similarly for ones:
$dp[i][j][1] = \sum_{k=1}^{\min(j, limit)} dp[i][j-k][0]$

The constraints for `zero` and `one` are up to 1000. A naive $O(zero \cdot one \cdot limit)$ solution would result in $10^9$ operations, which is too slow.

### Optimization using Prefix Sums
We can optimize the summation to $O(1)$ by observing the relationship between $dp[i][j][0]$ and $dp[i-1][j][0]$.
Using $dp[i][j][0] = \sum_{k=1}^{limit} dp[i-k][j][1]$:
$dp[i][j][0] = dp[i-1][j][1] + dp[i-2][j][1] + \dots + dp[i-limit][j][1]$
$dp[i-1][j][0] = dp[i-2][j][1] + dp[i-3][j][1] + \dots + dp[i-limit-1][j][1]$

Subtracting these two equations gives:
$dp[i][j][0] - dp[i-1][j][0] = dp[i-1][j][1] - dp[i-limit-1][j][1]$
Rearranging:
$dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1] - dp[i-limit-1][j][1]$

This allows us to compute each state in $O(1)$ time, reducing the total complexity to $O(zero \cdot one)$.

## Complexity Analysis
- **Time Complexity**: $O(\text{zero} \cdot \text{one})$, as we iterate through a 2D table of size `zero` $\times$ `one` and perform constant time operations at each step.
- **Space Complexity**: $O(\text{zero} \cdot \text{one})$ to store the DP table. Given the constraints (1000x1000), this fits within standard memory limits.