# 2161. Partition Array According to Given Pivot

### Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Two Pointers, Simulation
Date | June 8, 2026
LeetCode Link | [Partition Array According to Given Pivot](https://leetcode.com/problems/partition-array-according-to-given-pivot/)

---

## Intuition

The problem requires partitioning an array into three groups based on a given `pivot`:
1. Elements strictly less than `pivot`.
2. Elements equal to `pivot`.
3. Elements strictly greater than `pivot`.

Crucially, the **relative order** of elements in the first and third groups must be preserved. This requirement of maintaining order makes standard, in-place partitioning algorithms (like the one used in QuickSort) unsuitable, as they are inherently unstable.

To solve this efficiently in $O(N)$ time, we can allocate a new array of the same size as `nums` and fill it strategically:
* **Left-to-Right Pass for Smaller Elements:** If we iterate from left to right and place elements smaller than the pivot starting from the beginning (index `0`) of our new array, their relative order is automatically preserved.
* **Right-to-Left Pass for Larger Elements:** Similarly, if we iterate from right to left and place elements larger than the pivot starting from the end (index `n - 1`) of our new array, their relative order is also preserved (the rightmost larger element goes to the rightmost available spot, and so on).
* **Middle Section for Pivot Elements:** Any empty spaces left between the elements we placed from the left and right pointers must correspond to elements equal to `pivot`. We can simply fill this middle range with the `pivot` value.

This three-pointer simulation achieves stable partitioning in a single, clean sweep without using complex data structures or sorting.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$
  We perform a fixed number of linear passes over the array of size $N$. Specifically, one forward pass, one backward pass, and a final pass to fill the pivots in the remaining spaces. Each element is visited and placed exactly once, resulting in $\mathcal{O}(N)$ time.

- **Space Complexity:** $\mathcal{O}(N)$ (or $\mathcal{O}(1)$ auxiliary space)
  We utilize an output array of size $N$ to construct the rearranged array, which is required by the problem's return type. No other auxiliary space proportional to $N$ is used.

---