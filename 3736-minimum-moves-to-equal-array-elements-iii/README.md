# 3736. Minimum Moves to Equal Array Elements III
| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | Array, Math |
| Date | 2026-11-03 |
| LeetCode Link | https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/ |

## Intuition & Approach
The only allowed operation is **increment** of a single element by 1.  
Consequently, the final common value cannot be smaller than the current maximum element `M = max(nums)`, because we cannot decrement any entry.  
If we choose any target `T > M`, every element would need additional `(T-M)` increments, raising the total moves strictly. Hence the optimal target is exactly `M`.

The minimal number of moves is therefore the sum of the gaps between `M` and each array element:

```
moves = Σ (M - nums[i])  for all i
```

Algorithm:
1. Scan the array once to find `M`.
2. Scan again (or combine with step 1) to accumulate `M - nums[i]`.
3. Return the accumulated sum.

This uses only two linear passes (or a single pass with simultaneous max‑tracking and accumulation) and O(1) extra space.

## Complexity Analysis
- **Time Complexity:** O(n), where n = `nums.length`, because each element is examined a constant number of times.
- **Space Complexity:** O(1) auxiliary space; the input array is read‑only and only a few scalar variables are used.