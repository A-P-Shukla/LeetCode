# 3420. Count Non-Decreasing Subarrays After K Operations
| Property | Value |
| --- | --- |
| Difficulty | Hard |
| Topics | Array, Stack, Segment Tree, Queue, Sliding Window, Monotonic Stack, Monotonic Queue |
| Date | 2026-11-13 |
| LeetCode Link | https://leetcode.com/problems/count-non-decreasing-subarrays-after-k-operations/ |

## Intuition & Approach
For a fixed subarray `nums[l..r]` the *minimum* number of increments required to make it non‑decreasing is obtained by scanning left‑to‑right, keeping the highest value seen so far (`curMax`).  
If the current element `a` is smaller than `curMax` we must raise it by `curMax‑a`; otherwise `curMax` becomes `a`.  
Summing all those deficits yields  

```
cost(l, r) = Σ (prefixMax_i – nums_i)   ,  i∈[l,r]
```

where `prefixMax_i = max{ nums[l], … , nums[i] }`.

Thus a subarray is *good* iff `cost(l,r) ≤ k`.  
Counting all good subarrays reduces to a classic “two‑pointer with sliding window” problem where we must maintain `cost` while expanding `r` and possibly contracting `l`.

The bottleneck is updating `cost` when the left border moves: removing `nums[l]` can change the prefix maxima of many later positions, not just a single element.  
To handle this in **O(1) amortized** we store the window as a **deque of monotonic segments**:

* Each segment represents a consecutive block where the prefix maximum is constant.
* A segment stores `(value = that constant maximum, cnt = length of block)`.

When a new element `x` enters on the right:

1. Its own block length starts at 1.
2. While the last segment’s `value ≤ x` we merge it into the new block because the larger `x` becomes the new prefix maximum for all those positions.
3. After merging, push a segment `(x, mergedLength)`.
4. Update `sumMax` = Σ(value * cnt) for the whole window.

The total increments needed for the current window are  

```
cost = sumMax – sumNums
```

where `sumNums` is the ordinary sum of the window elements.  
Both `sumMax` and `sumNums` are updated in O(1) when elements are added or removed.

When `cost > k` we slide the left border:

* Subtract `nums[l]` from `sumNums`.
* Decrease the front segment’s `cnt` by one and subtract its `value` from `sumMax`.
* If the front segment becomes empty, pop it.
* Increment `l` until `cost ≤ k`.

For each right endpoint `r` the number of valid subarrays ending at `r` equals `r‑l+1`. Accumulating this over all `r` yields the answer.

The algorithm touches each array element a constant number of times (push, pop in deque), guaranteeing **O(n)** time and **O(n)** worst‑case space.

## Complexity Analysis
*Time* – Each element is inserted once and removed once from the deque; all merges and pops are amortized O(1). Overall **O(n)**.

*Space* – The deque stores at most `n` segments, each O(1). Plus a few 64‑bit scalars. **O(n)** auxiliary space (worst case when the array is strictly decreasing).