# 2916. Subarrays Distinct Element Sum of Squares II

Metadata Table:
Property | Value
--- | ---
Difficulty | Hard
Topics | Array, Hash Table, Binary Indexed Tree, Segment Tree
Date | 2026-10-16
LeetCode Link | https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-ii/

## Intuition
For a subarray its **distinct count** is the number of values that appear at least once inside it.  
If we write the distinct count of a subarray as a sum of indicators  

```
distinct(l, r) = Σ 1{ value v appears in nums[l..r] }
```

then the required sum is  

```
Σ (distinct(l, r))²
    = Σ distinct(l, r)                     // each indicator once
      + 2· Σ_{i<j} 1{ i is first occurrence of nums[i] in the subarray }
                       · 1{ j is first occurrence of nums[j] in the subarray }
```

So we need two kinds of contributions  

1. **Single‑element contribution** – every position `i` contributes to all subarrays where it is the first occurrence of its value.  
2. **Pair contribution** – every ordered pair `(i, j)` with `i < j` contributes to all subarrays where **both** `i` and `j` are the first occurrences of their values.

---

### 1️⃣ Single‑element contribution  

Let `prev[i]` be the previous index of `nums[i]` (`-1` if none).  
`i` is the first occurrence of its value in a subarray `[l, r]` iff `l > prev[i]`.  
Therefore the number of subarrays where `i` is a first occurrence is  

```
(i - prev[i])      choices for left border l
· (n - i)          choices for right border r (r ≥ i)
```

Summing this for every `i` gives the first term of the answer.

---

### 2️⃣ Pair contribution  

Consider a pair `i < j`.  
Both `i` and `j` are first occurrences in a subarray `[l, r]` iff  

```
l > max(prev[i], prev[j])          // left border after the later previous occurrence
l ≤ i                               // subarray must contain i
r ≥ j                               // subarray must contain j
```

Hence the number of such subarrays is  

```
(i - max(prev[i], prev[j])) · (n - j)
```

The total pair contribution is  

```
2 · Σ_{j} (n - j) · Σ_{i<j} (i - max(prev[i], prev[j]))
```

The inner sum can be evaluated online while scanning the array from left to right.
For a fixed `j` we split previously processed indices `i` into two groups:

* **Group A** – `prev[i] ≥ prev[j]`.  
  Here `max(prev[i], prev[j]) = prev[i]` and the term becomes `i - prev[i]`.
* **Group B** – `prev[i] < prev[j]`.  
  Here `max = prev[j]` and the term becomes `i - prev[j]`.

If we maintain for all processed indices a **Fenwick tree (BIT)** keyed by `prev[i]`,
we can query in `O(log n)`:

* `cnt_lt` – count of indices with `prev[i] < prev[j]`
* `sum_i_lt` – sum of their positions `i`
* `sumA_lt` – sum of `i - prev[i]` for them (not needed directly)

The complementary set (`prev[i] ≥ prev[j]`) is obtained by subtracting from the totals
maintained so far.

Putting everything together gives the pair contribution in `O(log n)` per position,
overall `O(n log n)` time and `O(n)` memory.