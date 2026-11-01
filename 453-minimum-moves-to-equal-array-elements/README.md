# 453. Minimum Moves to Equal Array Elements
| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Math |
| Date | 2026-11-01 |
| LeetCode Link | https://leetcode.com/problems/minimum-moves-to-equal-array-elements/ |

## Intuition & Approach
The operation “increment n‑1 elements by 1” is equivalent to *decrementing a single element by 1*.  
If we view each move as lowering the highest values toward the minimum, the total number of moves required to make all elements equal is simply the sum of differences between each element and the global minimum.

Why this works:
* Let `m` be the final equal value after all moves. Since each move adds exactly `n‑1` to the array sum, the total sum after `k` moves is `initial_sum + k·(n‑1)`.  
  When the array becomes uniform with value `m`, the sum is `n·m`. Hence `k = (n·m - initial_sum)/(n‑1)`.  
* The minimal feasible `m` is the smallest element in the original array, because we can never decrease any element (only increase). Choosing any larger `m` would add unnecessary moves.  
* Substituting `m = min(nums)` yields `k = Σ (nums[i] - min)`. This is precisely the total distance each element must travel down to the minimum.

Thus the optimal algorithm:
1. Scan the array once to find the minimum value.
2. Accumulate the differences `nums[i] - min` using a 64‑bit accumulator to avoid overflow.
3. Return the accumulator as an `int` (problem guarantees it fits 32‑bit).

Any approach that tries to simulate the moves or sorts the array incurs extra O(n log n) time, which is unnecessary.

## Complexity Analysis
*Time Complexity*: O(n) – one linear pass to find the minimum and another linear pass to sum differences (can be merged into a single pass).  
*Space Complexity*: O(1) – only a few scalar variables are used; the input array is not duplicated.