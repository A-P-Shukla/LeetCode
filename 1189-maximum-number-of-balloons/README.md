# 1189. Maximum Number of Balloons

| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | Hash Table, String, Counting |
| Date | 2026-06-22 |
| LeetCode Link | https://leetcode.com/problems/maximum-number-of-balloons/ |

### Intuition

To form the word "balloon", we need specific counts of specific characters:
- 'b': 1
- 'a': 1
- 'l': 2
- 'o': 2
- 'n': 1

The bottleneck for forming the word is the character that limits the total count. For example, if we have plenty of 'b', 'a', and 'n', but very few 'l's or 'o's, the number of 'l's or 'o's will define the maximum number of times we can complete the word.

**Approach:**
1. Count the frequency of every character in the input `text`.
2. Determine how many times we can satisfy the requirement for each character type found in "balloon".
3. Since 'l' and 'o' appear twice in "balloon", we must divide their total count in the input string by 2 (integer division) before comparing them with the counts of 'b', 'a', and 'n'.
4. The maximum number of "balloon" instances is the minimum value among these calculated limits.

### Complexity Analysis

**Time Complexity:** O(N), where N is the length of the string `text`. We traverse the string once to count characters and then perform a constant number of operations (comparing values for the 5 unique characters in "balloon").

**Space Complexity:** O(1). While we use an array or hash map to store frequencies, the size is constrained to a fixed alphabet size (26 lowercase English letters), which is considered constant space.