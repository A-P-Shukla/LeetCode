# 2916. Subarrays Distinct Element Sum of Squares II

Metadata Table:
Property | Value
--- | ---
Difficulty | Hard
Topics | Array, Hash Table, Binary Indexed Tree, Segment Tree
Date | 2026-10-16
LeetCode Link | https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-ii/

## Intuition
For any sub‑array `nums[i..j]` the **distinct count** equals the number of positions `k` inside `[i, j]` whose previous occurrence lies *strictly before* `i`.  
If we denote  

```
prev[k] = index of the previous occurrence of nums[k]   ( -1 if none )
```

then the indicator  

```
a_k(i) = 1   if prev[k] < i ≤ k
          0   otherwise
```

is precisely “does `nums[k]` appear for the first time inside the sub‑array starting at `i`?”.  
Hence  

```
distinct(i, j) = Σ_{k=i..j} a_k(i)
```

and the required value is  

```
 Σ_{i≤j} distinct(i,j)² = Σ_{i≤j} ( Σ a_k )²
                        = Σ_{i≤j} Σ a_k        // singletons
                          + 2·Σ_{i≤j} Σ_{k<l} a_k·a_l   // pairs
```

The **singleton** part can be summed directly:

```
for each position k:
   a_k contributes for every i with prev[k] < i ≤ k
   number of such i = k - prev[k]
   for each such i, j can be any ≥ k   → (n - k) choices
   contribution = (n - k) * (k - prev[k])
```

The **pair** part needs the number of sub‑arrays that contain *both* `k` and `l` (`k<l`) and for which the start index `i` is larger than **both** `prev[k]` and `prev[l]`.  
For a fixed pair `(k,l)` the valid starts are  

```
i ∈ ( max(prev[k], prev[l]) , k ]          (i must be ≤ k)
```

so the count of such `i` is `max(0, k - max(prev[k], prev[l]))`.  
The end `j` can be any index ≥ `l`, i.e. `(n - l)` possibilities.

Therefore the total pair contribution is  

```
2 * Σ_{l} (n - l) * G[l]
where
G[l] = Σ_{k<l} max(0, k - max(prev[k], prev[l]))
```

Computing `G[l]` naively is O(n²).  To obtain it in `O(n log n)` we
process the array **left‑to‑right** and keep three Fenwick trees
(Binary Indexed Trees):

* **BITPrev** – keyed by `prev[k]` (shifted by +1).  
  Stores three aggregates for all already‑seen positions `k`:
  - count `cntPrev`
  - sum of indices `sumKPrev`
  - sum of `k - prev[k]` → `sumDiffPrev`

* **BITIdx** – keyed by the *position* `k`.  
  Stores
  - count `cntIdx`
  - sum of indices `sumKIdx`

* a running scalar `totalDiff = Σ_{processed k} (k - prev[k])`.

When we are at index `l` with `X = prev[l]`:

```
cntA, sumK_A, sumDiff_le   = query BITPrev up to X
cntSmall, sumK_small       = query BITIdx  up to X
```

*Elements with `prev[k] ≤ X` and `k > X`* contribute  

```
(k - X) = k - X
total = (sumK_A - sumK_small) - (cntA - cntSmall) * X
```

*Elements with `prev[k] > X`* contribute simply `k - prev[k]`, i.e.

```
totalDiff - sumDiff_le
```

Thus  

```
G[l] = (sumK_A - sumK_small) - (cntA - cntSmall) * X
       + (totalDiff - sumDiff_le)
```

After using `G[l]`