# 1344. Angle Between Hands of a Clock

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Math |
| Date | 2026-06-18 |
| LeetCode Link | [https://leetcode.com/problems/angle-between-hands-of-a-clock/](https://leetcode.com/problems/angle-between-hands-of-a-clock/) |

### Intuition

To solve this problem, we need to calculate the position of both the hour and minute hands in degrees relative to the 12 o'clock position (which we define as 0 degrees).

1.  **Minute Hand:** The minute hand completes a full circle ($360^\circ$) in 60 minutes. Therefore, it moves at a rate of $360/60 = 6^\circ$ per minute. The position is simply `minutes * 6`.
2.  **Hour Hand:** The hour hand completes a full circle in 12 hours. However, it also moves continuously as the minutes pass. 
    *   In 12 hours, it moves $360^\circ$, so it moves $30^\circ$ per hour ($360/12$).
    *   Additionally, in 60 minutes, the hour hand moves the distance of one hour mark ($30^\circ$). Thus, it moves $30/60 = 0.5^\circ$ per minute.
    *   The total position is `(hour % 12) * 30 + minutes * 0.5`.
3.  **Calculate the Angle:** Take the absolute difference between the two positions. Since we need the *smaller* angle, if the resulting angle is greater than $180^\circ$, we subtract it from $360^\circ$.

### Complexity Analysis

*   **Time Complexity:** $O(1)$. The calculation involves a fixed number of arithmetic operations, regardless of the input values.
*   **Space Complexity:** $O(1)$. We only store a few floating-point variables to hold intermediate results.