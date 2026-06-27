# 3020. Find the Maximum Number of Elements in Subset

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Hash Table, Enumeration |
| Date | 2026-06-27 |
| LeetCode Link | [Find the Maximum Number of Elements in Subset](https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset/) |

### Intuition

The required pattern is `[x, x^2, x^4, ..., x^k, ..., x^4, x^2, x]`. This sequence has a very specific structure:
1. It is symmetric.
2. Every term except the middle one ($x^k$) must appear at least twice to form the "sides" of the sequence.
3. If we choose a base $x > 1$, the length of the longest possible subset is determined by how many times we can square $x$ before exhausting the available count of that number in the input array. 

For a base $x > 1$:
- We need two of each term $x, x^2, x^4, \dots, x^{2^{(m-1)}}$.
- We can have one of the middle term $x^{2^m}$.
- Therefore, the length is $2m + 1$. We iterate through the unique numbers in the frequency map and calculate the length of the chain for each base $x$.

Special case for $x = 1$:
- The pattern for 1 is just `[1, 1, ..., 1]`. Any number of 1s can be included in the subset, provided the total count of 1s is odd (to satisfy the requirement of having a middle element $1^k = 1$). If the total count of 1s is even, we can use `count - 1` elements.

### Complexity Analysis

- **Time Complexity**: $O(N \log(\log(\max(\text{nums}))))$. We first count frequencies in $O(N)$. Then, for each unique element, we iterate through powers of 2. Since $x^{2^m} \le 10^9$, $m$ is very small (at most $\log(\log(10^9)) \approx 5$).
- **Space Complexity**: $O(N)$ to store the frequency map of the elements.