# 31. Next Permutation

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Two Pointers |
| Date | May 31, 2026 |
| LeetCode Link | [https://leetcode.com/problems/next-permutation/](https://leetcode.com/problems/next-permutation/) |

## Intuition

The next permutation is the lexicographically smallest arrangement that is strictly greater than the current one. The algorithm works in three steps, each with a clear mathematical justification:

**Step 1 — Find the pivot:**
Scan from right to left to find the first index `i` where `nums[i] < nums[i+1]`. This is the rightmost position where the suffix is not already in descending order. Everything to the right of `i` is in descending order (the largest possible arrangement of those elements), so we must change `nums[i]` to make the number larger.

**Step 2 — Swap with the successor:**
Find the rightmost index `j > i` where `nums[j] > nums[i]`. Swap `nums[i]` and `nums[j]`. This makes the number at position `i` as small as possible while still being larger than before — giving the smallest possible increase.

**Step 3 — Reverse the suffix:**
After the swap, the suffix `nums[i+1..n-1]` is still in descending order (swapping with the rightmost valid `j` preserves this property). Reversing it gives the lexicographically smallest arrangement of those elements, completing the next permutation.

**Edge case:** If no pivot exists (the entire array is descending — the largest permutation), we reverse the whole array to wrap around to the smallest permutation.

## Complexity Analysis

- **Time Complexity:** $O(n)$ — at most two linear scans (finding pivot and successor) plus one reversal.
- **Space Complexity:** $O(1)$ — all operations are in-place.
