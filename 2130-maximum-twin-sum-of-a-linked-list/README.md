# 2130. Maximum Twin Sum of a Linked List

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Linked List, Two Pointers, Stack |
| Date | 2026-06-14 |
| LeetCode Link | [https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/) |

### Intuition

To calculate the twin sum, we need to pair the first node with the last, the second with the second-to-last, and so on. In a singly linked list, we can easily access nodes moving forward, but accessing nodes from the end is inefficient.

The optimal approach involves three main steps:
1.  **Find the Middle:** Use the "Tortoise and Hare" algorithm (slow and fast pointers). The fast pointer moves two steps at a time, and the slow pointer moves one step. When the fast pointer reaches the end, the slow pointer will be at the start of the second half of the list.
2.  **Reverse the Second Half:** Reverse the second half of the list in-place. This allows us to traverse the second half starting from the end of the original list, effectively making it accessible as a standard traversal.
3.  **Calculate Twin Sums:** Use two pointers: one at the beginning of the list and one at the beginning of the reversed second half. Traverse both simultaneously, summing the values at each step and keeping track of the maximum.

This approach is highly space-efficient as it avoids using additional data structures like stacks or arrays, achieving constant auxiliary space complexity.

### Complexity Analysis

*   **Time Complexity:** O(N), where N is the number of nodes in the linked list. Finding the middle takes O(N/2), reversing the second half takes O(N/2), and calculating the maximum twin sum takes O(N/2). All are linear operations.
*   **Space Complexity:** O(1), as we are performing the reversal in-place and using only a fixed number of pointer variables regardless of the input size.