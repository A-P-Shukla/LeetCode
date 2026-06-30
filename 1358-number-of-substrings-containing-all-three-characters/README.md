# 1358. Number of Substrings Containing All Three Characters

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Hash Table, String, Sliding Window |
| Date | 2026-06-30 |
| LeetCode Link | [https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/) |

### Intuition

The problem asks for the total count of substrings that contain at least one 'a', one 'b', and one 'c'. A brute-force approach would check every possible substring, resulting in $O(N^2)$ complexity, which is inefficient for $N=5 \times 10^4$.

We can solve this efficiently using the **Sliding Window** technique. The key observation is that if a substring $s[i..j]$ contains 'a', 'b', and 'c', then any longer substring $s[i..k]$ where $k > j$ will also contain all three characters. 

Instead of iterating over all start indices, we maintain a window $[left, right]$ and expand the `right` boundary. Once the current window contains all three characters, we know that every substring starting from $0$ up to `left` and ending at `right` is valid. Specifically, if the window $[left, right]$ is valid, then all substrings $[0, right], [1, right], \dots, [left, right]$ are valid. This means there are $(left + 1)$ valid substrings ending at `right`. We then move the `left` pointer forward to find the next smallest valid window, accumulating the count.

### Complexity Analysis

*   **Time Complexity:** $O(N)$, where $N$ is the length of the string. The `right` pointer traverses the string once, and the `left` pointer also traverses the string at most once.
*   **Space Complexity:** $O(1)$, because we only use a fixed-size frequency array (or hash map) of size 3 to track the counts of 'a', 'b', and 'c'.