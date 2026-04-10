# 3740. Minimum Distance Between Three Equal Elements I

| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | Array, Hash Table |
| Date | April 10, 2026 |
| LeetCode Link | [Minimum Distance Between Three Equal Elements I](https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/) |

## Intuition

To solve this problem efficiently, we first need to simplify the distance formula for a good tuple $(i, j, k)$. Given three distinct indices, let's assume they are ordered such that $i < j < k$.

The distance is defined as:
`dist = abs(i - j) + abs(j - k) + abs(k - i)`

Substituting our assumption $i < j < k$:
`dist = (j - i) + (k - j) + (k - i)`
`dist = j - i + k - j + k - i`
`dist = 2k - 2i = 2(k - i)`

This reveals that the distance of any triplet depends solely on the difference between the maximum index and the minimum index of the triplet. The intermediate index $j$ does not affect the total distance as long as it exists and is distinct.

**Strategy:**
1.  **Group Indices:** We need to find indices where `nums[i]` is the same. A hash map (or an array, since $nums[i] \le n$) can store the list of indices for each unique value.
2.  **Minimize Span:** For any value that appears at least three times, we want to pick three indices such that the difference between the largest and smallest is minimized. In a sorted list of indices, the minimum difference between the first and third element of a triplet occurs when the triplet is composed of **consecutive** indices in that list (i.e., indices at positions $p, p+1, p+2$).
3.  **Global Minimum:** Iterate through all unique values, calculate the minimum distance for each, and keep track of the overall minimum.

## Complexity Analysis

-   **Time Complexity:** $O(n)$, where $n$ is the length of the array. We traverse the array once to group indices into a map, and then traverse the lists of indices. Since the total number of indices stored is $n$, the second traversal also takes $O(n)$.
-   **Space Complexity:** $O(n)$ to store the indices of each number in the hash map.
