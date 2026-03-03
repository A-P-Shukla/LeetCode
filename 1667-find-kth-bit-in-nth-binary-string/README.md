# 1545. Find Kth Bit in Nth Binary String

Property | Value
--- | ---
Difficulty | Medium
Topics | String, Recursion, Simulation
Date | March 03, 2025
LeetCode Link | [https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/](https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/)

## Intuition

The problem defines a sequence of strings where each string $S_n$ is built from $S_{n-1}$. While we could simulate the string construction, the constraints ($n=20$) result in a string of length $2^{20} - 1$ (approximately 1 million characters). While simulation is feasible at this scale, a recursive approach based on the geometric properties of the construction is more elegant and efficient.

The structure of $S_n$ is: `S_{n-1} + "1" + reverse(invert(S_{n-1}))`.
The length of $S_n$, denoted $L_n$, is $2^n - 1$.

Given $n$ and $k$, we can determine which part of $S_n$ the $k$-th bit falls into:
1.  **Left Half**: If $k < 2^{n-1}$, the bit is identical to the $k$-th bit in $S_{n-1}$.
2.  **Middle**: If $k = 2^{n-1}$, the bit is always '1'.
3.  **Right Half**: If $k > 2^{n-1}$, the bit is part of the `reverse(invert(S_{n-1}))` section. 
    *   Because it is reversed, index $k$ in $S_n$ corresponds to a specific index in $S_{n-1}$. The mirrored index in $S_{n-1}$ is $L_n - k + 1$.
    *   Because it is inverted, we find the bit at that mirrored index in $S_{n-1}$ and flip it ('0' to '1' or '1' to '0').

This recursive logic allows us to find the bit in $O(n)$ time without ever constructing the full string.

## Complexity Analysis

- **Time Complexity**: $O(n)$. Each recursive call reduces the problem from $S_n$ to $S_{n-1}$. Since there are $n$ levels and each level performs constant time operations, the total time is linear with respect to $n$.
- **Space Complexity**: $O(n)$. This is the maximum depth of the recursion stack. Since $n$ is small (up to 20), this is very efficient.