# 396. Rotate Function

Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Math, Dynamic Programming
Date | May 1, 2026
LeetCode Link | [https://leetcode.com/problems/rotate-function/](https://leetcode.com/problems/rotate-function/)

## Intuition

A brute-force approach would involve rotating the array $n$ times and calculating the summation for each rotation. Since the array length $n$ can be up to $10^5$, an $O(n^2)$ solution would exceed the time limit. We need a way to derive $F(k)$ from $F(k-1)$ in $O(1)$ time.

Let's examine the transition between $F(0)$ and $F(1)$ for an array of size $n$:
- $F(0) = 0 \cdot nums[0] + 1 \cdot nums[1] + 2 \cdot nums[2] + \dots + (n-1) \cdot nums[n-1]$
- $F(1) = 0 \cdot nums[n-1] + 1 \cdot nums[0] + 2 \cdot nums[1] + \dots + (n-1) \cdot nums[n-2]$

Let $S$ be the sum of all elements in `nums`.
The difference $F(1) - F(0)$ is:
$F(1) - F(0) = (1 \cdot nums[0] - 0 \cdot nums[0]) + (2 \cdot nums[1] - 1 \cdot nums[1]) + \dots + (0 \cdot nums[n-1] - (n-1) \cdot nums[n-1])$
$F(1) - F(0) = nums[0] + nums[1] + \dots + nums[n-2] - (n-1) \cdot nums[n-1]$

We can rewrite the right side by adding and subtracting $nums[n-1]$:
$F(1) - F(0) = (nums[0] + nums[1] + \dots + nums[n-1]) - n \cdot nums[n-1]$
$F(1) - F(0) = S - n \cdot nums[n-1]$

Generalizing this for any $k$:
$F(k) = F(k-1) + S - n \cdot nums[n-k]$

Using this recurrence relation, we can calculate each subsequent $F(k)$ in constant time after an initial $O(n)$ pass to compute $S$ and $F(0)$.

## Complexity Analysis

- **Time Complexity:** $O(n)$, where $n$ is the length of the array. We iterate through the array twice: once to compute the initial sum and $F(0)$, and once to compute the $n-1$ subsequent values of $F(k)$.
- **Space Complexity:** $O(1)$, as we only store a few variables (`sum`, `current_f`, `max_f`) regardless of the input size.