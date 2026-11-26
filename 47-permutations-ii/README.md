# 47. Permutations II

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Backtracking |
| Date | May 31, 2026 |
| LeetCode Link | [https://leetcode.com/problems/permutations-ii/](https://leetcode.com/problems/permutations-ii/) |

## Intuition

The array may contain duplicates, so naive backtracking would generate identical permutations. We need a pruning rule that eliminates duplicates without using a result set.

**The duplicate-skipping rule:**
After sorting, identical values are adjacent. At any recursion depth, if we are about to place `nums[i]` and `nums[i] == nums[i-1]` and `nums[i-1]` was **not** used in the current path, we skip `nums[i]`.

**Why this works:** The condition `!used[i-1]` means `nums[i-1]` was already tried (and fully explored) at this same recursion depth before being backtracked. Placing `nums[i]` (which equals `nums[i-1]`) at this position would produce the exact same subtree of permutations — so we skip it. Conversely, if `used[i-1]` is true, `nums[i-1]` is currently in the path at a *higher* level, meaning `nums[i]` is being placed at a different position, which is valid.

**Contrast with Permutations I:** The only addition is the two-line duplicate check. The rest of the backtracking structure is identical.

## Complexity Analysis

- **Time Complexity:** $O(n! \cdot n)$ in the worst case (all distinct). With $k$ groups of duplicates of sizes $c_1, c_2, \ldots, c_k$, the actual number of unique permutations is $\frac{n!}{c_1! \cdot c_2! \cdots c_k!}$, which is significantly smaller.
- **Space Complexity:** $O(n)$ — recursion stack, `path`, and `used` array.
