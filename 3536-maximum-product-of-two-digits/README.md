# 3536. Maximum Product of Two Digits

Property | Value
--- | ---
Difficulty | Easy
Topics | Math, Sorting
Date | July 25, 2026
LeetCode Link | https://leetcode.com/problems/maximum-product-of-two-digits/

## Intuition

The problem asks us to find the maximum product of any two digits chosen from a given positive integer $n$. 

Since all digits are non-negative integers between $0$ and $9$, the product of two numbers is maximized when we pick the two largest numbers available. Therefore, the problem reduces to finding the two largest digits (let's call them $m_1$ and $m_2$) present in $n$.

We can iterate through the digits of $n$ (either by repeated division/modulo operations or by converting $n$ into a string) while maintaining two tracking variables:
1. `max1`: the largest digit seen so far.
2. `max2`: the second largest digit seen so far.

Once all digits have been processed, the answer is simply `max1 * max2`.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(\log_{10} n)$ — We iterate through each digit of $n$. Since $10 \le n \le 10^9$, $n$ has at most 10 digits, making this an $\mathcal{O}(1)$ operation in practice.
- **Space Complexity:** $\mathcal{O}(1)$ — Only a few variables are used to track the two maximum digits, requiring constant extra space.