# 122. Best Time to Buy and Sell Stock II

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Dynamic Programming, Greedy |
| Date | May 31, 2026 |
| LeetCode Link | [https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) |

## Intuition

Unlike Stock I (at most one transaction), here we can make **unlimited transactions** but can hold at most one share at a time. The optimal strategy is a **greedy** one.

**Key insight:** Any profit from a multi-day holding can be decomposed into the sum of single-day profits. For example, buying on day 1 and selling on day 3 gives `prices[3] - prices[1] = (prices[2] - prices[1]) + (prices[3] - prices[2])`. So we can equivalently "buy and sell every day" — we just collect every positive day-over-day difference.

Formally, the maximum profit equals:
$$\sum_{i=1}^{n-1} \max(0,\ \text{prices}[i] - \text{prices}[i-1])$$

**Why greedy is optimal:** We never miss a profitable move (we take every positive increment) and we never take a losing move (we skip non-positive differences). No DP state is needed because past decisions don't constrain future ones — we can always buy and sell on the same day (zero profit) to "reset" our position.

## Complexity Analysis

- **Time Complexity:** $O(n)$ — a single pass through the prices array.
- **Space Complexity:** $O(1)$ — only a running profit accumulator.
