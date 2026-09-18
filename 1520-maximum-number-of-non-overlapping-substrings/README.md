# 1520. Maximum Number of Non-Overlapping Substrings

### Metadata Table
Property | Value
--- | ---
Difficulty | Hard
Topics | String, Greedy, Two Pointers, Prefix Sum
Date | September 18, 2026
LeetCode Link | [Maximum Number of Non-Overlapping Substrings](https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/)

## Intuition

The problem asks us to find the maximum number of non-overlapping valid substrings in a string `s`, minimizing total length in case of ties. A substring is valid if containing any character `c` implies containing **all** occurrences of `c` present in `s`.

### Key Insights:
1. **Interval Boundary Expansion**:
   For any character `c` that appears in `s`, any valid substring starting at `first[c]` must span at least from `first[c]` to `last[c]`. As we scan through the range `[L, R]`, any other character `x` inside this range expands the right boundary `R` to at least `last[x]`. 
   
2. **Early Invalidation**:
   If while expanding the interval `[L, R]` (where `L = first[c]`) we encounter a character `x` such that `first[x] < L`, then `first[c]` cannot be a valid starting index for a minimal valid substring. Including `c` forces us to include `x`, which extends further left than `L`.

3. **Interval Property (Nested vs Disjoint)**:
   A crucial property of valid substrings here is that two valid substrings cannot partially overlap. They are either completely disjoint or one is nested entirely inside the other. 

4. **Greedy Interval Scheduling**:
   Because intervals are either nested or disjoint, we can generate all valid candidate intervals `[L, R]`, sort them by their end indices `R` in ascending order, and greedily pick non-overlapping intervals. Sorting by end index `R` ensures that we always pick inner (shorter) substrings before outer (longer) ones, maximizing the count of substrings while naturally minimizing their total length.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the length of string `s`.
  - Computing `first` and `last` occurrence maps takes $\mathcal{O}(N)$ time.
  - Candidate generation iterates over at most $26$ distinct characters. Each character's interval expansion visits at most $N$ positions. Since alphabet size $\Sigma = 26$ is constant, this step takes $\mathcal{O}(\Sigma \cdot N) = \mathcal{O}(N)$ time.
  - Sorting at most $26$ candidate intervals takes $\mathcal{O}(\Sigma \log \Sigma) = \mathcal{O}(1)$ time.
  
- **Space Complexity:** $\mathcal{O}(N)$ to store the output substrings. Auxiliary space used for tracking bounds and candidate intervals is $\mathcal{O}(\Sigma) = \mathcal{O}(1)$.