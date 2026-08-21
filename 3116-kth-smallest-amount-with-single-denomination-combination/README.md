# 3116. Kth Smallest Amount With Single Coin Combination

| Property | Value |
| --- | --- |
| Difficulty | Hard |
| Topics | Array, Math, Binary Search, Bitmask, Combinatorics, Number Theory |
| Date | August 21, 2026 |
| LeetCode Link | [LeetCode 3116](https://leetcode.com/problems/kth-smallest-amount-with-single-coin-combination/) |

## Intuition

The problem asks for the $k$-th smallest amount that can be formed using a single coin denomination from a given list `coins`. This means we are looking for the $k$-th smallest integer that is a multiple of **at least one** integer in `coins`.

Because $k$ can be as large as $2 \times 10^9$, constructing the multiples directly or using a min-heap would exceed time and memory limits. Instead, we can observe that:
1. The property *"count of valid amounts $\le x$"* is **monotonically increasing** with respect to $x$. This makes the problem ideal for **Binary Search**.
2. To count how many numbers $\le x$ are divisible by at least one coin in our array, we can use the **Inclusion-Exclusion Principle (IEP)**.

### Inclusion-Exclusion Principle
For a set of coins $C$, the number of multiples $\le x$ of at least one coin is given by:
$$\text{Count}(x) = \sum_{S \subseteq C, S \neq \emptyset} (-1)^{|S| - 1} \left\lfloor \frac{x}{\text{lcm}(S)} \right\rfloor$$

Given that the maximum number of coins is very small ($N \le 15$), $2^{15} = 32,768$ subsets exist. We can evaluate this counting function efficiently in $O(2^N)$ time per binary search check. Furthermore, we can prune redundant coins (e.g., if we have coin 3, a coin of denomination 6 or 9 is redundant because all multiples of 6 or 9 are already multiples of 3).

## Complexity Analysis

- **Time Complexity:** 
  - **Coin Filtering:** $O(N \log N + N^2)$ to sort and remove redundant multiples.
  - **Binary Search Range:** High bound is $O(\min(\text{coins}) \cdot k)$. The range size is bounded by $25 \times 2 \cdot 10^9 = 5 \cdot 10^{10}$, requiring $\approx \log_2(5 \cdot 10^{10}) \approx 36$ steps.
  - **Per Evaluation:** IEP processes at most $2^{N'}$ subsets, where $N' \le N \le 15$.
  - **Total Time Complexity:** $O(N \log N + 2^{N'} \cdot \log(\min(\text{coins}) \cdot k))$. With $2^{15} \approx 32,768$, the total operations per query are around $36 \times 32768 \approx 1.18 \times 10^6$, which easily runs well within execution limits.

- **Space Complexity:** $O(2^{N'})$ to store precomputed subset Least Common Multiples (LCMs) or $O(N)$ if computed iteratively.

---