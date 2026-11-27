# 3946. Maximum Number of Items From Sale I

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Dynamic Programming, Greedy |
| Date | 2026-11-27 |
| LeetCode Link | https://leetcode.com/problems/maximum-number-of-items-from-sale-i/ |

## Intuition & Approach
1. **Separate concerns** –  
   *Purchasing extra copies* only increases the total count proportionally to their price; it never influences the free‑copy rule.  
   *Free copies* are generated exclusively by the **set of distinct item types** bought at least once.  
   Therefore we can first decide **which item types** to “activate” (buy ≥1 copy) and afterwards spend any remaining budget on the cheapest item repeatedly.

2. **Quantify the contribution of an activated item** –  
   For an item `i` with factor `f_i` we receive one free copy of every other item `j` whose factor is a multiple of `f_i`.  
   Let  

   ```
   outdeg_i = |{ j ≠ i  |  f_i divides f_j }|
   ```

   Buying at least one copy of `i` yields:
   * 1 purchased copy of `i`
   * `outdeg_i` free copies (one per applicable `j`)

   Hence the **net gain** of activating `i` is  

   ```
   gain_i = 1 + outdeg_i
   ```

3. **0/1 knapsack formulation** –  
   Each item type can be activated **once** (subsequent copies give no extra free items).  
   We must choose a subset `S` with total purchase cost  

   ```
   cost_S = Σ_{i∈S} price_i   ≤   budget
   ```

   that maximizes  

   ```
   Σ_{i∈S} gain_i   +   floor((budget - cost_S) / min_price)
   ```

   The last term is the maximal number of additional copies we can buy of the globally cheapest item after paying for `S`.

   For every possible cost `c (0…budget)` we compute the maximal achievable `gain` using a classic 0/1 knapsack DP:
   ```
   dp[c] = maximum Σ gain_i with total price exactly c
   ```

4. **Answer extraction** –  
   For each reachable cost `c` we add the free extra copies obtainable with the remaining budget:
   ```
   total = dp[c] + (budget - c) / min_price
   ```
   The maximum over all `c` is the answer.  
   The case `c = 0` (activate no item) is naturally covered, yielding only cheap‑item purchases.

5. **Complexities** –  
   *Pre‑computing `outdeg_i`* is O(N²) (N ≤ 1000).  
   *Knapsack DP* runs in O(N·budget) (budget ≤ 1500).  
   Both are well within limits.

## Complexity Analysis
- **Time Complexity:**  
  - Computing outdegrees: `O(N²)`  
  - 0/1 knapsack DP: `O(N·budget)`  
  Overall `O(N² + N·budget)` ≤ `~2·10⁶` operations.

- **Space Complexity:**  
  - `outdeg` & `gain` arrays: `O(N)`  
  - DP array of size `budget+1`: `O(budget)`  
  Total `O(N + budget)` ≤ `~2500` integers.