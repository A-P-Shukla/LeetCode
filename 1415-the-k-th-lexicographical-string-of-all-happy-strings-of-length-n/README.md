# 1415. The k-th Lexicographical String of All Happy Strings of Length n

Property | Value
--- | ---
Difficulty | Medium
Topics | String, Backtracking
Date | February 19, 2025
LeetCode Link | [https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/](https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/)

## Intuition

A "happy string" is defined by two constraints: it only uses characters from the set `{'a', 'b', 'c'}` and no two adjacent characters are identical. We are asked to find the $k$-th such string of length $n$ when sorted lexicographically.

Given the constraints ($n \le 10$, $k \le 100$), the total number of possible happy strings is relatively small. Specifically, for the first character, we have 3 choices ('a', 'b', or 'c'). For every subsequent position, we have 2 choices (the two characters from the set that are not equal to the previous character). Thus, the total number of happy strings of length $n$ is $3 \times 2^{n-1}$. For $n=10$, this is $3 \times 512 = 1536$, which is well within the limits to generate them using backtracking.

The approach involves:
1.  Using a recursive backtracking function to build strings character by character.
2.  Ensuring lexicographical order by trying 'a', then 'b', then 'c' at each step.
3.  Pruning the search by keeping a global counter and stopping as soon as the $k$-th string is found.
4.  If the search completes and we haven't reached the $k$-th string, returning an empty string.

## Complexity Analysis

- **Time Complexity:** $O(k \cdot n)$. In the worst case, we generate up to $k$ happy strings, each of length $n$. Since $k$ is small (up to 100) and $n$ is small (up to 10), this is highly efficient. Mathematically, the algorithm visits at most $k \times n$ states in the recursion tree before finding the answer or exhausting possibilities.
- **Space Complexity:** $O(n)$. The space complexity is determined by the recursion stack depth, which is $n$, and the string being constructed, which is also of length $n$.