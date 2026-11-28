# 3947. Maximum Number of Items From Sale II

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Greedy, Sorting, Heap (Priority Queue) |
| Date | 2026-11-28 |
| LeetCode Link | https://leetcode.com/problems/maximum-number-of-items-from-sale-ii/ |

## Intuition & Approach

This is a variant of the classic Knapsack problem with the additional twist of post-purchase rewards (free items). A greedy strategy alone isn't sufficient due to these interdependencies. We must consider both the item's cost-efficiency for direct purchase and its potential to unlock free items. Let's break this down systematically.

Firstly, let’s reframe the problem constraints to understand the structure clearly:

1. Each item has an associated `factor` and `price`.
2. Purchasing any quantity of an item costs directly (`quantity * price`).
3. For each item `i`, purchasing it can yield **at most one free copy** of another distinct item `j`, granted that `factor_i` divides `factor_j`.
4. The reward relationship `(i → j)` can only be used **once per i-type purchase**, even if multiple units of item `i` are bought.

Our objective is to maximize total items (purchased + free), respecting the budget constraint. This necessitates an approach combining optimization and careful accounting of dependencies among items.

### Naive Greedy Strategies Fail

Attempting to solve it greedily by choosing cheap items or sorting items by their price-to-factor ratios leads to suboptimal results. Why? Because selecting an expensive but highly generative item (one unlocking several other items) might result in better overall outcomes than repeatedly purchasing cheaper standalone ones. Therefore, the order in which we process items affects possible gains.

### Optimal Strategy Using Priority Queues

A smarter way is to use two heaps — a max heap storing items based on net gain when selected optimally (including future benefits through free items), complemented by a min-cost priority mechanism helping us prioritize low-cost entries early.

However, the trick lies in preprocessing dependencies first so that we know which items trigger rewards for others.

#### Step-by-step Plan:

1. **Preprocessing Dependency Graph**:  
   Build adjacency list mapping each factor `f` to all items whose factors it divides (excluding itself). This prepares information needed later during item evaluation.

2. **Initialize Heaps**:
   - Use a max heap to store tuples of `(net_benefit, cost, item_id)` prioritizing beneficial selections.
   - Alternatively, since computing benefit dynamically becomes unwieldy, sort items cleverly instead using a hybrid greedy technique:
     Sort items by ascending price to encourage earlier processing of potentially more rewarding yet affordable candidates.

3. **Greedy Selection Loop Over Sorted Inputs**:
   - Pick next lowest priced item. Calculate how many full units fit into remaining budget.
   - Add those purchases into our count and update budget accordingly.
   - Then activate its corresponding rewards exactly once per unique eligible item target.
       - Count rewarded items and remove them from availability tracking to enforce rule “each link usable at-most-once”.

4. **Final Accumulation**:  
   Sum up original purchases plus collected rewards as final output.

This plan ensures linear passes while leveraging key insights about factor relationships efficiently.

We adopt a simpler but efficient implementation via precomputing divisors graph followed by sorted iteration.

Let's finalize logic.

### Implementation Details:

1. Precompute factor-based edges (i.e., map each item's factor to indices it can unlock).
2. Sort items by increasing price for greedy-like effect.
3. Traverse sorted list keeping track of:
   - total spent,
   - total bought quantities,
   - unlocked rewards tracked carefully.
4. Return cumulative sum.

Time complexity dominated by sorting and sparse divisor checks, leading to manageable performance under limits.

## Complexity Analysis

Assume N items with maximum factor F <= N.

- Time complexity: $ O(N \log N + NF) $
    - Sorting takes $ O(N \log N) $. 
    - Constructing the directed dependency graph involves iterating over every item and listing numbers divisible by it up to F; for each item ~√F multiples exist.
    - Final loop processes N elements once and checks reward fulfillment status in constant time (via set lookups).

- Space complexity: $ O(NF) $
    - Storing graph mappings requires ~F connections per node hence O(NF). Other variables require O(N) additional storage.

Thus, within acceptable bounds for large datasets allowed by constraints.

## C++ Solution