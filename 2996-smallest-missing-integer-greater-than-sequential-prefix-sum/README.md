# 2996. Smallest Missing Integer Greater Than Sequential Prefix Sum

### Metadata Table
Property | Value
--- | ---
Difficulty | Easy
Topics | Array, Hash Table
Date | August 11, 2026
LeetCode Link | https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/

### Intuition

The problem asks us to find the smallest integer $x \ge S$ missing from the array `nums`, where $S$ is the sum of the longest **sequential prefix** of `nums`.

1. **Find the Longest Sequential Prefix Sum ($S$):** 
   A sequential prefix starts at index `0`. We iterate through `nums` from index `1` onwards. As long as `nums[i] == nums[i - 1] + 1`, we include `nums[i]` in our sum $S$. The moment this condition fails, the sequential prefix ends, and we stop adding.

2. **Find the Smallest Missing Integer ($x$):**
   We can insert all elements of `nums` into a Hash Set to perform fast $O(1)$ lookups. Starting from candidate $x = S$, we check if $x$ exists in the Hash Set. If it does, we increment $x$ by `1` and repeat the check. The first $x$ that does not exist in the Hash Set is our answer.

### Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the number of elements in `nums`. 
  - Iterating to compute the sequential prefix sum takes $\mathcal{O}(N)$ time.
  - Inserting elements into a Hash Set takes $\mathcal{O}(N)$ time.
  - The loop to increment $x$ runs at most $N + 1$ times because `nums` contains at most $N$ distinct numbers.
  
- **Space Complexity:** $\mathcal{O}(N)$, required by the Hash Set to store up to $N$ unique values from `nums` for $O(1)$ lookup time.

---