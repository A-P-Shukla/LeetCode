# 46. Permutations

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Backtracking |
| Date | May 31, 2026 |
| LeetCode Link | [https://leetcode.com/problems/permutations/](https://leetcode.com/problems/permutations/) |

## Intuition

All integers are **distinct**, so every arrangement of the $n$ elements is a unique permutation. There are $n!$ permutations in total.

**Approach — Backtracking with `used` array:**
We build permutations one element at a time. At each recursion depth, we try every element that has not yet been placed in the current path. When the path reaches length $n$, we have a complete permutation.

The recursion tree has $n$ branches at depth 0, $n-1$ at depth 1, and so on — naturally generating all $n!$ permutations without duplicates (since all values are distinct).

**Alternative (C++ implementation):** Sort the array and repeatedly call `std::next_permutation` until it wraps around. This visits all $n!$ permutations in lexicographic order and is concise for distinct elements.

**Why backtracking is the canonical approach:** It generalises naturally to Permutations II (with duplicates) and other constrained permutation problems, making it the more instructive solution to understand.

## Complexity Analysis

- **Time Complexity:** $O(n! \cdot n)$ — there are $n!$ permutations and each takes $O(n)$ to copy into the result.
- **Space Complexity:** $O(n)$ — the recursion stack depth and the `path` / `used` arrays are all $O(n)$.
