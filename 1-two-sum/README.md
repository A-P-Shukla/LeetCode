# 1. Two Sum

| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | Array, Hash Table |
| Date | May 31, 2026 |
| LeetCode Link | [https://leetcode.com/problems/two-sum/](https://leetcode.com/problems/two-sum/) |

## Intuition

The naive approach checks every pair $(i, j)$ where $i < j$, giving $O(n^2)$ time. We can do much better with a **Hash Map**.

The key observation is: for each element `nums[i]`, we are looking for a previously seen element equal to `target - nums[i]` (its complement). If we store every element we have seen so far in a hash map (value → index), we can check for the complement in $O(1)$.

The algorithm is a single pass:
1. For each index `i`, compute `complement = target - nums[i]`.
2. If `complement` is already in the map, return `[map[complement], i]`.
3. Otherwise, insert `nums[i] → i` into the map and continue.

This works because by the time we reach the second element of any valid pair, the first element is guaranteed to already be in the map. We never need to look ahead.

**Edge cases handled:**
- The same element cannot be used twice — since we check the map *before* inserting the current element, `nums[i]` is never matched against itself.

## Complexity Analysis

- **Time Complexity:** $O(n)$ — a single pass with $O(1)$ average-case hash map operations per element.
- **Space Complexity:** $O(n)$ — the hash map stores at most $n$ entries in the worst case (no valid pair until the last element).
