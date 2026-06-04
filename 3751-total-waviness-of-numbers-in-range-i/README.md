# 3751. Total Waviness of Numbers in Range I

### Metadata Table
Property | Value
--- | ---
Difficulty | Medium
Topics | Math, Dynamic Programming, Enumeration
Date | June 4, 2026
LeetCode Link | [Total Waviness of Numbers in Range I](https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/)

### Intuition
The problem asks for the sum of the "waviness" of all integers in the closed range `[num1, num2]`. The waviness of a number is the total number of peaks and valleys formed by its digits (excluding the first and last digits).

Given that the maximum limit of `num2` is extremely small ($10^5$), we can easily compute the waviness of each number in the range individually. 

For each number $n$ in the range `[num1, num2]`:
1. Convert $n$ to its string representation.
2. If the length is less than 3, its waviness is 0.
3. Otherwise, iterate through all internal digits (from index `1` to `length - 2`) and check if the digit is:
   - A **peak**: strictly greater than both its left and right neighbors.
   - A **valley**: strictly less than both its left and right neighbors.
4. Sum the occurrences across all numbers in the range.

This direct simulation/enumeration is highly efficient and easily runs well within the time limit.

### Complexity Analysis
- **Time Complexity:** $\mathcal{O}((num2 - num1) \cdot L)$ where $L$ is the number of digits of $num2$. Since $num2 \le 10^5$, $L \le 6$. Thus, the total number of operations is at most $6 \times 10^5$, which executes in just a few milliseconds.
- **Space Complexity:** $\mathcal{O}(L)$ to store the string representation of the current number, which is $\mathcal{O}(1)$ since $L \le 6$.