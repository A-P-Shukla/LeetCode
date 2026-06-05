# 3753. Total Waviness of Numbers in Range II

### Property | Value
--- | ---
Difficulty | Hard
Topics | Math, Dynamic Programming
Date | June 5, 2026
LeetCode Link | [Total Waviness of Numbers in Range II](https://leetcode.com/problems/total-waviness-of-numbers-in-range-ii/)

---

## Intuition

The problem asks us to find the sum of "waviness" (the total number of peaks and valleys) for all integers in a given inclusive range $[num1, num2]$. Since the maximum value of $num2$ is $10^{15}$, we cannot iterate through each number individually. Instead, this problem is a classic candidate for **Digit Dynamic Programming**.

To find the answer in the range $[num1, num2]$, we can calculate the total waviness for numbers in $[1, num2]$ and subtract the total waviness for numbers in $[1, num1 - 1]$:
$$\text{totalWaviness}(num1, num2) = \text{solve}(num2) - \text{solve}(num1 - 1)$$

### The Digit DP State

When constructing numbers digit-by-digit from left to right, a peak or a valley at position $i$ (using $0$-based indexing of the active number) can only be confirmed once we know:
1. The digit at position $i-1$ (the left neighbor).
2. The digit at position $i$ (the current candidate).
3. The digit at position $i+1$ (the right neighbor).

Thus, when we are at index `idx` and choosing the digit `d` (which represents the right neighbor), we can evaluate if the previously chosen digit `prev1` (at `idx-1`) is a peak or a valley relative to its neighbors `prev2` (at `idx-2`) and `d`.

To correctly compute this, our DP state should track:
* `idx`: The current position in the string representation of $N$.
* `prev1`: The digit chosen at `idx - 1`.
* `prev2`: The digit chosen at `idx - 2`.
* `is_less`: A boolean flag indicating if the prefix we have constructed is already strictly less than the prefix of the limit $N$.
* `is_started`: A boolean flag indicating if we have placed at least one non-zero digit (used to ignore leading zeros, which do not contribute to waviness).

### Subproblem Contribution

Instead of just counting valid numbers, the DP needs to compute both:
1. The count of valid completed numbers from the current state.
2. The sum of waviness of all those completed numbers.

If a state transition adds a waviness of `waviness_add` (either `1` or `0`), it contributes `waviness_add * sub_count` to the cumulative waviness of the paths branching off from it.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(L \cdot 10^2 \cdot 2)$ where $L \approx 16$ is the maximum number of digits for $10^{15}$. The DP state space size is limited to $L \times 11 \times 11 \times 2 \approx 3,872$ states. For each state, we transition through at most $10$ choices. This results in under $40,000$ operations per query, which runs in less than $1$ millisecond.
- **Space Complexity:** $\mathcal{O}(L \cdot 10^2 \cdot 2)$ to store the memoization table. The recursion stack uses $\mathcal{O}(L)$ depth. Thus, auxiliary space is $\mathcal{O}(1)$ practically.

---