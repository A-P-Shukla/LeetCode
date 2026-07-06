# 1288. Remove Covered Intervals

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Sorting |
| Date | 2026-07-06 |
| LeetCode Link | https://leetcode.com/problems/remove-covered-intervals/ |

### Intuition

To efficiently determine which intervals are covered, we must first impose an order on them. If we sort the intervals, we can simplify the condition $[c, d]$ covering $[a, b]$ (where $c \le a$ and $b \le d$).

1.  **Sorting Strategy:** We sort the intervals primarily by their start time (`l`) in ascending order. If two intervals have the same start time, we sort by their end time (`r`) in *descending* order.
    *   Why descending for `r` when `l` is the same? This ensures that if we have `[1, 4]` and `[1, 6]`, the longer one comes first. The longer one will potentially cover the shorter one.

2.  **Greedy Sweep:** After sorting, we iterate through the intervals while keeping track of the current `max_r` seen so far.
    *   For a new interval `[curr_l, curr_r]`:
        *   If `curr_r <= max_r`, the current interval is entirely contained within the previous "master" interval that defined `max_r`. We increment a counter of removed intervals (or simply don't count it).
        *   If `curr_r > max_r`, it means this interval extends beyond the previous ones. It is not covered, so we update `max_r = curr_r` and count it as a "remaining" interval.

This approach allows us to process the intervals in a single pass after sorting.

### Complexity Analysis

*   **Time Complexity:** $O(N \log N)$, where $N$ is the number of intervals. This is dominated by the sorting step. The subsequent linear scan is $O(N)$.
*   **Space Complexity:** $O(1)$ or $O(N)$ depending on the sorting implementation (in-place vs. auxiliary space for the sort).