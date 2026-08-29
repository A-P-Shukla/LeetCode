# 2948. Make Lexicographically Smallest Array by Swapping Elements

### Metadata Table
| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Union Find, Sorting, Sliding Window |
| Date | 2026-08-29 |
| LeetCode Link | [Make Lexicographically Smallest Array by Swapping Elements](https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/) |

---

### Intuition

The problem allows us to swap any two elements $nums[i]$ and $nums[j]$ if $|nums[i] - nums[j]| \le limit$. 

Because swapping is a symmetric and transitive relation, if element $A$ can be swapped with $B$, and $B$ can be swapped with $C$, then $A$, $B$, and $C$ all belong to the same **connected component (or group)**. Any permutation of elements within the same group can be formed using valid swap operations.

To minimize the resulting array lexicographically, for each index $i$ in the original array, we should place the smallest available element from $nums[i]$'s connected component.

**Key Insight & Algorithm:**
1. **Sort & Group:** If we sort the values of `nums`, any two adjacent sorted numbers $x$ and $y$ belong to the same group if $y - x \le limit$. If $y - x > limit$, a new component must be started.
2. **Track Groups with Queues:** Because each group is formed from a sorted sequence, the elements within each group are naturally sorted in ascending order. We can store each group's elements in a queue (FIFO structure).
3. **Map Values to Groups:** Maintain a hash map/dictionary mapping each value to its corresponding group ID.
4. **Reconstruct Result:** Iterate through the original array `nums` from left to right. For each element `nums[i]`, determine its group ID via the map, pop the front (smallest available) element from that group's queue, and assign it to `result[i]`.

---

### Complexity Analysis

- **Time Complexity:** 
  - **Sorting:** $O(N \log N)$, where $N$ is the number of elements in `nums`.
  - **Grouping:** $O(N)$ to iterate through the sorted list and construct the queues.
  - **Reconstruction:** $O(N)$ to process each element in `nums` and perform $O(1)$ pop operations on the deques.
  - **Total Time Complexity:** $O(N \log N)$.

- **Space Complexity:** 
  - $O(N)$ auxiliary space to store the sorted copy of `nums`, group queues, hash map, and the output result array.

---