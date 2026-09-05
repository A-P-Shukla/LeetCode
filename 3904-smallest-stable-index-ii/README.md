# Find the Smallest Stable Index

## Metadata Table
Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Prefix / Suffix Evaluation
Date | September 05, 2026
LeetCode Link | LeetCode Problem

## Intuition

The problem requires us to find the smallest index $i$ where the **instability score** is less than or equal to $k$. The instability score at index $i$ is defined as:
$$\text{instability\_score}(i) = \max(\text{nums}[0..i]) - \min(\text{nums}[i..n-1])$$

A naive approach of calculating the maximum of the prefix $\text{nums}[0..i]$ and the minimum of the suffix $\text{nums}[i..n-1]$ for each index $i$ independently would take $O(n)$ time per index, resulting in an $O(n^2)$ overall time complexity. Given $n \le 10^5$, this would result in a Time Limit Exceeded (TLE).

To optimize this to $O(n)$:
1. **Precompute Suffix Minimums:** By scanning the array from right to left (index $n-1$ down to $0$), we can construct an array `suffix_min` where `suffix_min[i]` stores $\min(\text{nums}[i..n-1])$.
2. **Maintain Running Prefix Maximum:** As we iterate from left to right (index $0$ up to $n-1$), we can maintain a variable `prefix_max` that stores $\max(\text{nums}[0..i])$.

At each index $i$, we evaluate `prefix_max - suffix_min[i]`. The first index that satisfies `prefix_max - suffix_min[i] <= k` is our answer. If no index satisfies this condition after visiting all elements, we return `-1`.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n)$
  - Building the `suffix_min` array takes a single backward traversal over the array of size $n$, which runs in $\mathcal{O}(n)$ time.
  - Finding the first index takes a single forward traversal over the array of size $n$, which also runs in $\mathcal{O}(n)$ time.
  - Overall Time Complexity: $\mathcal{O}(n)$.

- **Space Complexity:** $\mathcal{O}(n)$
  - We use an auxiliary array `suffix_min` of size $n$ to store the suffix minimum values.
  - Overall Space Complexity: $\mathcal{O}(n)$.