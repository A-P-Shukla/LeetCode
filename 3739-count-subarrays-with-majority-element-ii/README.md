# 3739. Count Subarrays With Majority Element II

| Property | Value |
| --- | --- |
| Difficulty | Hard |
| Topics | Array, Hash Table, Prefix Sum, Binary Indexed Tree |
| Date | 2026-06-26 |
| LeetCode Link | [https://leetcode.com/problems/count-subarrays-with-majority-element-ii/](https://leetcode.com/problems/count-subarrays-with-majority-element-ii/) |

### Intuition

To determine if `target` is the majority element in a subarray `nums[i..j]`, it must appear more than `(j - i + 1) / 2` times. Let $count(x)$ be 1 if `nums[x] == target` and -1 otherwise. The condition for the majority element becomes:
$$\sum_{k=i}^{j} \mathbb{I}(nums[k] == target) > \frac{j - i + 1}{2}$$
$$\sum_{k=i}^{j} \mathbb{I}(nums[k] == target) > \sum_{k=i}^{j} \frac{1}{2}$$
Multiplying by 2:
$$2 \sum_{k=i}^{j} \mathbb{I}(nums[k] == target) > \sum_{k=i}^{j} 1$$
$$\sum_{k=i}^{j} (2 \cdot \mathbb{I}(nums[k] == target) - 1) > 0$$

Let $v_k = 1$ if `nums[k] == target`, and $v_k = -1$ if `nums[k] != target`.
We define a prefix sum array $P$ where $P_0 = 0$ and $P_i = P_{i-1} + v_i$. The condition for a subarray `nums[i..j]` (0-indexed, $0 \le i \le j < n$) to have `target` as the majority is $P_{j+1} - P_i > 0$, or $P_{j+1} > P_i$.

The problem reduces to counting pairs $(i, k)$ such that $0 \le i < k \le n$ and $P_k > P_i$. This is equivalent to counting "inversions" but looking for pairs where the right element is greater than the left element. This can be solved efficiently using a Fenwick tree (Binary Indexed Tree) or Merge Sort in $O(N \log N)$ time. Since prefix sum values can range from $-N$ to $N$, we map them to positive indices by adding an offset of $N$.

### Complexity Analysis

*   **Time Complexity:** $O(N \log N)$. We iterate through the array to compute prefix sums ($O(N)$) and then use a Fenwick tree or a similar data structure to count valid pairs in $O(N \log N)$ time.
*   **Space Complexity:** $O(N)$. We store the prefix sums and the Fenwick tree array, both of which take $O(N)$ space.