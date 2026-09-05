# 6. Zigzag Conversion

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | String |
| Date | May 31, 2026 |
| LeetCode Link | [https://leetcode.com/problems/zigzag-conversion/](https://leetcode.com/problems/zigzag-conversion/) |

## Intuition

The string is written in a zigzag pattern across `numRows` rows, then read row by row. For example, `"PAYPALISHIRING"` with `numRows = 3` produces:

```
P   A   H   N
A P L S I I G
Y   I   R
```

Reading row by row gives `"PAHNAPLSIIGYIR"`.

**Simulation approach:**
We maintain one string buffer per row. As we iterate through the characters, we track the current row and a direction flag (`goingDown`). The direction flips whenever we hit the top row (row 0) or the bottom row (row `numRows - 1`). Each character is appended to its corresponding row buffer. Finally, we concatenate all row buffers.

**Why this is correct:** Every character in the original string belongs to exactly one row in the zigzag pattern. The direction flag correctly models the "V" shape of the traversal — going down from row 0 to row `numRows-1`, then back up.

**Edge cases:**
- If `numRows == 1` or `numRows >= len(s)`, no zigzag occurs and the string is returned unchanged.

## Complexity Analysis

- **Time Complexity:** $O(n)$ — each of the $n$ characters is appended to a row buffer exactly once, and the final concatenation is also $O(n)$.
- **Space Complexity:** $O(n)$ — the row buffers collectively hold all $n$ characters.
