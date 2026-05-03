# 796. Rotate String

| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | String, String Matching |
| Date | May 3, 2026 |
| LeetCode Link | [https://leetcode.com/problems/rotate-string/](https://leetcode.com/problems/rotate-string/) |

## Intuition

The problem asks whether a string `s` can be transformed into a string `goal` by shifting characters from the front to the back. A "shift" is essentially a cyclic rotation.

The key observation for cyclic rotations is that any rotation of a string `s` is a substring of `s + s`. 
For example, if `s = "abcde"`, then `s + s = "abcdeabcde"`.
The possible rotations are:
1. `abcde` (index 0 to 4)
2. `bcdea` (index 1 to 5)
3. `cdeab` (index 2 to 6)
4. `deabc` (index 3 to 7)
5. `eabcd` (index 4 to 8)

By concatenating `s` with itself, we capture every possible cyclic shift in a single search space. Therefore, the problem reduces to two simple conditions:
1. The lengths of `s` and `goal` must be equal.
2. `goal` must be a substring of `s + s`.

## Complexity Analysis

- **Time Complexity:** $O(N)$, where $N$ is the length of string `s`. String concatenation takes $O(N)$, and the substring search algorithm (like KMP or highly optimized built-in search functions) generally runs in $O(N)$ time on average.
- **Space Complexity:** $O(N)$ because we create a new string of length $2N$ to perform the search.