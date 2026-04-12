## 1320. Minimum Distance to Type a Word Using Two Fingers

| Property | Value |
| --- | --- |
| Difficulty | Hard |
| Topics | String, Dynamic Programming |
| Date | April 12, 2026 |
| LeetCode Link | [Minimum Distance to Type a Word Using Two Fingers](https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/) |

## Intuition
The problem asks for the minimum movement distance to type a word using two fingers. At any given point in the typing process, we need to know the current positions of both fingers to make an optimal decision. 

A crucial observation is that after typing the $i$-th character of the word, one of the two fingers **must** be at the position of `word[i]`. This allows us to reduce the state of our Dynamic Programming (DP) model. Instead of tracking two arbitrary positions $(pos1, pos2)$, we track the current character index $i$ and the position of the "other" finger (the one that didn't just type `word[i]`).

The state can be defined as `dp[i][other_pos]`, representing the minimum distance to type the remaining part of the word starting from index $i$, given that one finger is currently at `word[i-1]` and the other finger is at `other_pos`.

Special handling is needed for the initial state where a finger is "off-board." Moving a finger from the off-board state to any key costs zero distance.

## Complexity Analysis
- **Time Complexity:** $O(N \cdot \Sigma)$, where $N$ is the length of the word (up to 300) and $\Sigma$ is the alphabet size (26). For each character in the word, we iterate through all possible positions of the other finger.
- **Space Complexity:** $O(N \cdot \Sigma)$ to store the DP table. This can be optimized to $O(\Sigma)$ since each step only depends on the previous step, but the $O(N \cdot \Sigma)$ approach is well within memory limits.
