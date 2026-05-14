# 2784. Check if Array is Good

| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | Array, Hash Table, Sorting |
| Date | May 14, 2026 |
| LeetCode Link | [https://leetcode.com/problems/check-if-array-is-good/](https://leetcode.com/problems/check-if-array-is-good/) |

## Intuition

The problem defines a "good" array as a permutation of a base array `base[n] = [1, 2, ..., n-1, n, n]`. 

Key observations:
1. **Length Relationship**: The length of `base[n]` is always $n + 1$. Therefore, if we are given an array `nums`, the value of $n$ must be `nums.length - 1`.
2. **Value Constraints**: A "good" array of length $L$ must contain:
   - The values $1$ through $n-1$ exactly once.
   - The value $n$ exactly twice.
   - No values greater than $n$ or less than $1$.

To solve this efficiently, we can use a frequency count (hash map or array) to track the occurrences of each number. Alternatively, sorting the array allows for a simple linear comparison against the expected sequence. Given the small constraints ($N \le 100$), a frequency array is highly efficient and provides $O(N)$ time complexity.

## Complexity Analysis

- **Time Complexity**: $O(N)$, where $N$ is the length of the input array. We iterate through the array once to count frequencies and once through the frequency table to validate requirements.
- **Space Complexity**: $O(N)$ to store the frequency counts. Given the constraints (max value 200), this can also be viewed as $O(1)$ constant space relative to the problem limits.