# 3336. Find the Number of Subsequences With Equal GCD

| Property | Value |
| --- | --- |
| Difficulty | Hard |
| Topics | Array, Math, Dynamic Programming, Number Theory |
| Date | 2026-07-14 |
| LeetCode Link | [https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/](https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/) |

### Intuition

The problem asks for the number of pairs of disjoint non-empty subsequences with the same GCD. Given that the constraints on the length of the array and the values within the array are small (up to 200), we can use Dynamic Programming.

The state needs to capture:
1. The index in `nums` we are currently considering.
2. The current GCD of the first subsequence (`seq1`).
3. The current GCD of the second subsequence (`seq2`).

A state can be defined as `dp(index, gcd1, gcd2)`.
- At each index, we have three choices:
    - Include the element in `seq1`: Update `gcd1 = gcd(gcd1, nums[index])`.
    - Include the element in `seq2`: Update `gcd2 = gcd(gcd2, nums[index])`.
    - Skip the element entirely: The GCDs remain unchanged.

Since we need non-empty subsequences, we need to handle the "empty" state for the GCDs. A common trick is to use 0 to represent an empty subsequence, noting that `gcd(0, x) = x`. After traversing all elements, we count the number of cases where `gcd1 == gcd2` and both are greater than 0.

### Complexity Analysis

- **Time Complexity**: $O(N \cdot M^2)$, where $N$ is the length of `nums` and $M$ is the maximum value in `nums` ($200$). Since the GCD can only take values up to 200, the state space is $200 \times 201 \times 201$.
- **Space Complexity**: $O(N \cdot M^2)$ for the memoization table. This can be optimized to $O(M^2)$ if we only keep the current and previous index states, but $200^3$ fits within memory limits.