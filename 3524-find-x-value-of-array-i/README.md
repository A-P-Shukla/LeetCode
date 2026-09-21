# Find the X-Value of Array

## Metadata Table

Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Dynamic Programming, Math, Prefix Sum
Date | September 21, 2026
LeetCode Link | https://leetcode.com/problems/find-the-x-value-of-array/

---

## Intuition

The problem asks for the number of ways to remove a non-overlapping prefix and suffix from `nums` such that the remaining elements form a non-empty subarray with a product congruent to $x \pmod k$, for each $x \in [0, k-1]$.

Removing a prefix of length $i$ and a suffix of length $n - 1 - j$ leaves a non-empty subarray `nums[i..j]` where $0 \le i \le j < n$. Thus, the problem reduces to counting the number of contiguous, non-empty subarrays whose product modulo $k$ equals $x$.

Since $k$ is extremely small ($1 \le k \le 5$), we can maintain a Dynamic Programming state that tracks the number of subarrays ending at the current index $j$ for each possible remainder modulo $k$. 

For each element `nums[j]`:
1. Calculate its remainder `val = nums[j] % k`.
2. A single-element subarray `nums[j..j]` contributes 1 to remainder `val`.
3. Any existing subarray ending at index $j-1$ with product modulo $k$ equal to `prev_x` will have a new product modulo $k$ equal to `(prev_x * val) % k` when extended to include `nums[j]`.
4. We accumulate these frequencies into our global result array and update our state for the next iteration.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n \cdot k)$ where $n$ is the length of `nums` and $k$ is the given modulo integer. Since $k \le 5$, the loop runs in constant time for each element, resulting in an effective runtime of $\mathcal{O}(n)$.
- **Space Complexity:** $\mathcal{O}(k)$ auxiliary space to store the DP array of counts for remainders from $0$ to $k-1$. Since $k \le 5$, this is equivalent to $\mathcal{O}(1)$ extra space.

---