# 2124. Check if All A's Appears Before All B's
| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | String |
| Date | 2026-11-22 |
| LeetCode Link | https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/ |

## Intuition & Approach
The string contains only two characters, **'a'** and **'b'**.  
The condition *“every ‘a’ appears before every ‘b’”* is violated exactly when an **'a'** is found **after** a **'b'** has already appeared. Therefore:

1. Scan the string from left to right.
2. Maintain a boolean `seenB` that becomes `true` the moment we encounter the first **'b'**.
3. While `seenB` is `true`, encountering any **'a'** means the ordering rule is broken → return `false`.
4. If the scan finishes without such a violation, the ordering holds → return `true`.

Why not sort or count? Sorting would be O(n log n) and unnecessary; counting only tells us frequencies, not ordering. A single linear pass yields the answer in optimal O(n) time and constant extra space.

## Complexity Analysis
- **Time Complexity:** $O(n)$, where *n* is `s.length`, because each character is inspected exactly once.
- **Space Complexity:** $O(1)$, only a single boolean flag is used regardless of input size.