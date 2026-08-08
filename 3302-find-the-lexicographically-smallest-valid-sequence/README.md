# 3302. Find the Lexicographically Smallest Valid Sequence

## Metadata
Property | Value
--- | ---
Difficulty | Medium
Topics | Two Pointers, String, Dynamic Programming, Greedy
Date | August 8, 2026
LeetCode Link | https://leetcode.com/problems/find-the-lexicographically-smallest-valid-sequence/

---

## Intuition

We are asked to construct a sequence of indices `seq` from `word1` of length `m` (`word2.length`) that matches `word2` with **at most 1 character mismatch**, such that the sequence of indices `seq` is **lexicographically as small as possible**.

To minimize the sequence of indices lexicographically, we must greedily choose the smallest possible index `seq[i]` at each step $i \in [0, m-1]$. 

Let's analyze what happens if the single allowed mismatch occurs at index $k \in [0, m-1]$:
1. For indices $0 \dots k-1$, characters must match `word2` exactly with $0$ mismatches. To minimize these indices, they must be matched **greedily from left to right**. Let `pref[j]` be the index in `word1` of the $0$-mismatch greedy match for `word2[0...j]`.
2. For index $k$, `word1[seq[k]]` is mismatched with `word2[k]`. The smallest valid index for `seq[k]` is `pref[k-1] + 1` (or $0$ if $k=0$).
3. For indices $k+1 \dots m-1$, characters must match `word2[k+1...m-1]` with $0$ mismatches. To check if `word2[k+1...m-1]` can fit after `seq[k]`, we can precompute the right-to-left $0$-mismatch matchings. Let `suf[j]` be the largest index in `word1` where `word2[j]` can be placed when matching `word2[j...m-1]` right-to-left.

Thus, a position $k$ can serve as a mismatch if and only if:
$$\text{seq}[k] = \text{pref}[k-1] + 1 < \text{suf}[k+1]$$

Using `pref`, `suf`, and a boolean array `valid_mismatch[k]`, we can determine at each position $i$ whether we can greedily take `last_idx + 1` (using our mismatch if `word1[last_idx + 1] != word2[i]`) or if we must defer the mismatch and match `word2[i]` exactly.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n + m)$ where $n = \text{word1.length}$ and $m = \text{word2.length}$.
  - Computing `pref` takes $\mathcal{O}(n + m)$ time using a two-pointer approach.
  - Computing `suf` takes $\mathcal{O}(n + m)$ time similarly.
  - The greedy construction iterates through `word2` and advances the `word1` pointer monotonically, taking $\mathcal{O}(n + m)$ time.
  - Since $m < n$, the overall time complexity is $\mathcal{O}(n)$.

- **Space Complexity:** $\mathcal{O}(m)$ auxiliary space to store the `pref`, `suf`, `valid_mismatch`, and `has_valid_suffix` arrays of size $\mathcal{O}(m)$.

---