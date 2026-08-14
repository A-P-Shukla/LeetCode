# 3090. Maximum Length Substring With Two Occurrences

### Metadata
Property | Value
--- | ---
Difficulty | Easy
Topics | Hash Table, String, Sliding Window
Date | August 14, 2026
LeetCode Link | https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/

---

### Intuition

The problem asks for the longest contiguous substring where no character appears more than twice. 

This requirement naturally fits the **Sliding Window (Two Pointers)** paradigm:
1. We maintain a dynamic window `[left, right]` and a frequency counter for the characters currently within this window.
2. We expand the window to the right by incrementing the frequency of `s[right]`.
3. If the frequency of `s[right]` exceeds $2$, the current window becomes invalid. To restore validity, we shrink the window from the `left` by decrementing character frequencies and moving `left` forward until the count of `s[right]` drops back to $2$.
4. At each step where the window is valid, we compute its length (`right - left + 1`) and update our maximum length found so far.

---

### Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the length of the string `s`. Both the `left` and `right` pointers traverse the string at most once, and frequency updates operate in $\mathcal{O}(1)$ time.
- **Space Complexity:** $\mathcal{O}(1)$ (or $\mathcal{O}(\Sigma)$ where $\Sigma = 26$). The frequency tracking array requires fixed space since the alphabet is limited to lowercase English letters.

---