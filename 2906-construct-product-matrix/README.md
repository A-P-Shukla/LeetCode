# 2906. Construct Product Matrix

Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Matrix, Prefix Sum
Date | March 24, 2026
LeetCode Link | [https://leetcode.com/problems/construct-product-matrix/](https://leetcode.com/problems/construct-product-matrix/)

### Intuition
The problem asks us to compute a product matrix where each element `p[i][j]` is the product of all elements in the original `grid` except for `grid[i][j]`, all modulo `12345`. 

A naive approach would be to calculate the total product of the matrix and divide by the current element. However, this is problematic for two reasons:
1. **Division under Modulo**: The modulo $12345$ is not prime ($12345 = 3 \times 5 \times 823$). Thus, modular inverses do not exist for all numbers.
2. **Zeros**: If an element in the grid is a multiple of $12345$, it effectively acts as a zero in the modulo arithmetic, making division impossible.

The optimal strategy is the **Prefix and Suffix Product** pattern. We can treat the 2D matrix as a flattened 1D array. By calculating the running product of elements before a specific index (prefix) and the running product of elements after that index (suffix), we can determine the "product of all except current" without ever using division. 

To optimize space, we use the output matrix itself to store the prefix products and then perform a backward pass to incorporate the suffix products.

### Complexity Analysis
- **Time Complexity**: $O(n \times m)$, where $n$ is the number of rows and $m$ is the number of columns. we traverse the matrix twice (once forward, once backward).
- **Space Complexity**: $O(1)$ extra space if we don't count the output matrix, or $O(n \times m)$ to store the result.