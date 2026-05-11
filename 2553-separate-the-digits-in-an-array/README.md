# 2553. Separate the Digits in an Array

Property | Value
--- | ---
Difficulty | Easy
Topics | Array, Simulation
Date | May 11, 2026
LeetCode Link | [https://leetcode.com/problems/separate-the-digits-in-an-array/](https://leetcode.com/problems/separate-the-digits-in-an-array/)

## Intuition
The problem asks us to take a sequence of integers and "flatten" them into their constituent digits while maintaining the original order. There are two primary ways to approach this:

1.  **String Conversion**: Convert each integer to a string, iterate through the characters of the string, and convert each character back to an integer. This is often the most readable approach in high-level languages.
2.  **Mathematical Extraction**: For each number, repeatedly use the modulo operator (`% 10`) to get the last digit and division (`/ 10`) to remove it. Since this extracts digits from right to left, we need to store them temporarily (e.g., in a stack or a temporary vector) and then append them to our result in reverse order.

Given the constraints ($10^5$ is the maximum value), each number has at most 6 digits. The total number of digits is small enough that either method is highly efficient.

## Complexity Analysis
- **Time Complexity**: $O(n \cdot k)$, where $n$ is the number of elements in the input array and $k$ is the average number of digits per element. Since $k$ is small and bounded (max 6), this effectively simplifies to $O(D)$, where $D$ is the total number of digits across all integers.
- **Space Complexity**: $O(D)$ to store the resulting array of digits. If we do not count the output array, the auxiliary space used for temporary digit storage is $O(k)$, which is $O(1)$ as $k \le 6$.