# 3501. Maximize Active Section with Trade II

| Property | Value |
| --- | --- |
| Difficulty | Hard |
| Topics | Array, String, Binary Search, Segment Tree |
| Date | July 22, 2026 |
| LeetCode Link | [Maximize Active Section with Trade II](https://leetcode.com/problems/maximize-active-section-with-trade-ii/) |

---

### Intuition

The problem asks us to find the maximum number of active sections ('1's) in a substring $s[l \dots r]$ after performing **at most one trade**. A trade consists of:
1. Converting a contiguous block of '1's that is surrounded by '0's to '0's.
2. Converting a contiguous block of '0's that is surrounded by '1's to '1's.

Wait, looking at the augmented rule:
For a substring $s[l \dots r]$, we augment it with '1' at both ends to form $t = \text{'1'} + s[l \dots r] + \text{'1'}$. 
A trade in this augmented string effectively corresponds to picking a block of '0's surrounded by '1's (which becomes '1's) and removing a block of '1's surrounded by '0's (which becomes '0's). 

More precisely, if we don't do any trade, the number of active sections is simply the count of '1's in $s[l \dots r]$.
If we do a trade, we can pick any block of '0's inside $s[l \dots r]$ and turn them into '1's, while also turning a block of '1's into '0's. To maximize the gain, we want to convert a block of '0's (say of length $len_0$) into '1's, while getting rid of a block of '1's (say of length $len_1$) to satisfy the surrounding conditions.
Alternatively, the net change in the number of '1's can be analyzed through runs of alternating characters. 

Since we need to answer multiple range queries efficiently on a static string, we can precalculate prefix sums and use range queries (or segment trees/binary search) to find the optimal interval structures. 

---

### Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n + q \log n)$ where $n$ is the length of string $s$ and $q$ is the number of queries. We can precompute prefix sums and use binary search to locate the optimal boundaries for each query in logarithmic time.
- **Space Complexity:** $\mathcal{O}(n)$ to store prefix sums and auxiliary arrays for efficient range queries.

---