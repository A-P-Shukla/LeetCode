# 18. 4Sum

| Property | Value |
| --- | --- |
| Difficulty | Hard |
| Topics | Array, Two Pointers, Sorting |
| Date | May 31, 2026 |
| LeetCode Link | [https://leetcode.com/problems/4sum/](https://leetcode.com/problems/4sum/) |

## Intuition

4Sum is a direct generalisation of 3Sum. We fix two elements with nested loops and reduce the inner problem to a 2Sum on the remaining sorted subarray, solved with two pointers.

**Key design decisions:**

1. **Sorting first** enables duplicate skipping and early termination — if the four smallest remaining elements already exceed `target`, we can break the inner loop; if the four largest are still below `target`, we can skip the current outer element.

2. **Duplicate skipping:** After sorting, identical values are adjacent. We skip `nums[a]` if `a > 0 && nums[a] == nums[a-1]`, and similarly for `nums[b]`. After recording a valid quadruplet, we advance both inner pointers past duplicates before moving them inward.

3. **Overflow prevention:** The sum of four integers can exceed `INT_MAX`. We use `long long` arithmetic for all sum comparisons.

**Algorithm:**
- Sort `nums`.
- For each `a` from `0` to `n-4` (skip duplicates):
  - For each `b` from `a+1` to `n-3` (skip duplicates):
    - Two pointers `left = b+1`, `right = n-1`:
      - `sum = nums[a] + nums[b] + nums[left] + nums[right]`
      - If `sum == target`: record, skip duplicates, advance both.
      - If `sum < target`: `left++`.
      - If `sum > target`: `right--`.

## Complexity Analysis

- **Time Complexity:** $O(n^3)$ — two nested loops $O(n^2)$ with an $O(n)$ two-pointer scan inside.
- **Space Complexity:** $O(\log n)$ to $O(n)$ for sorting; output space not counted.
