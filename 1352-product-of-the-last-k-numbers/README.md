# 1352. Product of the Last K Numbers
| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Math, Design, Data Stream, Prefix Sum |
| Date | 2026-11-23 |
| LeetCode Link | https://leetcode.com/problems/product-of-the-last-k-numbers/ |

## Intuition & Approach
The naive solution stores the whole stream and multiplies the last *k* elements on every `getProduct` call, yielding **O(k)** time. With up to 4·10⁴ operations and *k* as large as 4·10⁴, this is too slow.

The key observation is that a *product* of a contiguous suffix can be expressed as a ratio of two **prefix products**:

```
product(last k numbers) = prefix[n] / prefix[n‑k]
```

where `prefix[i]` denotes the product of the first *i* numbers (excluding any zeroes).  
If a zero appears, every product that spans across it becomes zero. Therefore we **reset** the prefix list after a zero; any query that asks for more numbers than the length of the current prefix must include that zero, and we can immediately return 0.

By storing a running product list `pref` with a sentinel `1` at index 0, we can:

* **Add**:  
  * If `num == 0`, clear `pref` and start a new segment (`pref = [1]`).  
  * Else, append `pref.back() * num`.  
  This is O(1).

* **GetProduct(k)**:  
  * If `k >= pref.size()`, a zero lies within the requested window → return 0.  
  * Otherwise return `pref.back() / pref[pref.size() - k - 1]`.  
  Division is exact because all numbers are integers and we never overflow a 64‑bit container (the final result fits in 32‑bit per problem statement). This is O(1).

The design yields **amortized O(1)** for both operations, satisfying the follow‑up requirement.

## Complexity Analysis
- **Time Complexity**:  
  *`add`*: O(1) – constant work (push or reset).  
  *`getProduct`*: O(1) – constant arithmetic and index calculations.

- **Space Complexity**:  
  At most one prefix entry per non‑zero element, i.e. O(N) where N ≤ total number of `add` calls (≤ 4·10⁴). The extra sentinel contributes negligible space.