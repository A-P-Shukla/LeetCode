# 2126. Destroying Asteroids


Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Greedy, Sorting
Date | May 31, 2026
LeetCode Link | [https://leetcode.com/problems/destroying-asteroids/](https://leetcode.com/problems/destroying-asteroids/)

### Intuition
To maximize our chances of destroying all asteroids, we should adopt a **greedy** strategy. 

If we have a choice of which asteroid to collide with next, it is always optimal to choose the smallest available asteroid that we can successfully destroy. 
1. Smallest asteroids require the lowest minimum mass to be destroyed.
2. Once destroyed, they add to our planet's mass, making it easier to destroy larger asteroids in the next steps.

By sorting the `asteroids` array in non-decreasing (ascending) order, we can greedily process them from smallest to largest. If at any point the current mass of the planet is strictly less than the asteroid we are facing, it is impossible to progress further, and we return `false`. If we successfully iterate through all the asteroids, we return `true`.

*Note:* Since the sum of all asteroid masses can reach $10^{10}$ ($10^5 \text{ asteroids} \times 10^5 \text{ maximum mass}$), we must use a 64-bit integer (e.g., `long long` in C++) to prevent integer overflow during the accumulation of the mass.

### Complexity Analysis
- **Time Complexity:** $\mathcal{O}(N \log N)$ where $N$ is the number of asteroids. The dominating operation is sorting the `asteroids` array. The subsequent linear scan takes $\mathcal{O}(N)$ time.
- **Space Complexity:** $\mathcal{O}(1)$ or $\mathcal{O}(N)$ depending on the programming language's sorting algorithm implementation. In C++, `std::sort` uses $\mathcal{O}(\log N)$ stack space, while Python's Timsort uses up to $\mathcal{O}(N)$ space.