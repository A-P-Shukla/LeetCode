# 788. Rotated Digits

Property | Value
--- | ---
Difficulty | Medium
Topics | Math, Dynamic Programming
Date | May 2, 2026
LeetCode Link | [https://leetcode.com/problems/rotated-digits/](https://leetcode.com/problems/rotated-digits/)

## Intuition

The problem asks us to count numbers in the range $[1, n]$ that, when rotated 180 degrees, result in a valid number that is different from the original. 

To solve this, we need to categorize digits based on their behavior after a 180-degree rotation:
1.  **Invalid Digits**: `3, 4, 7`. If a number contains any of these digits, it becomes invalid upon rotation.
2.  **Neutral Digits**: `0, 1, 8`. These digits rotate into themselves. If a number consists *only* of these digits, the rotated number will be identical to the original.
3.  **Rotating Digits**: `2, 5, 6, 9`. These digits rotate into a different valid digit (`2 <-> 5` and `6 <-> 9`). If a number contains at least one of these (and no invalid digits), the rotated number will be valid and different from the original.

**Condition for a "Good" Number:**
-   It must **not** contain any digits from the **Invalid** set.
-   It must contain **at least one** digit from the **Rotating** set.

While this can be solved using Digit Dynamic Programming for very large $N$, the constraint $N \le 10^4$ allows for a straightforward iterative approach where we check every number from 1 to $N$.

## Complexity Analysis

-   **Time Complexity**: $O(N \log_{10} N)$. We iterate through $N$ numbers. For each number, we inspect its digits. Since $N$ has at most $\log_{10} N$ digits, the total complexity is linear with respect to the total number of digits processed.
-   **Space Complexity**: $O(1)$ or $O(\log_{10} N)$. If we check digits using mathematical operations (modulo/division), the space is $O(1)$. If we convert the number to a string, the space is proportional to the number of digits.