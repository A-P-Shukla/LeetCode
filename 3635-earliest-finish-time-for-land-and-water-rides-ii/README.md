# 3635. Earliest Finish Time for Land and Water Rides II

### Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Greedy
Date | June 3, 2026
LeetCode Link | [Earliest Finish Time for Land and Water Rides II](https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/)

---

## Intuition

The problem asks us to find the earliest possible finish time to complete exactly one land ride and exactly one water ride in either order. 

Let's represent the problem mathematically. We have $n$ land rides and $m$ water rides. For any land ride $i$ and water ride $j$:
* The finish time of land ride $i$ if taken first is:  
  $$L_{\text{finish}}[i] = L_{\text{start}}[i] + L_{\text{duration}}[i]$$
* The finish time of water ride $j$ if taken first is:  
  $$W_{\text{finish}}[j] = W_{\text{start}}[j] + W_{\text{duration}}[j]$$

If we choose the order **Land Ride $\to$ Water Ride**:
1. Land ride $i$ finishes at $L_{\text{finish}}[i]$.
2. Water ride $j$ starts at $\max(W_{\text{start}}[j], L_{\text{finish}}[i])$.
3. It finishes at $\max(W_{\text{start}}[j], L_{\text{finish}}[i]) + W_{\text{duration}}[j]$.
   Using the distributive property of addition over $\max$, this simplifies to:
   $$T_1(i, j) = \max(W_{\text{finish}}[j], L_{\text{finish}}[i] + W_{\text{duration}}[j])$$

Notice that for any fixed water ride $j$, the value of $T_1(i, j)$ is minimized when $L_{\text{finish}}[i]$ is minimized. Since this choice of land ride $i$ is independent of $j$, the optimal land ride to ride first is always the one that finishes earliest overall:
$$L_{\text{fin\_min}} = \min_{i} L_{\text{finish}}[i]$$

By symmetry, if we choose the order **Water Ride $\to$ Land Ride**:
The optimal water ride to ride first is always the one that finishes earliest overall:
$$W_{\text{fin\_min}} = \min_{j} W_{\text{finish}}[j]$$

Thus, we can find the minimum finish time for both orderings:
1. **Land $\to$ Water**: Pick the best land ride $i$ (which minimizes $L_{\text{finish}}[i]$) and check all water rides $j$.
2. **Water $\to$ Land**: Pick the best water ride $j$ (which minimizes $W_{\text{finish}}[j]$) and check all land rides $i$.

The answer is the minimum of these two cases. This simplifies the search space from $O(n \times m)$ to $O(n + m)$.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n + m)$
  - Finding $L_{\text{fin\_min}}$ and $W_{\text{fin\_min}}$ takes $\mathcal{O}(n)$ and $\mathcal{O}(m)$ respectively.
  - Evaluating the two configurations takes $\mathcal{O}(m)$ and $\mathcal{O}(n)$ respectively.
  - Overall time complexity is linear in terms of the size of the inputs.

- **Space Complexity:** $\mathcal{O}(1)$
  - No additional data structures are allocated. All calculations are carried out in-place using constant extra space.

---