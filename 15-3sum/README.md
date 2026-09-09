# 15. 3Sum

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Two Pointers, Sorting |
| Date | May 31, 2026 |
| LeetCode Link | [https://leetcode.com/problems/3sum/](https://leetcode.com/problems/3sum/) |

## Intuition

We need all unique triplets `(nums[i], nums[j], nums[k])` with `i < j < k` that sum to zero. A brute-force $O(n^3)$ enumeration works but is too slow. The key insight is to **sort the array first**, which enables two optimisations:

1. **Reduce to 2Sum:** Fix one element `nums[i]` and find all pairs in the remaining subarray `nums[i+1..n-1]` that sum to `-nums[i]`. With a sorted subarray, this 2Sum variant is solvable in $O(n)$ using two pointers.

2. **Duplicate skipping without a set:** After sorting, duplicate values are adjacent. We skip `nums[i]` if it equals `nums[i-1]` (same fixed element tried before). Similarly, after finding a valid triplet, we advance both pointers past any duplicates. This avoids using a `set<vector<int>>` and keeps the solution $O(n^2)$ overall.

**Algorithm:**
- Sort `nums`.
- For each `i` from `0` to `n-3`:
  - Skip if `nums[i] > 0` (sorted array — no triplet can sum to 0 if the smallest is positive).
  - Skip if `nums[i] == nums[i-1]` (duplicate fixed element).
  - Run two pointers `left = i+1`, `right = n-1`:
    - If sum == 0: record triplet, skip duplicates, advance both pointers.
    - If sum < 0: `left++`.
    - If sum > 0: `right--`.

## Complexity Analysis

- **Time Complexity:** $O(n^2)$ — $O(n \log n)$ for sorting, plus $O(n)$ two-pointer scan for each of the $O(n)$ fixed elements.
- **Space Complexity:** $O(\log n)$ to $O(n)$ depending on the sorting algorithm; output space not counted.
