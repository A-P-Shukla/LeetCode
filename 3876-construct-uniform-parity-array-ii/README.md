# Construct Array with Equal Parity

## Metadata Table
Property | Value
--- | ---
Difficulty | Easy
Topics | Array, Math, Greedy
Date | September 3, 2026
LeetCode Link | [LeetCode - Construct Array with Equal Parity](https://leetcode.com/)

---

## Intuition

To determine if we can construct `nums2` such that all its elements share the same parity (all even or all odd), let's analyze the constraints placed on the elements:

1. **The Role of the Overall Minimum Element (`min_val`)**:
   - For any index `i`, we can either keep `nums1[i]` as is or replace it with `nums1[i] - nums1[j]` where `nums1[j] < nums1[i]`.
   - The overall minimum element in `nums1`, let's call it `min_val`, has no strictly smaller element `nums1[j]` in the array. Thus, `min_val` can **never** be modified via subtraction. Its parity in `nums2` is permanently fixed to its original parity in `nums1`.

2. **Can we make all elements ODD?**
   - If `min_val` is **odd**, every other element `x` in `nums1` is strictly greater than `min_val` (`x > min_val`).
   - If `x` is already odd, we can leave it as `x`.
   - If `x` is even, we can set `nums2[i] = x - min_val`. Since `even - odd = odd` and `x - min_val >= 1`, every even number successfully turns into a positive odd number!
   - Thus, if `min_val` is odd, we can **always** make all elements odd.

3. **Can we make all elements EVEN?**
   - To transform an odd number `O` into an even number, we must subtract a smaller odd number `O'` because `odd - odd = even`.
   - The **smallest odd number** in `nums1` has no smaller odd number available to subtract. Therefore, the smallest odd number can **never** become even.
   - Consequently, we can make all elements even **only if** there are no odd numbers in `nums1` in the first place (i.e., all elements are already even).

### Summary of Rules
- If `min_val` is **odd** $\rightarrow$ Return `true` (we can make everything odd).
- If **all elements are even** $\rightarrow$ Return `true` (we can make everything even).
- Otherwise $\rightarrow$ Return `false`.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the number of elements in `nums1`. We perform a single linear scan to find the minimum value and check the parity of elements.
- **Space Complexity:** $\mathcal{O}(1)$, as we only use a few auxiliary variables to track the minimum element and parity condition.

---