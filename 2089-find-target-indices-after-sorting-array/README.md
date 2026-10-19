# 2089. Find Target Indices After Sorting Array
| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | Array, Binary Search, Sorting |
| Date | 2026-10-19 |
| LeetCode Link | https://leetcode.com/problems/find-target-indices-after-sorting-array/ |

Intuition & Approach
- Sorting the array puts all equal elements in a contiguous block. After sorting, any index where `nums[i] == target` will be a range `[L, R)` where `L` is the first occurrence and `R` is one past the last.
- A naive scan after sorting would be O(n). Because `n ≤ 100`, this is already optimal, but we can still use binary search (`lower_bound` / `upper_bound`) to locate the boundaries in O(log n) time, demonstrating mastery of the binary‑search technique.
- Steps:
  1. Sort `nums` in non‑decreasing order.
  2. Use `lower_bound` to find the first index `L` where `nums[L] >= target`.
  3. Verify that `L` is within bounds and `nums[L] == target`; if not, the target does not exist → return empty list.
  4. Use `upper_bound` to find the first index `R` where `nums[R] > target`.
  5. Return a vector/list containing all integers from `L` to `R‑1` inclusive.

Complexity Analysis
- **Time Complexity:** Sorting dominates with `O(n log n)`. The two binary searches each run in `O(log n)`, and generating the result list is `O(k)` where `k = R‑L` (the number of target occurrences). Overall `O(n log n)`.
- **Space Complexity:** Sorting is in‑place (`O(1)` auxiliary) for C++ `std::sort`. The result list occupies `O(k)` additional space, which is required to store the answer.