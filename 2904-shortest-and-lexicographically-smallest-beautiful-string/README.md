# 2904. Shortest and Lexicographically Smallest Beautiful String

Property | Value
--- | ---
Difficulty | Easy
Topics | String, Sliding Window, Prefix Sum
Date | August 26, 2026
LeetCode Link | [Shortest and Lexicographically Smallest Beautiful String](https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/)

## Intuition

A **beautiful substring** is defined as a contiguous substring containing exactly $k$ ones (`'1'`).

We need to find the **shortest** beautiful substring. If there are multiple beautiful substrings of this minimum length, we must return the **lexicographically smallest** one among them.

Notice a key mathematical property:
If a string containing $k$ ones starts or ends with a `'0'`, we can trim that `'0'` to produce a strictly shorter substring that still contains exactly $k$ ones. Therefore, any *shortest* beautiful substring must both **start** and **end** with `'1'`.

This leads to a straightforward observation:
1. Collect the 0-based indices of all `'1'` characters in the string $s$.
2. If the total count of `'1'`s is less than $k$, it is impossible to form a beautiful substring, so we return `""`.
3. Every potential candidate for the shortest beautiful substring containing $k$ ones must start at the $i$-th `'1'` and end at the $(i + k - 1)$-th `'1'`.
4. We can iterate over all valid start indices $i$, extract the candidate substring `s[ones[i] ... ones[i + k - 1]]`, and keep track of the overall optimal substring based on:
   - Shorter length first.
   - Lexicographically smaller string if lengths are equal.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N^2)$, where $N$ is the length of the string $s$. 
  - Finding the indices of `'1'` takes $\mathcal{O}(N)$ time.
  - There are at most $N - k + 1$ candidates of length at most $N$. Extracting and comparing candidate substrings takes $\mathcal{O}(N)$ time per candidate.
  - Overall time complexity is $\mathcal{O}(N^2)$, which is optimal given $N \le 100$.

- **Space Complexity:** $\mathcal{O}(N)$ to store the indices of `'1'` and candidate substrings.