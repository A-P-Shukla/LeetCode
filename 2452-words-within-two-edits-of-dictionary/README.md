# 2452. Words Within Two Edits of Dictionary

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, String, Enumeration |
| Date | April 22, 2026 |
| LeetCode Link | [https://leetcode.com/problems/words-within-two-edits-of-dictionary/](https://leetcode.com/problems/words-within-two-edits-of-dictionary/) |

## Intuition

The problem asks us to identify words in a `queries` list that can be transformed into any word in a `dictionary` list using at most two character substitutions. Since all strings in both lists have the same length $n$, the "edit" operation described is equivalent to calculating the **Hamming Distance** between two strings.

Given the constraints:
- Number of queries ($Q$) ≤ 100
- Number of dictionary words ($D$) ≤ 100
- Length of each word ($N$) ≤ 100

The total number of character comparisons in a brute-force approach would be approximately $Q \times D \times N$, which is $100 \times 100 \times 100 = 1,000,000$. This is well within the limits for a standard execution time (usually $10^7$ to $10^8$ operations per second).

Our approach is to:
1. Iterate through each word in `queries`.
2. For each query, iterate through every word in `dictionary`.
3. Compare the characters at each index. If the count of differing characters (mismatches) is 2 or less for any dictionary word, the query is valid.
4. Short-circuit: As soon as we find a match within 2 edits for a query, we can stop checking that query against the rest of the dictionary and move to the next query. Similarly, we can stop comparing two words if the mismatch count exceeds 2.

## Complexity Analysis

- **Time Complexity:** $O(Q \cdot D \cdot N)$, where $Q$ is the number of queries, $D$ is the number of words in the dictionary, and $N$ is the length of the strings. In the worst case, we compare every character of every query against every word in the dictionary.
- **Space Complexity:** $O(1)$ or $O(Q \cdot N)$ depending on whether you count the output list. The algorithm itself uses only a few integer variables for counting and indexing.