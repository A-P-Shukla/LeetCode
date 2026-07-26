# 628. Maximum Product of Three Numbers

## Metadata
Property | Value
--- | ---
Difficulty | Easy
Topics | Array, Math, Sorting
Date | 2026-07-26
LeetCode Link | [Maximum Product of Three Numbers](https://leetcode.com/problems/maximum-product-of-three-numbers/)

## Intuition

To maximize the product of three integers in an array, we must consider the signs of the numbers:
1. **All Positive Numbers (or All Negative)**: The maximum product is simply formed by multiplying the **three largest numbers** in the array.
2. **Negative Numbers Present**: Multiplying two negative numbers yields a positive product. If we take the **two smallest (most negative) numbers** and multiply them with the **largest positive number**, we can potentially produce a product larger than the product of the three largest numbers.

Therefore, the candidate maximum products are always narrowed down to two scenarios:
- `max1 * max2 * max3` (product of the three largest numbers)
- `min1 * min2 * max1` (product of the two smallest numbers and the single largest number)

While sorting the array takes $O(N \log N)$ time, we can optimize this to $O(N)$ time and $O(1)$ space by finding the top 3 maximums (`max1`, `max2`, `max3`) and top 2 minimums (`min1`, `min2`) in a single linear scan.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the number of elements in `nums`. We traverse the array exactly once to track the three largest and two smallest values.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space, as we only maintain a few integer variables.