##3741. Minimum Distance Between Three Equal Elements II

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Hash Table |
| Date | April 11, 2026 |
| LeetCode Link | [Minimum Distance Between Three Equal Elements II](https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/) |

## Intuition
The problem asks us to find a triplet of distinct indices $(i, j, k)$ such that $nums[i] = nums[j] = nums[k]$, minimizing the distance defined as $abs(i - j) + abs(j - k) + abs(k - i)$.

First, let's simplify the distance formula. For any three distinct indices, we can order them as $i < j < k$. Substituting this into the formula:
$$|i - j| + |j - k| + |k - i| = (j - i) + (k - j) + (k - i) = 2 \cdot (k - i)$$
The distance depends only on the span between the smallest and largest index of the triplet. To minimize $2 \cdot (k - i)$, we simply need to minimize $(k - i)$.

For any specific value $X$ that appears in the array at sorted positions $p_0, p_1, p_2, \dots, p_m$, any triplet $(p_a, p_b, p_c)$ with $a < b < c$ has a span of $(p_c - p_a)$. This span is minimized when $c = a + 2$. Therefore, we only need to check consecutive triplets of indices for each unique value in the array.

By using a Hash Map to track the last two seen indices for every value, we can compute the span as soon as the third occurrence of a value is encountered, maintaining an $O(N)$ time complexity.

## Complexity Analysis
- **Time Complexity:** $O(N)$, where $N$ is the length of the array. we iterate through the array once and perform $O(1)$ average-time lookups and updates in a Hash Map.
- **Space Complexity:** $O(N)$ in the worst case (when all elements are unique) to store the indices of each element in the Hash Map.
