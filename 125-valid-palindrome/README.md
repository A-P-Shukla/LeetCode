# 125. Valid Palindrome

| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | Two Pointers, String |
| Date | May 31, 2026 |
| LeetCode Link | [https://leetcode.com/problems/valid-palindrome/](https://leetcode.com/problems/valid-palindrome/) |

## Intuition

A palindrome reads the same forwards and backwards when considering only alphanumeric characters in lowercase. The **two-pointer** approach checks this directly without building a filtered string.

**Algorithm:**
- Place `left` at the start and `right` at the end of the string.
- Skip non-alphanumeric characters on both sides.
- Compare the lowercased characters at both pointers.
- If they differ, return false. If they match, advance both pointers inward.
- If the pointers meet or cross, the string is a palindrome.

**Why skip non-alphanumeric:** The problem defines "alphanumeric characters only", so spaces, punctuation, and other characters are ignored entirely.

**Python alternative:** Filter the string to alphanumeric lowercase characters, then compare with its reverse (`filtered == filtered[::-1]`). This is $O(n)$ time but $O(n)$ space — cleaner to read but less space-efficient than the two-pointer approach.

## Complexity Analysis

- **Time Complexity:** $O(n)$ — each character is examined at most once.
- **Space Complexity:** $O(1)$ for the C++ two-pointer approach; $O(n)$ for the Python filtered-list approach.
