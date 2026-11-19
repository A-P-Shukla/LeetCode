# 2567. Minimum Score by Changing Two Elements
| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Greedy, Sorting |
| Date | 2026-11-19 |
| LeetCode Link | https://leetcode.com/problems/minimum-score-by-changing-two-elements/ |

## Intuition & Approach
The *low* score is the smallest absolute difference between any two numbers, the *high* score is the largest absolute difference, and the overall score is their sum.

*Observation 1* – We can always achieve `low = 0`.  
By setting the two changed elements to the same value (any integer), at least one pair becomes identical, making the minimum absolute difference zero. Therefore the problem reduces to minimizing only the *high* score after the two modifications.

*Observation 2* – Only the maximum and minimum of the array influence the *high* score (`high = max – min`).  
Changing an element to any value that lies **inside** the current `[min, max]` interval does not affect the high score. Consequently, to shrink the interval we should use the two modifications to “remove” up to two extreme values (the smallest and/or the largest).

*Observation 3* – Removing an interior element never shrinks the interval.  
Thus the only useful strategies are:
1. Delete the two smallest numbers.  
2. Delete the two largest numbers.  
3. Delete the smallest **and** the largest.  
4. Delete only the smallest (the second change is irrelevant).  
5. Delete only the largest.

After sorting, each strategy translates to a simple range calculation:
- `a[n‑1] - a[2]`   (remove two minima)
- `a[n‑3] - a[0]`   (remove two maxima)
- `a[n‑2] - a[1]`   (remove both ends)
- `a[n‑1] - a[1]`   (remove only the minimum)
- `a[n‑2] - a[0]`   (remove only the maximum)

The answer is the minimum among the valid expressions.  
For `n = 3` the interval can be collapsed to a single element, yielding score `0`.

The algorithm:
1. Sort `nums`.  
2. If `n ≤ 3`, return `0`.  
3. Compute the five candidate ranges (guarding against out‑of‑bounds).  
4. Return the smallest candidate; `low` is already `0`, so the final score equals this minimal range.

## Complexity Analysis
- **Time Complexity:** `O(n log n)` for sorting; all other operations are linear.  
- **Space Complexity:** `O(1)` extra (apart from the input array and the sorted copy).