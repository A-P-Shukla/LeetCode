# 3120. Count the Number of Special Characters I

Property | Value
--- | ---
Difficulty | Easy
Topics | Hash Table, String, Bit Manipulation
Date | May 26, 2026
LeetCode Link | [LeetCode - Count the Number of Special Characters I](https://leetcode.com/problems/count-the-number-of-special-characters-i/)

### Intuition
To solve this problem, we need to determine which characters in the alphabet appear in both lowercase and uppercase within the given string `word`. 

Since the English alphabet consists of only 26 letters, we can track the occurrence of each lowercase and uppercase character efficiently. 
1. Maintain two sets or tracking structures: one for lowercase characters and one for uppercase characters.
2. Iterate through each character in the string. If it is lowercase, record its presence. If it is uppercase, record its presence.
3. Finally, find the intersection of the letters that exist in both lowercase and uppercase forms and return the count of such unique characters.

We can optimize this further by using bitwise masks to achieve $O(1)$ auxiliary space. An integer has 32 bits, which is more than enough to store the presence of 26 letters (one bit per letter).

### Complexity Analysis
- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the length of the string `word`. We perform a single pass over the string to populate our tracking structures, and then a constant number of operations to compute the intersection.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space. The storage required for the bitmasks (or alphabet-sized tracking structures) is independent of the input size $N$ and bounded by the alphabet size (26).
