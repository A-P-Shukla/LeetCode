# 1732. Find the Highest Altitude

| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | Array, Prefix Sum |
| Date | 2026-06-19 |
| LeetCode Link | https://leetcode.com/problems/find-the-highest-altitude/ |

### Intuition

The problem asks us to find the maximum value among a series of altitudes reached by a biker. We are given the *net gain* between consecutive points, starting from an initial altitude of 0.

To solve this, we can simulate the road trip point by point. We keep track of the `current_altitude`, which starts at 0. As we iterate through the `gain` array, we update our `current_altitude` by adding the current gain value to it. Simultaneously, we maintain a `max_altitude` variable to store the highest value `current_altitude` has ever reached. Since we want to find the maximum altitude, we compare the `current_altitude` with our `max_altitude` at every step and update `max_altitude` whenever the current one is higher. This approach effectively computes the prefix sums of the gains on the fly.

### Complexity Analysis

*   **Time Complexity:** $O(n)$, where $n$ is the length of the `gain` array. We iterate through the input array exactly once, performing constant-time operations at each step.
*   **Space Complexity:** $O(1)$. We only use a constant amount of extra space for the `current_altitude` and `max_altitude` variables, regardless of the input size.