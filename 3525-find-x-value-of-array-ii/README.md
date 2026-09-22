# [3480. Maximize Subarrays After Removing One Conflicting Pair / Prefix-Suffix Modulo Product Queries]

## Title: 3480. Find Subarray Product Modulo K Count (X-Value Modulo K Queries)

### Metadata Table
Property | Value
--- | ---
Difficulty | Hard
Topics | Array, Segment Tree, Math
Date | 2026-09-22
LeetCode Link | [LeetCode Problem](https://leetcode.com/problems/maximize-subarrays-after-removing-one-conflicting-pair/)

---

### Intuition

The problem asks us to process a set of queries on an array `nums`. Each query updates an element at a given index (persistently) and then asks for the count of valid suffix removals from a modified prefix-trimmed array such that the remaining non-empty subarray has a product modulo $k$ equal to $x_i$.

In other words, given a starting index $start_i$, we need to count how many end indices $R \in [start_i, n-1]$ satisfy:
$$\left( \prod_{m = start_i}^{R} \text{nums}[m] \right) \pmod k = x_i$$

Since $k$ is extremely small ($1 \le k \le 5$), we can maintain the modulo $k$ prefix product information using a **Segment Tree**.

Each segment tree node covering a range $[L, R]$ maintains:
1. `prod`: The total product of all elements in $[L, R]$ modulo $k$.
2. `cnt`: An array of size $k$, where `cnt[rem]` stores the number of non-empty prefixes of $[L, R]$ whose relative product modulo $k$ equals `rem`.

When merging two nodes (left and right subsegment):
- The combined segment product is $(\text{left.prod} \times \text{right.prod}) \pmod k$.
- The prefix counts from the left node directly transfer over.
- The prefix counts from the right node are multiplied by $\text{left.prod}$ modulo $k$ and added to the respective relative product buckets.

To answer a query starting at $start_i$, we traverse the range $[start_i, n-1]$ in the segment tree from left to right while keeping a running prefix product modulo $k$ (initialized to 1). For every canonical node in the query range, we match its internal prefix remainders with the running product to check if $(\text{running\_prod} \times \text{rem}) \pmod k == x_i$.

---

### Complexity Analysis

- **Time Complexity:** 
  - **Build:** $\mathcal{O}(N \cdot k)$ to construct the segment tree.
  - **Updates:** Each point update takes $\mathcal{O}(k \log N)$ time.
  - **Queries:** Range query covers $\mathcal{O}(\log N)$ canonical nodes. At each node, we perform $\mathcal{O}(k)$ operations. Thus, each query takes $\mathcal{O}(k \log N)$ time.
  - **Total Time Complexity:** $\mathcal{O}(N \cdot k + Q \cdot k \log N)$, where $N$ is the length of `nums`, $Q$ is the number of queries, and $k \le 5$. This executes in under 0.1 seconds.

- **Space Complexity:** $\mathcal{O}(N \cdot k)$ auxiliary space to store the Segment Tree structure.

---