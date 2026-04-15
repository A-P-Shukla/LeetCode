# 2515. Shortest Distance to Target String in a Circular Array

Property | Value
--- | ---
Difficulty | Easy
Topics | Array, String
Date | April 15, 2026
LeetCode Link | [https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/](https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/)

## Intuition

The problem asks for the minimum distance between a starting point and a target element in a circular array. In a circular array of size $n$, there are always two ways to reach one index from another:
1.  **Forward/Direct distance:** The absolute difference between the indices, $|i - j|$.
2.  **Circular/Wrap-around distance:** The total length minus the direct distance, $n - |i - j|$.

Because the constraints are small ($n \le 100$), the most straightforward approach is to iterate through every index in the array. Whenever we encounter a word that matches the target, we calculate both possible distances (direct and wrap-around), find the minimum of those two, and update our global minimum distance. If, after checking all elements, we haven't found the target, we return -1.

## Complexity Analysis

- **Time Complexity:** $O(n \cdot L)$, where $n$ is the number of words in the array and $L$ is the average length of the strings. We iterate through the array once and perform a string comparison at each step.
- **Space Complexity:** $O(1)$, as we only use a few integer variables to track the minimum distance and loop indices.