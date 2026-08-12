# 2958. Length of Longest Subarray With at Most K Frequency

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Hash Table, Sliding Window |
| Date | August 12, 2026 |
| LeetCode Link | [https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/](https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/) |

## Intuition

The problem asks for the length of the longest contiguous subarray where no element appears more than $k$ times. 

Since we are looking for a contiguous subarray that satisfies a condition that is monotonic with respect to window shrinking (if a window has all frequency counts $\le k$, shrinking it keeps all frequency counts $\le k$), a **Sliding Window (Two Pointers)** approach is ideal.

We maintain a dynamic window $[left, right]$ along with a frequency map tracking the count of each element within the current window:
1. We extend the window to the right by incrementing `right` and adding `nums[right]` to our frequency map.
2. If the frequency of `nums[right]` exceeds $k$, the current window becomes invalid (not "good"). To fix this, we shrink the window from the left by incrementing `left` and updating frequency counts until `nums[right]`'s frequency drops back down to $k$ or less.
3. At each valid state, we calculate the window size `right - left + 1` and update our maximum length recorded so far.

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the number of elements in `nums`. Both `right` and `left` pointers move across the array from $0$ to $N-1$ at most once. Hash map insertions, updates, and lookups take $\mathcal{O}(1)$ average time.
- **Space Complexity:** $\mathcal{O}(N)$, to store the frequency map of unique elements within the current window. In the worst case, all elements are unique.