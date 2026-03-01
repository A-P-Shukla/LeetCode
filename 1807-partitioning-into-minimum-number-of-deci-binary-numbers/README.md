# 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers

Property | Value
--- | ---
Difficulty | Medium
Topics | String, Greedy
Date | March 1, 2026
LeetCode Link | [https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/](https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/)

### Intuition

The problem defines a "deci-binary" number as one where every digit is either $0$ or $1$. We are asked to find the minimum number of such values that sum up to a given string $n$.

The core insight lies in observing how addition works column by column. In any specific digit position (e.g., the units place, the tens place), a deci-binary number can contribute at most a $1$ to the sum at that position. It cannot contribute more than $1$ because its digits are restricted to $\{0, 1\}$. 

If a digit at a certain position in $n$ is $x$, we need at least $x$ deci-binary numbers to have a $1$ at that position to sum up to $x$. While carries from lower positions could theoretically impact higher positions, they would only increase the value needed at that position, not decrease the requirement for the number of deci-binary values. Since we want the *minimum* number of deci-binary strings, we simply look for the most restrictive constraint. 

The most restrictive constraint is the largest digit present in the string $n$. If the string contains a '9', we must have at least 9 deci-binary numbers because no single deci-binary number can contribute more than 1 to that specific column. Consequently, the answer is simply the maximum digit found in the string.

### Complexity Analysis

*   **Time Complexity:** $O(L)$, where $L$ is the length of the string $n$. We perform a single linear pass through the string to identify the largest character.
*   **Space Complexity:** $O(1)$, as we only store a single variable to track the maximum digit encountered during the iteration.