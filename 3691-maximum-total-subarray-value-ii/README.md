# 3691. Maximum Total Subarray Value II

### Metadata Table
Property | Value
--- | ---
Difficulty | Hard
Topics | Array, Binary Search, Monotonic Stack, Two Pointers, Greedy
Date | June 10, 2026
LeetCode Link | [Maximum Total Subarray Value II](https://leetcode.com/problems/maximum-total-subarray-value-ii/)

## Intuition

The problem asks us to find the maximum possible sum of values of exactly $k$ distinct subarrays, where the value of a subarray is defined as its maximum minus its minimum.

Since $k$ can be up to $10^5$, and $n$ can be up to $5 \cdot 10^4$, we cannot compute the values of all possible $O(n^2)$ subarrays and sort them. However, we can use **Binary Search on the Answer** to find the value of the $k$-th largest subarray.

### 1. Binary Search for the Threshold $X$
Let $X$ be a candidate threshold value. If we can quickly count how many subarrays have a value (i.e., $\max - \min$) $\ge X$, we can binary search the optimal threshold $X$. 
- The difference $\max(nums[l..r]) - \min(nums[l..r])$ is **monotonic** with respect to the right boundary $r$. As $r$ increases, the window expands, making the maximum non-decreasing and the minimum non-increasing. Consequently, the difference is non-decreasing.
- For each left index $l$, there exists a minimum right index $R[l]$ such that the subarray $nums[l..R[l]]$ has a value $\ge X$.
- Using a **Two-Pointer (Sliding Window)** approach with two monotonic queues (one for maintaining the maximum and one for the minimum), we can find $R[l]$ for all $l$ in $O(n)$ time.
- The total number of subarrays starting at $l$ with value $\ge X$ is then $n - R[l]$ (if $R[l] < n$).
- We can find the largest threshold $X \in [0, 10^9]$ such that the count of subarrays with value $\ge X$ is at least $k$.

### 2. Summing the Values of Subarrays $\ge Y$
Once we find the threshold $X$:
1. The subarrays with value $\ge X+1$ are strictly in our top-$k$ collection. Let their count be $C_{next}$.
2. The remaining $k - C_{next}$ subarrays will have value exactly equal to $X$.
3. We need to sum up the actual values of all subarrays with value $\ge Y = X + 1$.

To compute the sum of values of all subarrays with value $\ge Y$ in $O(n \log n)$ time, we can calculate the contribution of each element $nums[i]$ as the maximum and as the minimum of the subarrays:
- Using a **Monotonic Stack**, we precompute the boundaries for each element $i$ as:
  - The maximum: $l \in [PL[i] + 1, i]$ and $r \in [i, PR[i] - 1]$.
  - The minimum: $l \in [QL[i] + 1, i]$ and $r \in [i, QR[i] - 1]$.
- For a fixed element $i$ as maximum, we need to sum its contribution over all valid $l$ and $r$ such that $r \ge R[l]$.
- Since $R[l]$ is non-decreasing, we can use binary search (`std::upper_bound`) to partition the interval of $l$ into segments where $R[l] \le i$ (where the contribution is constant) and $R[l] > i$ (where we can use prefix sums of $R$ to compute the summation in $O(1)$).
- Summing these up gives us the exact total sum of values of all subarrays with value $\ge Y$ in $O(n \log n)$ time.

---

## Complexity Analysis

- **Time Complexity:** 
  - **Binary Search Phase:** We perform $O(\log(\max\_val))$ steps. In each step, we find $R[l]$ using a sliding window with monotonic queues in $O(n)$ time. This phase takes $O(n \log(\max\_val))$ time.
  - **Summation Phase:** Finding the monotonic stack boundaries takes $O(n)$ time. For the chosen threshold $Y$, we perform $O(n)$ binary searches to compute the prefix-sum based contribution of each element, taking $O(n \log n)$ time.
  - **Total Time Complexity:** $\mathcal{O}(n \log(\max\_val) + n \log n)$, which is extremely fast and easily passes within the time limit.

- **Space Complexity:** $\mathcal{O}(n)$ to store the helper arrays ($PL, PR, QL, QR, R$) and the monotonic deques.