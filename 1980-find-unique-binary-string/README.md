# 1980. Find Unique Binary String
| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Hash Table, String, Backtracking |
| Date | 2026-03-08 |
| LeetCode Link | https://leetcode.com/problems/find-unique-binary-string/ |

### Intuition
To solve this problem efficiently, we can leverage the Cantor's Diagonal Argument principle. We are given $n$ unique binary strings, each of length $n$. To construct a binary string of length $n$ that is guaranteed not to be in the input array, we can create a result string `res` such that for every index $i$ from $0$ to $n-1$, the $i$-th character of `res` is the opposite of the $i$-th character of the $i$-th string in the input array `nums`.

By setting `res[i] = (nums[i][i] == '0' ? '1' : '0')`, we guarantee that our constructed string differs from every string in the array by at least one character (the $i$-th character). Since there are $n$ such strings, this construction will always produce a valid answer that is not present in the input.

### Complexity Analysis
*   **Time Complexity:** O(n), where $n$ is the length of the input array (and the length of each string). We iterate through the array once to build the string.
*   **Space Complexity:** O(n) to store the resulting binary string of length $n$.
