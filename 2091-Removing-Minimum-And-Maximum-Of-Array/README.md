# 2091. Removing Minimum and Maximum From Array

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Greedy |
| Date | August 30, 2026 |
| LeetCode Link | [Removing Minimum and Maximum From Array](https://leetcode.com/problems/removing-minimum-and-maximum-from-array/) |

## Intuition

We are asked to find the minimum number of deletions to remove both the minimum and maximum elements from an array, where deletions can only be performed from either the front or the back of the array.

Let $n$ be the length of the array. First, we locate the 0-based indices of the minimum and maximum elements. Let $i = \min(\text{min\_idx}, \text{max\_idx})$ and $j = \max(\text{min\_idx}, \text{max\_idx})$. That is, index $i$ is closer to the front, and index $j$ is further to the right.

There are only three possible deletion strategies to remove both target elements:

1. **Delete both from the front (left):**
   - Deleting up to index $j$ covers both elements.
   - Cost: $j + 1$
2. **Delete both from the back (right):**
   - Deleting from the right end up to index $i$ covers both elements.
   - Cost: $n - i$
3. **Delete from both ends:**
   - Delete from the front up to index $i$ (cost: $i + 1$).
   - Delete from the back up to index $j$ (cost: $n - j$).
   - Total Cost: $(i + 1) + (n - j)$

The optimal solution is simply the minimum of these three values:
$$\min(j + 1,\; n - i,\; (i + 1) + (n - j))$$

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n)$, where $n$ is the length of the array. Finding the minimum and maximum elements requires a single pass over the array, and computing the answer is done in $\mathcal{O}(1)$ time.
- **Space Complexity:** $\mathcal{O}(1)$, as only a few scalar variables are used to store indices and costs.
