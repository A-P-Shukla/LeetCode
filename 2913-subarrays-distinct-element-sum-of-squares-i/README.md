# 2913. Subarrays Distinct Element Sum of Squares I

Metadata Table:
Property | Value
--- | ---
Difficulty | Easy
Topics | Array, Hash Table, Binary Indexed Tree, Segment Tree
Date | 2026-10-15
LeetCode Link | https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/

## Intuition
For each subarray we need the number of *distinct* elements, square it, and add it to the total.  
Because the array length is at most 100, we can afford an **O(n²)** enumeration of all subarrays. While expanding a subarray from a fixed left endpoint, we maintain a frequency table (or a hash set) that tells us whether the newly‑added element is a new distinct value. The distinct count only ever increases, never decreases, so we can update the answer in constant time for each right endpoint.

The overall process:

1. Fix the left index `i`.
2. Initialise an empty frequency array / set and a counter `distinct = 0`.
3. Extend the right index `j` from `i` to the end of the array.  
   * If `nums[j]` has not been seen before, increment `distinct` and mark it as seen.  
   * Add `distinct * distinct` to the running answer.
4. Move to the next left index and repeat.

Because every subarray is visited exactly once, the algorithm runs in **O(n²)** time and uses **O(𝑚)** extra space, where `𝑚` is the range of possible values (≤ 100).

## Complexity Analysis
- **Time Complexity:** `O(n²)` – there are `n` choices for the left endpoint and up to `n` extensions for the right endpoint.
- **Space Complexity:** `O(1)` (or `O(101)` explicitly) – a fixed‑size frequency array of size 101 suffices regardless of `n`.