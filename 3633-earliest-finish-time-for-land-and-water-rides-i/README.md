# 3633. Earliest Finish Time for Land and Water Rides I

### Property | Value
--- | ---
Difficulty | Easy
Topics | Array, Greedy
Date | June 2, 2026
LeetCode Link | [Earliest Finish Time for Land and Water Rides I](https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/)

## Intuition

The problem asks us to find the earliest possible time to experience exactly one land ride and exactly one water ride in either order. 

Let the chosen land ride be at index $i$ and the water ride be at index $j$. We have two options for the order of execution:
1. **Land Ride First, then Water Ride**:
   * We start the land ride at `landStartTime[i]`. It finishes at $f_{\text{land}} = \text{landStartTime}[i] + \text{landDuration}[i]$.
   * We then immediately head to the water ride. We can only start it once we arrive and once it is open. Thus, the water ride starts at $\max(f_{\text{land}}, \text{waterStartTime}[j])$.
   * It finishes at $F_1 = \max(f_{\text{land}}, \text{waterStartTime}[j]) + \text{waterDuration}[j]$.

2. **Water Ride First, then Land Ride**:
   * We start the water ride at `waterStartTime[j]`. It finishes at $f_{\text{water}} = \text{waterStartTime}[j] + \text{waterDuration}[j]$.
   * We start the land ride at $\max(f_{\text{water}}, \text{landStartTime}[i])$.
   * It finishes at $F_2 = \max(f_{\text{water}}, \text{landStartTime}[i]) + \text{landDuration}[i]$.

Since the number of land rides $n$ and water rides $m$ are both very small ($1 \le n, m \le 100$), we can simply iterate through all possible pairs $(i, j)$ of land and water rides, calculate the finish time for both orders of operations, and return the minimum finish time found.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n \times m)$, where $n$ is the number of land rides and $m$ is the number of water rides. Since $n, m \le 100$, the maximum number of iterations is $10^4$, which executes instantly (in under 1 millisecond).
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space as we only use a few variables to store intermediate results and the minimum answer.