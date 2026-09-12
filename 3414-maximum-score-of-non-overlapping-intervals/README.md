# Maximum Score of Non-Overlapping Intervals

| Property | Value |
| --- | --- |
| Difficulty | Hard |
| Topics | Array, Binary Search, Dynamic Programming, Sorting |
| Date | September 12, 2026 |
| LeetCode Link | [Maximum Score of Non-Overlapping Intervals](https://leetcode.com/problems/maximum-score-of-non-overlapping-intervals/) |

## Intuition

The problem asks us to select **at most 4 non-overlapping intervals** to maximize the sum of their weights. If multiple subsets of intervals yield the maximum total score, we must return the set of original indices that is **lexicographically smallest** when sorted in ascending order.

This is a variation of the classic **Weighted Interval Scheduling** problem, restricted to choosing at most $K = 4$ intervals.

1. **Sorting and Next Non-Overlapping Interval**:
   By sorting the intervals by their start times $l_i$, we can process them sequentially. For any interval $i$ ending at $r_i$, the next interval we can choose must start at $l_j > r_i$. Because the array is sorted by start time, we can locate the first valid non-overlapping interval index `next_idx` using **Binary Search** (`std::upper_bound` in C++ or `bisect_right` in Python).

2. **Dynamic Programming State**:
   We can define a suffix DP state:
   - `dp[k][i]` represents the best outcome (maximum score and lexicographically smallest index array) achievable by choosing **at most $k$ non-overlapping intervals** from the suffix of sorted intervals starting from index $i$ to $N-1$.

3. **Transitions**:
   At index $i$ for $k$ intervals, we have two choices:
   - **Skip interval $i$**: The state transitions to `dp[k][i + 1]`.
   - **Take interval $i$**: The score increases by $weight_i$, and the remaining capacity becomes $k - 1$ starting at `next_idx`. The state transitions to `weight_i + dp[k - 1][next_idx].score`, and original index of interval $i$ is inserted into `dp[k - 1][next_idx].indices` maintaining sorted order.

4. **Lexicographical Tie-Breaking**:
   A key property of lexicographical ordering on sorted index lists is that inserting a constant element $x$ into two sorted arrays $V_1$ and $V_2$ preserves their relative order: $V_1 < V_2 \iff \text{insert}(V_1, x) < \text{insert}(V_2, x)$. This guarantees that optimal substructure holds even when breaking ties lexicographically!

Since $K \le 4$, we can optimize space by keeping track of only two DP rows (current $k$ and previous $k - 1$).

## Complexity Analysis

- **Time Complexity:** 
  - **Sorting:** $\mathcal{O}(N \log N)$ to sort $N$ intervals by start time.
  - **DP Transitions:** We run $K = 4$ outer iterations. In each iteration, we loop through $N$ intervals and perform a binary search in $\mathcal{O}(\log N)$ time. Inserting/comparing small index vectors of length $\le 4$ takes $\mathcal{O}(1)$ time.
  - **Total Time Complexity:** $\mathcal{O}(K \cdot N \log N) = \mathcal{O}(N \log N)$, which comfortably runs within the time limit for $N \le 50,000$.

- **Space Complexity:** 
  - Storing the mapped interval structure takes $\mathcal{O}(N)$ space.
  - Space-optimized DP table uses 2 rows of size $N + 1$, where each entry stores a score and a vector of length $\le 4$.
  - **Total Space Complexity:** $\mathcal{O}(N)$.