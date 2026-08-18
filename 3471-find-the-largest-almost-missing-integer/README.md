# 3471. Find the Largest Almost Missing Integer

### Metadata Table
Property | Value
--- | ---
Difficulty | Easy
Topics | Array, Hash Table
Date | August 18, 2026
LeetCode Link | [Find the Largest Almost Missing Integer](https://leetcode.com/problems/find-the-largest-almost-missing-integer/)

---

### Intuition

The problem asks us to find the largest integer that appears in **exactly one** subarray of size $k$ in `nums`. Instead of simulating and counting subarrays for all elements (which takes $O(N \cdot k)$ or $O(N^2)$ time), we can analyze the structural properties of subarrays based on the value of $k$:

1. **Case 1 ($k = 1$):**
   Subarrays of size 1 are just individual elements of the array. An element appears in exactly one subarray of size 1 if and only if its total frequency in `nums` is exactly 1. We can just count the global frequencies and return the maximum element with a frequency of 1.

2. **Case 2 ($k = N$):**
   There is only one subarray of size $N$ (the entire array). Therefore, every unique element present in the array appears in exactly this one subarray. The answer is simply the maximum element in `nums`.

3. **Case 3 ($1 < k < N$):**
   Any element located at an index $i$ in the middle ($0 < i < N - 1$) is guaranteed to be covered by at least 2 overlapping subarrays of size $k$. 
   Thus, the only elements that can possibly appear in exactly one subarray of size $k$ are the boundary elements: the first element `nums[0]` and the last element `nums[N-1]`.
   - `nums[0]` is "almost missing" if and only if it is globally unique in the entire array.
   - `nums[N-1]` is "almost missing" if and only if it is globally unique in the entire array.
   
   If either (or both) are globally unique, our answer is the maximum of those unique boundary values. Otherwise, no such element exists, and we return `-1`.

---

### Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$. We count the frequencies of all elements in the array in a single pass, and then perform constant-time checks on the boundaries.
- **Space Complexity:** $\mathcal{O}(U)$ where $U$ is the number of unique elements in `nums` (at most $N$). This is used for the frequency map. Since $N \le 50$, the auxiliary space is effectively $\mathcal{O}(1)$.

---