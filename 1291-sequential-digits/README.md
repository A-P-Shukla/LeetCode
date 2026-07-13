# 1291. Sequential Digits

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Enumeration |
| Date | 2026-07-13 |
| LeetCode Link | [https://leetcode.com/problems/sequential-digits/](https://leetcode.com/problems/sequential-digits/) |

### Intuition

The definition of "sequential digits" is restrictive: digits must be increasing consecutively (e.g., 123, 4567). Given that the maximum value for `high` is $10^9$, the number of sequential digits is extremely small. A sequential number cannot exceed 9 digits (123456789), meaning there is a very limited pool of candidates.

Instead of iterating through every number between `low` and `high` (which would be $O(high - low)$ and potentially exceed time limits), we can generate all possible sequential numbers and filter those within the range. 

We can view the possible sequential numbers as substrings of the string "123456789". We iterate through all possible starting positions ($0$ to $8$) and all possible lengths ($2$ to $9 - \text{start\_index}$). For each pair, we extract the substring, convert it to an integer, and check if it satisfies `low <= num <= high`. Sorting these results ensures we meet the problem requirement.

### Complexity Analysis

*   **Time Complexity**: $O(1)$. Since the number of sequential integers is constant (there are only 45 such numbers total), the generation and sorting process takes constant time.
*   **Space Complexity**: $O(1)$. We only store a constant number of results (max 45 integers).