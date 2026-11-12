# 3105. Longest Strictly Increasing or Strictly Decreasing Subarray
| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | Array |
| Date | 2026-11-12 |
| LeetCode Link | https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/ |

## Intuition & Approach
The problem asks for the maximum length of a contiguous subarray that is *strictly* monotonic, either increasing or decreasing.  
A naïve approach would enumerate all O(n²) subarrays and verify monotonicity, which is unnecessary because the monotonic property is *local*: extending a subarray by one element only depends on the comparison of the new element with its immediate predecessor.

**Key observation:** While scanning the array from left to right we can maintain two running counters:
- `inc_len`: length of the current strictly increasing subarray ending at the current index.
- `dec_len`: length of the current strictly decreasing subarray ending at the current index.

When the current element `nums[i]` is greater than `nums[i‑1]`, the increasing counter grows by one; otherwise it resets to 1 (the element itself). The decreasing counter behaves analogously with the opposite comparison. At each step we update a global `ans` with the larger of the three values (`ans`, `inc_len`, `dec_len`). This yields the longest monotonic subarray in a single linear pass.

Why sub‑optimal methods fail:
- **Full enumeration** incurs O(n²) time, far exceeding the O(n) limit imposed by the constraints (even though n ≤ 50, we aim for optimality).
- **Two‑pass approach** (first identify increasing, then decreasing) would miss subarrays that switch direction mid‑scan; a single pass with parallel counters handles both directions simultaneously.

The solution therefore uses O(1) auxiliary space and O(n) time, optimal for this problem.

## Complexity Analysis
- **Time Complexity:** O(n) – each element is examined once, performing only constant‑time comparisons and updates.
- **Space Complexity:** O(1) – only a few integer variables are stored irrespective of input size.