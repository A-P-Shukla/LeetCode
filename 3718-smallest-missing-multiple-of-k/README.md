# Smallest Missing Multiple

| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | Array, Hash Table |
| Date | 2026-08-25 |
| LeetCode Link | https://leetcode.com/problems/smallest-missing-multiple/ |

## Intuition

The problem asks for the smallest positive multiple of $k$ that does not exist in the array `nums`.

A positive multiple of $k$ can be generated sequentially as $k, 2k, 3k, 4k, \dots$.
To efficiently check if a multiple exists in `nums`:
1. Convert `nums` into a Hash Set (or lookup table). This allows $O(1)$ time complexity for presence checks.
2. Start with `multiple = k` and check if it exists in the Hash Set.
3. If it exists, increment `multiple` by $k$ and repeat the check.
4. The moment we find a `multiple` that is not present in the set, we immediately return it as the answer.

Since the elements in `nums` are bounded, this lookup process will terminate very quickly.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the number of elements in `nums`. Inserting $N$ elements into a hash set takes $\mathcal{O}(N)$ time. The lookup loop runs at most $\frac{\max(\text{nums})}{k} + 1$ times, which takes $\mathcal{O}(1)$ time under the given constraints ($N \le 100$, $\text{nums}[i] \le 100$).
- **Space Complexity:** $\mathcal{O}(N)$ auxiliary space to store elements of `nums` in a hash set for constant time lookups.