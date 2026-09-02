# [Construct Array with All Odd or All Even Elements]

### Metadata Table
Property | Value
--- | ---
Difficulty | Easy
Topics | Array, Math, Greedy
Date | September 02, 2026
LeetCode Link | https://leetcode.com/

---

### Intuition

The problem asks whether we can transform an array `nums1` into `nums2` such that all elements in `nums2` are either **all odd** or **all even**. For each index `i`, we can either keep `nums2[i] = nums1[i]` or set `nums2[i] = nums1[i] - nums1[j]` for some index $j \neq i$.

Let's analyze the parity rules of arithmetic operations:
- $\text{Even} - \text{Odd} = \text{Odd}$
- $\text{Odd} - \text{Even} = \text{Odd}$
- $\text{Even} - \text{Even} = \text{Even}$
- $\text{Odd} - \text{Odd} = \text{Even}$

Now consider the composition of the input array `nums1`:

1. **Case 1: `nums1` contains NO odd numbers (all elements are even).**
   - We can simply set `nums2[i] = nums1[i]` for all $i$.
   - Every element in `nums2` remains Even, which satisfies the condition (all even).

2. **Case 2: `nums1` contains AT LEAST ONE odd number.**
   - Let $j$ be the index of any odd element in `nums1`.
   - For every index $i$ where `nums1[i]` is **Odd**, we set `nums2[i] = nums1[i]` (it stays Odd).
   - For every index $i$ where `nums1[i]` is **Even**, we choose the odd element `nums1[j]` and set `nums2[i] = nums1[i] - nums1[j]`.
   - Since `nums1[i]` is Even and `nums1[j]` is Odd, $i \neq j$ is guaranteed. Subtraction gives $\text{Even} - \text{Odd} = \text{Odd}$.
   - As a result, every element in `nums2` becomes Odd, which satisfies the condition (all odd).

Since any given array `nums1` must fall into either Case 1 or Case 2, **it is always possible** to construct `nums2`. Therefore, the answer is unconditionally `true`.

---

### Complexity Analysis

- **Time Complexity:** $\mathcal{O}(1)$ — The condition is mathematically proven to be satisfied for any valid input array, requiring zero iterations or operations.
- **Space Complexity:** $\mathcal{O}(1)$ — No additional memory or state storage is needed.

---