# 3296. Minimum Number of Seconds to Make Mountain Height Zero

Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Math, Binary Search, Greedy
Date | March 13, 2026
LeetCode Link | [https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/](https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/)

### Intuition
The problem asks for the minimum time required for multiple workers, working simultaneously, to reduce a mountain's height to zero. Each worker $i$ takes $workerTimes[i] \times (1 + 2 + \dots + x)$ seconds to reduce the height by $x$. This simplifies to the formula:
$$T_i = workerTimes[i] \times \frac{x(x+1)}{2}$$

Since the workers work simultaneously, we are looking for a time $T$ such that the sum of the heights reduced by all workers within time $T$ is at least `mountainHeight`. As $T$ increases, the total height workers can reduce also increases monotonically. This monotonicity indicates that we can use **Binary Search** on the answer (the time $T$).

For a fixed time $T$, we calculate the maximum height $x$ each worker $i$ can contribute by solving the quadratic inequality:
$$workerTimes[i] \times \frac{x(x+1)}{2} \le T \implies x^2 + x - \frac{2T}{workerTimes[i]} \le 0$$
Using the quadratic formula, the maximum integer $x$ is:
$$x = \left\lfloor \frac{-1 + \sqrt{1 + \frac{8T}{workerTimes[i]}}}{2} \right\rfloor$$

### Complexity Analysis
- **Time Complexity:** $O(N \log(\text{MaxTime}))$, where $N$ is the number of workers and $\text{MaxTime}$ is the upper bound of the search space (approximately $10^{16}$). In practice, $\log(10^{16}) \approx 54$, so the complexity is roughly $54 \times 10^4$ operations.
- **Space Complexity:** $O(1)$, as we only use a few variables for binary search and mathematical calculations.