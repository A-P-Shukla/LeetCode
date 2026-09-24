# Smallest Index With Equal Digit Sum

| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | Array, Math |
| Date | September 24, 2026 |
| LeetCode Link | https://leetcode.com/problems/smallest-index-with-equal-digit-sum/ |

## Intuition

The problem requires us to find the smallest index $i$ such that the sum of the decimal digits of `nums[i]` is equal to $i$. 

Since we are looking for the **smallest** index $i$, a linear scan from index $0$ to $n - 1$ is ideal. Iterating in increasing order of indices ensures that the first index that satisfies the condition `digit_sum(nums[i]) == i` is guaranteed to be the minimal answer. If we reach the end of the array without finding any satisfying index, we simply return `-1`.

To compute the sum of digits of a non-negative integer $n$:
1. Repeatedly extract the last digit using modulo arithmetic (`n % 10`).
2. Accumulate the digit into a running sum.
3. Remove the last digit using integer division (`n / 10`).
4. Repeat until $n$ becomes $0$.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N \times \log_{10}(M))$, where $N$ is the length of `nums` and $M$ is the maximum value in `nums`. Since $nums[i] \le 1000$, $M$ has at most 4 digits, making the digit sum calculation $\mathcal{O}(1)$ for each element. Thus, the overall time complexity simplifies to $\mathcal{O}(N)$.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space, as we only store a few integer variables for iteration and tracking the digit sum.