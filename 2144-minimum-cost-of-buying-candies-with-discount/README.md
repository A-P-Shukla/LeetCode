# 2144. Minimum Cost of Buying Candies With Discount

### Property | Value
--- | ---
Difficulty | Easy
Topics | Array, Greedy, Sorting
Date | June 1, 2026
LeetCode Link | [Minimum Cost of Buying Candies With Discount](https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/)

---

### Intuition

The problem asks us to find the minimum cost to buy all the candies given a specific discount strategy: for every two candies we buy, we can get a third candy for free, provided the cost of the free candy is less than or equal to the minimum of the two purchased candies.

To minimize the overall cost, we want to maximize the cost of the candies we get for free. To do this, we should greedily choose the most expensive candies possible to be the "free" ones.

1. **Sorting**: Sort the candies in descending order of cost.
2. **Greedy Grouping**: Group the sorted candies into triplets: `(cost[i], cost[i+1], cost[i+2])`.
   - By buying the two most expensive candies in each triplet (`cost[i]` and `cost[i+1]`), we can get the third most expensive candy (`cost[i+2]`) for free since `cost[i+2] <= cost[i+1] <= cost[i]`.
3. **Summation**: Iterate through the sorted candies and sum up the costs, skipping every 3rd candy (at 0-indexed positions $2, 5, 8, \dots$, or when $i \pmod 3 == 2$).

### Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N \log N)$ where $N$ is the number of candies. This is because we need to sort the `cost` array. The subsequent linear scan takes $\mathcal{O}(N)$ time.
- **Space Complexity:** $\mathcal{O}(1)$ or $\mathcal{O}(N)$ depending on the language's built-in sorting algorithm. In C++, `std::sort` uses $\mathcal{O}(\log N)$ auxiliary space, whereas Python's Timsort uses up to $\mathcal{O}(N)$ auxiliary space.