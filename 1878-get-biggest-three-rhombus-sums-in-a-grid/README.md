# 1878. Get Biggest Three Rhombus Sums in a Grid

Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Math, Sorting, Matrix, Prefix Sum
Date | May 23, 2024
LeetCode Link | [https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/](https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/)

### Intuition
The problem asks for the three largest distinct "rhombus sums" in a grid. A rhombus is defined by a center $(r, c)$ and a radius $k$. When $k=0$, the rhombus is a single cell. When $k > 0$, the rhombus is the border of a square rotated 45 degrees.

Given the constraints ($m, n \le 50$), the total number of possible rhombuses is relatively small. We can iterate through every possible cell $(r, c)$ as a potential center and every possible radius $k$. For each valid rhombus, we calculate the sum of its border elements.

To maintain the "biggest three distinct" sums, a `std::set<int>` is an ideal data structure. A set naturally handles uniqueness and maintains elements in sorted order. By keeping the size of the set at most 3, we can efficiently track the largest values encountered. While diagonal prefix sums could optimize the sum calculation from $O(k)$ to $O(1)$, the $O(M \cdot N \cdot \min(M, N)^2)$ simulation is highly efficient for these constraints and results in cleaner, more maintainable code.

### Complexity Analysis
- **Time Complexity:** $O(M \cdot N \cdot \min(M, N)^2)$
  There are $M \times N$ possible centers. For each center, the maximum radius $k$ is $\min(M, N)/2$. Calculating the sum for a radius $k$ takes $O(k)$ time. The total complexity is roughly proportional to $\sum 4k$, which simplifies to $O(M \cdot N \cdot \min(M, N)^2)$. With $N=50$, this is approximately $1.5 \times 10^6$ operations, well within the time limit.
- **Space Complexity:** $O(1)$ 
  Excluding the space for the output, we only use a small amount of extra space for the `std::set` (which holds at most 3 integers) and loop variables.