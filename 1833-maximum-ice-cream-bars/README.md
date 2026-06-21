# 1833. Maximum Ice Cream Bars

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Greedy, Sorting, Counting Sort |
| Date | 2026-06-21 |
| LeetCode Link | https://leetcode.com/problems/maximum-ice-cream-bars/ |

### Intuition

To maximize the number of ice cream bars the boy can buy, we should always prioritize the cheapest bars first. This is a classic greedy problem. Buying a cheaper item leaves more coins available for subsequent, potentially more expensive items, thereby increasing the total count of items purchased.

The problem specifically mandates the use of **Counting Sort**. Since the range of ice cream costs is relatively small ($1$ to $10^5$), we can create a frequency array where the index represents the cost of an ice cream bar, and the value at that index represents the number of bars available at that specific cost.

By iterating through the frequency array from the lowest cost ($1$) to the highest ($10^5$), we can simulate "buying" bars in increasing order of price until our coins run out. This approach is highly efficient for large datasets where the range of input values is constrained.

### Complexity Analysis

*   **Time Complexity:** O(N + M), where N is the number of ice cream bars and M is the maximum cost of an ice cream bar (100,000). We iterate through the `costs` array once to fill the frequency array, and then iterate through the frequency array once to calculate the total bars.
*   **Space Complexity:** O(M), required to store the frequency array of size $M + 1$.