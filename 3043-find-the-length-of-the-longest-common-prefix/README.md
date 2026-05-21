# 3043. Find the Length of the Longest Common Prefix

| Property | Value |
|---|---|
| Difficulty | Medium |
| Topics | Array, Hash Table, String, Trie |
| Date | May 21, 2026 |
| LeetCode Link | [Find the Length of the Longest Common Prefix](https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/) |

---

### Intuition

The problem asks us to find the longest common prefix between any number from `arr1` and any number from `arr2`. Since the maximum value of any element is $10^8$, each integer has at most 9 digits. 

A naive approach of comparing every pair `(x, y)` from `arr1` and `arr2` would result in $O(N \times M)$ comparisons, which is too slow given $N, M \le 5 \times 10^4$.

Instead of checking all pairs, we can decompose each number into all of its possible prefixes:
1. For any number $x$ (e.g., `12345`), its prefixes are `12345`, `1234`, `123`, `12`, and `1`.
2. We can generate and store all possible prefixes of the numbers in `arr1` in a Hash Set.
3. For each number $y$ in `arr2`, we check its prefixes starting from the longest. The first prefix of $y$ that exists in our Hash Set will represent the longest common prefix for that element.
4. We keep track of the maximum length of such matched prefixes across all elements in `arr2`.

This Hash Set approach is extremely efficient because the number of prefixes per number is bounded by a small constant ($\le 9$).

---

### Complexity Analysis

- **Time Complexity:** $\mathcal{O}((N + M) \log_{10}(\text{max\_val}))$, where $N$ and $M$ are the sizes of `arr1` and `arr2` respectively, and $\text{max\_val} \le 10^8$ is the maximum value in the arrays. Since $\log_{10}(\text{max\_val}) \le 9$, the logarithmic term is a small constant, making the time complexity practically linear $\mathcal{O}(N + M)$.
- **Space Complexity:** $\mathcal{O}(N \log_{10}(\text{max\_val}))$ to store the prefixes of elements from `arr1` in the Hash Set. Since each number yields at most 9 prefixes, the space complexity is $\mathcal{O}(N)$.

---
