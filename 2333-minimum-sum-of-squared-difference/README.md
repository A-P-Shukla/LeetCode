# 2333. Minimum Sum of Squared Difference

Metadata Table:
Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Binary Search, Greedy, Sorting, Heap (Priority Queue)
Date | 2026-10-10
LeetCode Link | https://leetcode.com/problems/minimum-sum-of-squared-difference/

## Intuition
The only thing that matters after all possible modifications is the **absolute difference** between the two arrays at each index:

```
diff[i] = |nums1[i] - nums2[i]|
```

An operation (`+1` or `-1`) on either array changes a single `diff[i]` by **exactly 1** (either decreasing it if we move towards the other value, or increasing it otherwise).  
Since we are asked for the *minimum* possible sum of squares, we will **never** increase a positive difference while we still have moves left; we will always try to reduce the *largest* difference first because reducing a larger `d` yields a larger reduction in `d²` (`d² - (d‑1)² = 2d‑1`).

Consequently the problem becomes:

*Given a multiset of non‑negative integers `diff[i]` and `K = k1 + k2` allowed unit reductions, repeatedly reduce the current maximum element by 1 until either all elements become 0 or we run out of operations.*

A naïve simulation with a max‑heap would be `O(K log n)` – far too slow for `K` up to `10⁹`.  
Instead we **bucket** the differences because each `diff[i]` is at most `10⁵`. By processing buckets from large to small we can apply whole “layers” of reductions in O(maxDiff) time.

## Complexity Analysis
*Time*: `O(n + maxDiff)` – counting the differences (`O(n)`) and scanning the buckets (`O(maxDiff)`, where `maxDiff ≤ 10⁵`).  
*Space*: `O(maxDiff)` for the frequency array (≈ 10⁵ integers).