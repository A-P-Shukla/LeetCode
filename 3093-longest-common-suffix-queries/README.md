# 3093. Longest Common Suffix Queries


Property | Value
--- | ---
Difficulty | Hard
Topics | Array, String, Trie
Date | May 28, 2026
LeetCode Link | [Longest Common Suffix Queries](https://leetcode.com/problems/longest-common-suffix-queries/)

### Intuition
The problem asks us to find, for each query, a string from `wordsContainer` that shares the longest common suffix. If there are multiple candidates, we prefer the one with the shortest length. If there is still a tie, we prefer the one with the smallest index (earlier occurrence).

A suffix of a string is simply a prefix of the reversed string. Thus, the problem of finding the **longest common suffix** matches perfectly with a **Trie (Prefix Tree)** after reversing all the words.

1. **Reversed Insertions**: We insert all strings from `wordsContainer` into a Trie in reverse order (from last character to first character).
2. **Best Candidate Tracking**: Instead of just marking the end of a word in the Trie, we can store the `best_index` of a `wordsContainer` string at **every node** we traverse. 
   - A node's `best_index` represents the best index among all strings that share the prefix corresponding to that node (which translates back to the suffix in the original string).
   - The comparison rule for updating `best_index` at any node is straightforward:
     - If the node has no candidate yet, assign the current index `i`.
     - If the current string is strictly shorter than the one currently recorded at `best_index`, update the node's `best_index` to `i`.
     - If they have the same length, we keep the existing `best_index` because we process indices sequentially from `0` to `N - 1`, making the existing one naturally smaller.
3. **Querying**: For each query, we traverse the Trie in reverse. We follow the path as long as the characters match. The last successfully visited node contains the `best_index` for the longest matching suffix. If even the first character doesn't match, we fall back to the root's `best_index`, which correctly represents the overall best string (shortest, then smallest index) with an empty suffix `""`.

### Complexity Analysis

- **Time Complexity**: 
  - **Trie Insertion**: $\mathcal{O}(\sum |wordsContainer[i]|)$ since we insert each character of every word once.
  - **Trie Query**: $\mathcal{O}(\sum |wordsQuery[j]|)$ as we traverse at most the length of each query string.
  - **Total Time Complexity**: $\mathcal{O}(\sum |wordsContainer[i]| + \sum |wordsQuery[j]|)$, which is linear and optimal.

- **Space Complexity**: $\mathcal{O}(\sum |wordsContainer[i]| \cdot \Sigma)$ where $\Sigma = 26$ is the alphabet size. This accounts for storing the characters of all unique reversed prefixes in the Trie structure.