# 2914. Minimum Number of Changes to Make Binary String Beautiful

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | String |
| Date | 2026-11-18 |
| LeetCode Link | https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/ |

## Intuition & Approach
A *beautiful* binary string can be divided into substrings of **even** length, each consisting of **identical** characters.  
Consider any valid partition. If a block has length 4 (e.g., “1111”), it can be further split into two length‑2 blocks “11|11” without violating the definition. Hence the global condition reduces to:

> For every consecutive pair of positions `(2k, 2k+1)`, the two characters must be equal.

Therefore the problem is equivalent to fixing each adjacent pair independently.  
- If `s[2k] == s[2k+1]`, the pair already satisfies the requirement – no change needed.  
- If they differ, at least one character must be flipped to make them equal; flipping exactly one yields the minimal cost for that pair.

Summing the mandatory flips over all pairs yields the global minimum because pairs are independent (no cross‑pair constraints).

### Why more complex approaches fail
- **Dynamic programming over partitions** would treat overlapping subproblems, but the independence of pairs makes DP unnecessary and adds O(n) overhead with larger constant factors.
- **Greedy merging of larger blocks** does not improve the answer because any larger homogeneous block can be represented as a sequence of length‑2 homogeneous pairs, already captured by the pairwise view.

Thus the optimal strategy is a single linear scan counting mismatched pairs.

## Complexity Analysis
- **Time Complexity:** $O(n)$, where $n = |s|$, each character is examined exactly once in its pair.
- **Space Complexity:** $O(1)$, only a few integer variables are used irrespective of input size.