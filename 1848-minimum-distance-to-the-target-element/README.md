# 1848. Minimum Distance to the Target Element

Property | Value
--- | ---
Difficulty | Easy
Topics | Array
Date | April 13, 2026
LeetCode Link | [https://leetcode.com/problems/minimum-distance-to-the-target-element/](https://leetcode.com/problems/minimum-distance-to-the-target-element/)

## Intuition

The problem asks us to find an index $i$ in an array `nums` such that the value at that index matches a given `target`, and the absolute distance between that index and a given `start` index is minimized.

Since we are guaranteed that the `target` exists in the array, we can solve this by performing a single linear scan of the array. For every element that matches the target, we calculate its distance from `start` using the formula $|i - start|$. We maintain a variable to track the minimum distance found so far.

While one could optimize the search by expanding outward from the `start` index (checking `start`, then `start-1` and `start+1`, etc.), the constraints ($N \le 1000$) make a simple $O(N)$ pass extremely efficient and easier to implement.

## Complexity Analysis

- **Time Complexity:** $O(N)$, where $N$ is the length of the array. We visit each element in the array exactly once.
- **Space Complexity:** $O(1)$, as we only use a few integer variables to store the minimum distance and the current index, regardless of the input size.