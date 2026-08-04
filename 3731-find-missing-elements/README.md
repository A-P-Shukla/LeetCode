# Find Missing Integers in Range

## Metadata Table
Property | Value
--- | ---
Difficulty | Easy
Topics | Array, Hash Table, Sorting
Date | August 4, 2026
LeetCode Link | https://leetcode.com/

## Intuition
The problem states that the original sequence consisted of consecutive integers spanning from a minimum value to a maximum value. Since the smallest and largest elements of this range are guaranteed to still be present in `nums`, the full intended range is strictly bounded by $[\min(\text{nums}), \max(\text{nums})]$.

To find the missing integers in this contiguous range:
1. Identify the lower bound ($\min(\text{nums})$) and upper bound ($\max(\text{nums})$).
2. Insert all elements of `nums` into a Hash Set (or lookup array) to allow for $O(1)$ presence checking.
3. Iterate through every integer $x$ from $\min(\text{nums})$ to $\max(\text{nums})$.
4. If $x$ is not present in the set, append it to our result list. Since we iterate in ascending order, the final list will automatically be sorted.

## Complexity Analysis
- **Time Complexity:** $\mathcal{O}(N + K)$, where $N$ is the number of elements in `nums` and $K = \max(\text{nums}) - \min(\text{nums}) + 1$ is the range length. Finding the minimum and maximum takes $\mathcal{O}(N)$ time, building the hash set takes $\mathcal{O}(N)$ time, and iterating through the range takes $\mathcal{O}(K)$ time.
- **Space Complexity:** $\mathcal{O}(N)$, to store the elements of `nums` in a hash set for $O(1)$ lookups (excluding the output array space).