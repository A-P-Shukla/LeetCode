# 3016. Minimum Number of Pushes to Type Word II

## Metadata Table

Property | Value
--- | ---
Difficulty | Medium
Topics | Hash Table, String, Greedy, Sorting, Counting
Date | July 31, 2026
LeetCode Link | https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/

## Intuition

To minimize the total number of key pushes needed to type a given word, we should use a **greedy strategy**. Letters that appear more frequently in `word` should require fewer pushes, while less frequent letters can accept more pushes.

There are 8 available keys (numbered 2 through 9). Each key can hold multiple characters:
- The 1st position on any key requires **1 push**.
- The 2nd position on any key requires **2 pushes**.
- The 3rd position on any key requires **3 pushes**.
- The 4th position on any key requires **4 pushes**.

Since we have 8 distinct keys, we can assign up to 8 distinct letters to the 1st position across these keys. Thus:
1. The **8 most frequent** letters should be assigned to the 1st position of the 8 keys (1 push each).
2. The **next 8 most frequent** letters should be assigned to the 2nd position (2 pushes each).
3. The **next 8 most frequent** letters should be assigned to the 3rd position (3 pushes each).
4. Any remaining letters (up to 2 characters, since there are 26 letters total) are placed in the 4th position (4 pushes each).

By counting letter frequencies, sorting them in descending order, and multiplying each frequency by its respective push cost based on its rank, we achieve the minimum possible number of key pushes.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the length of the string `word`. Counting character frequencies takes $\mathcal{O}(N)$ time. Sorting the frequency array of size 26 takes constant time $\mathcal{O}(26 \log 26) = \mathcal{O}(1)$. Therefore, the overall time complexity is linear, $\mathcal{O}(N)$.
- **Space Complexity:** $\mathcal{O}(1)$. The frequency map/array only stores up to 26 lowercase English letters, requiring constant auxiliary space.