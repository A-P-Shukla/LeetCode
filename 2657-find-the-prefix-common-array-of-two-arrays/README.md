# 2657. Find the Prefix Common Array of Two Arrays

### Metadata Table
Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Hash Table, Bit Manipulation
Date | 2026-05-20
LeetCode Link | [LeetCode - Find the Prefix Common Array of Two Arrays](https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/)

---

### Intuition

The problem asks us to find the number of common elements in the prefixes of two permutations $A$ and $B$ up to each index $i$.

Since $A$ and $B$ are permutations of the integers from $1$ to $n$, each number appears exactly once in $A$ and exactly once in $B$. This property is key:
- As we iterate through the arrays from left to right, we encounter new elements $A[i]$ and $B[i]$ at each step $i$.
- We can track how many times we have seen each number using a frequency array (or hash map).
- Since each number exists at most once in $A$ and at most once in $B$, any number can be seen at most **twice** across both prefixes.
- If the frequency of $A[i]$ or $B[i]$ becomes $2$ after being processed, it means that this number has now appeared in both $A$'s prefix and $B$'s prefix. Thus, we can increment our count of common elements.
- By keeping a running count of these "common" elements, we can build the result array $C$ in a single pass.

---

### Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$
  We iterate through the arrays of length $N$ exactly once. Inside the loop, we perform $\mathcal{O}(1)$ array lookups and updates.
  
- **Space Complexity:** $\mathcal{O}(N)$
  We use a frequency array of size $N + 1$ to keep track of the occurrences of each integer. The output array $C$ also takes $\mathcal{O}(N)$ space.

---