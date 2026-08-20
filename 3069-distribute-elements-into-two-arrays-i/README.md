# 3069. Distribute Elements Into Two Arrays I

### Metadata Table
Property | Value
--- | ---
Difficulty | Easy
Topics | Array, Simulation
Date | August 20, 2026
LeetCode Link | [Distribute Elements Into Two Arrays I](https://leetcode.com/problems/distribute-elements-into-two-arrays-i/)

## Intuition
The problem asks us to simulate a specific process of distributing elements from an input array `nums` into two separate arrays, `arr1` and `arr2`, based on simple comparison rules, and then concatenate `arr2` onto `arr1`.

The rule set is as follows:
1. Place the first element (`nums[0]`) into `arr1`.
2. Place the second element (`nums[1]`) into `arr2`.
3. For each remaining element `nums[i]` from index 2 to `n - 1`:
   - Compare the last element appended to `arr1` (`arr1.back()`) with the last element appended to `arr2` (`arr2.back()`).
   - If `arr1.back() > arr2.back()`, append `nums[i]` to `arr1`.
   - Otherwise, append `nums[i]` to `arr2`.
4. Finally, append all elements of `arr2` to `arr1` to construct the final result.

Since the constraints on $n$ are small ($3 \le n \le 50$), a straightforward simulation using standard dynamic array structures (like `std::vector` in C++ or `list` in Python) will easily run well within time limits.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n)$, where $n$ is the length of `nums`. We iterate through `nums` starting from index 2 to $n-1$, performing $\mathcal{O}(1)$ operations (accessing the last element and appending) at each step. Concatenating `arr2` to `arr1` takes $\mathcal{O}(n)$ time.
- **Space Complexity:** $\mathcal{O}(n)$ to store the elements in `arr1` and `arr2`.

---