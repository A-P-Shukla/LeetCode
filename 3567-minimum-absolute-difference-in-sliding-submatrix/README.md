# 3567. Minimum Absolute Difference in Sliding Submatrix

Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Sorting, Matrix
Date | March 20, 2026
LeetCode Link | [https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/](https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/)

### Intuition

The problem asks us to find the minimum absolute difference between any two distinct values within every possible $k \times k$ sliding submatrix of a given $m \times n$ grid. 

Given the constraints ($m, n \leq 30$), the total number of submatrices is relatively small (at most $30 \times 30 = 900$). Each submatrix contains $k^2$ elements (at most 900). Because the search space is small, a simulation-based approach is highly efficient.

For each submatrix:
1. **Extraction**: Collect all elements within the $k \times k$ boundaries.
2. **Deduplication and Sorting**: We need the difference between *distinct* values. By storing these elements in a sorted collection and removing duplicates, we can simply compare adjacent elements to find the minimum difference.
3. **Edge Case**: If a submatrix contains only one distinct value (all elements are the same), the problem specifies the answer is 0.

A `std::set` or a sorted `std::vector` with `std::unique` are both suitable for this task. Given the small $k$, a vector is often faster due to cache locality.

### Complexity Analysis

- **Time Complexity**: $O((m-k+1) \cdot (n-k+1) \cdot k^2 \log(k^2))$
  - There are $O(m \cdot n)$ submatrices.
  - For each submatrix, we process $k^2$ elements.
  - Sorting takes $O(k^2 \log k^2)$.
  - With $m, n, k \leq 30$, the total operations are approximately $900 \times 900 \times \log(900) \approx 8 \times 10^6$, which comfortably passes within the time limit.

- **Space Complexity**: $O(m \cdot n)$
  - We store the result in a 2D array of size $(m-k+1) \times (n-k+1)$.
  - Temporary storage for each submatrix elements takes $O(k^2)$ space.