# 41. First Missing Positive

| Property | Value |
| --- | --- |
| Difficulty | Hard |
| Topics | Array, Hash Table |
| Date | May 31, 2026 |
| LeetCode Link | [https://leetcode.com/problems/first-missing-positive/](https://leetcode.com/problems/first-missing-positive/) |

## Intuition

The problem requires $O(n)$ time and $O(1)$ space, ruling out sorting ($O(n \log n)$) and a separate hash set ($O(n)$ space). The key insight is: **the answer must lie in the range $[1, n+1]$** for an array of length $n$. This means we only care about values in $[1, n]$ — everything else is irrelevant.

We use the array itself as a hash map via **Cyclic Sort (Index Mapping):**
- For each value $v$ in $[1, n]$, place it at index $v - 1$.
- After rearranging, scan the array: the first index $i$ where `nums[i] != i + 1` means $i + 1$ is missing.
- If all positions are correctly filled, the answer is $n + 1$.

**Why the cyclic sort is $O(n)$:** Each element is swapped at most once — once a value reaches its correct index, it is never moved again. The total number of swaps across the entire loop is bounded by $n$.

**Why the answer is at most $n+1$:** With $n$ slots for values $1$ through $n$, if all of $1, 2, \ldots, n$ are present, the first missing positive is $n+1$.

## Complexity Analysis

- **Time Complexity:** $O(n)$ — the cyclic sort performs at most $n$ swaps total, and the final scan is $O(n)$.
- **Space Complexity:** $O(1)$ — the array is rearranged in-place with no auxiliary storage.
