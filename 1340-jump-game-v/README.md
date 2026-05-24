# 1340. Jump Game V

| Property | Value |
|---|---|
| Difficulty | Hard |
| Topics | Array, Dynamic Programming, Sorting |
| Date | May 24, 2026 |
| LeetCode Link | [Jump Game V](https://leetcode.com/problems/jump-game-v/) |

## Intuition

The problem asks us to find the maximum number of indices we can visit starting from any index in the array. Since we can only jump from index `i` to index `j` if `arr[i] > arr[j]` and all intermediate elements are also strictly smaller than `arr[i]`, we can never jump from a smaller value to a larger or equal value. This ensures that the choices form a **Directed Acyclic Graph (DAG)**. 

Because the relationship is acyclic (you can only go "downhill"), this is a classic candidate for **Dynamic Programming with Memoization (Top-Down DP)**:
1. Let `dp[i]` be the maximum number of indices we can visit starting at index `i`.
2. To calculate `dp[i]`, we can try jumping to any valid index `j` to the right (up to distance `d`) or to the left (up to distance `d`).
3. For a jump to be valid, every step we take towards `j` must be strictly smaller than `arr[i]`. If we hit any index `k` where `arr[k] >= arr[i]`, it acts as a "wall." We cannot jump to `k` or any element beyond `k` in that direction.
4. The transitions are:
   $$dp[i] = 1 + \max(dp[j])$$ for all valid destination indices $j$.
5. The overall answer will be $\max(dp[i])$ for all $0 \le i < n$.

Using memoization prevents redundant computations, ensuring each index is fully processed exactly once.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N \cdot d)$
  There are $N$ unique states (indices). For each state, we scan up to $d$ elements to the right and $d$ elements to the left to find valid jumps. This gives a total time complexity of $\mathcal{O}(N \cdot d)$. With $N, d \le 1000$, the maximum number of operations is roughly $2 \times 10^6$, which runs in just a few milliseconds.
  
- **Space Complexity:** $\mathcal{O}(N)$
  The memoization table (or recursion cache) and the recursive call stack both use $\mathcal{O}(N)$ space.
