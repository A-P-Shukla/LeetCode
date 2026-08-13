# 2213. Longest Substring of One Repeating Character

## Metadata Table
Property | Value
--- | ---
Difficulty | Hard
Topics | String, Segment Tree
Date | 2026-08-13
LeetCode Link | https://leetcode.com/problems/longest-substring-of-one-repeating-character/

## Intuition

The problem asks us to dynamically update individual characters in a string $s$ and find the length of the longest contiguous substring consisting of a single repeating character after each update.

Since the string length $n$ and the number of queries $k$ are up to $10^5$, updating the string and rescanning it naively after each query would take $O(n)$ time per query, yielding an overall $O(n \cdot k)$ time complexity, which is far too slow and will lead to a Time Limit Exceeded (TLE) error.

This dynamic range querying and point updating problem naturally invites a **Segment Tree**. Each node in the segment tree represents a contiguous range $[L, R]$ of the string and maintains the following metadata:
1. `max_len`: The length of the longest single-character repeating substring in $[L, R]$.
2. `prefix_len`: The length of the longest repeating prefix in $[L, R]$.
3. `prefix_char`: The character forming the longest prefix in $[L, R]$.
4. `suffix_len`: The length of the longest repeating suffix in $[L, R]$.
5. `suffix_char`: The character forming the longest suffix in $[L, R]$.
6. `length`: Total length of the segment $R - L + 1$.

When merging two child nodes (Left and Right):
- The `max_len` of the parent is at least $\max(\text{Left.max\_len}, \text{Right.max\_len})$.
- If $\text{Left.suffix\_char} == \text{Right.prefix\_char}$, a single repeating substring bridges across the boundary between Left and Right, contributing a candidate length of $\text{Left.suffix\_len} + \text{Right.prefix\_len}$.
- The parent's prefix and suffix information are updated according to whether the left child or right child is uniform across its whole length.

With a Segment Tree, point updates take $O(\log n)$ time, and the overall answer for the entire string resides directly in the root node's `max_len` field in $O(1)$ time per query.

## Complexity Analysis

- **Time Complexity:** 
  - **Tree Construction:** $O(n)$ to build the segment tree initially.
  - **Query Processing:** $O(\log n)$ per update query. For $k$ queries, the total query processing time is $O(k \log n)$.
  - **Total Time Complexity:** $O(n + k \log n)$, which comfortably runs within the given time limits.

- **Space Complexity:** $O(n + k)$. The segment tree requires $O(n)$ space to store the nodes, and $O(k)$ space is used to store the output array.