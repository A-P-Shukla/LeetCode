# 3838. Weighted Word Mapping

| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | Array, String, Simulation |
| Date | 2026-06-13 |
| LeetCode Link | [Weighted Word Mapping](https://leetcode.com/problems/weighted-word-mapping/) |

### Intuition

The problem asks us to perform a straightforward simulation. For each word in the provided list, we need to calculate its total "weight" by summing the values of its individual characters as defined by the `weights` array. Once the total weight is calculated, we determine its position in reverse alphabetical order relative to a 26-character cycle.

1.  **Weight Calculation**: Since the character 'a' corresponds to index 0, 'b' to 1, and so on, we can map any character `c` to its weight using `weights[c - 'a']`. We iterate through each character of a word and accumulate these values.
2.  **Mapping to Character**: After finding the sum, we compute `remainder = sum % 26`. The problem specifies a mapping: `0 -> 'z', 1 -> 'y', ..., 25 -> 'a'`.
    *   Observation: This is equivalent to `char('z' - remainder)`. For example, if the remainder is 0, `'z' - 0 = 'z'`. If the remainder is 1, `'z' - 1 = 'y'`.
3.  **Result Construction**: We repeat this process for every word in the input list and append the resulting characters to a result string.

### Complexity Analysis

*   **Time Complexity**: $O(N \times L)$, where $N$ is the number of words and $L$ is the average length of a word. We iterate through every character of every word exactly once to compute its weight, and the modulo/mapping operations are performed in constant time $O(1)$ per word.
*   **Space Complexity**: $O(N)$ to store the resulting string of mapped characters. The auxiliary space used for calculations is $O(1)$.