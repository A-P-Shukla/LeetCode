# 1840. Maximum Building Height

| Property | Value |
| --- | --- |
| Difficulty | Hard |
| Topics | Array, Math, Sorting |
| Date | 2026-06-20 |
| LeetCode Link | [https://leetcode.com/problems/maximum-building-height/](https://leetcode.com/problems/maximum-building-height/) |

### Intuition

The core constraint is that the height difference between adjacent buildings cannot exceed 1. This implies that for any two buildings $i$ and $j$ with known height restrictions $H_i$ and $H_j$, the height of any building $k$ between them ($i < k < j$) is constrained by:
$H_k \leq \min(H_i + (k - i), H_j + (j - k))$.

To solve this efficiently:
1. **Preprocessing:** Add the implicit restriction for the first building: `[1, 0]`. Sort the restrictions by building ID.
2. **Left-to-Right Pass:** Ensure that for each restriction $i$, its height is compatible with the previous restriction $i-1$. Specifically, $H_i \leq H_{i-1} + (id_i - id_{i-1})$.
3. **Right-to-Left Pass:** Similarly, ensure that each restriction $i$ is compatible with the following restriction $i+1$. Specifically, $H_i \leq H_{i+1} + (id_{i+1} - id_i)$.
4. **Final Calculation:** Once the restrictions are "tightened" such that no restriction violates the constraints imposed by its neighbors, the maximum height between any two adjacent restrictions $[id_i, H_i]$ and $[id_{i+1}, H_{i+1}]$ can be calculated. The peak height achievable between them occurs at the building $k$ where the upward slope from $i$ meets the downward slope from $i+1$, resulting in a height of $(H_i + H_{i+1} + (id_{i+1} - id_i)) // 2$.

### Complexity Analysis

*   **Time Complexity:** $O(M \log M)$, where $M$ is the number of restrictions, due to the sorting step. The subsequent linear passes take $O(M)$.
*   **Space Complexity:** $O(M)$ to store the processed restrictions.