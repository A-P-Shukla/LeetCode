# 2095. Delete the Middle Node of a Linked List

Property | Value
--- | ---
Difficulty | Medium
Topics | Linked List, Two Pointers
Date | 2026-06-15
LeetCode Link | [https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/)

### Intuition

To delete the middle node of a linked list, we need to locate it efficiently. Since we cannot access nodes by index directly in a linked list, a standard approach is to traverse the list.

The most effective way to find the middle node is using the **"Fast and Slow Pointer"** (or Tortoise and Hare) pattern. 
1. We initialize two pointers, `slow` and `fast`, both starting at the head.
2. We move `fast` two steps at a time and `slow` one step at a time.
3. By the time `fast` reaches the end of the list, `slow` will be positioned at the middle node.

However, to delete a node in a singly linked list, we need a reference to the **previous node** of the one we want to remove. To achieve this, we can introduce a `prev` pointer that trails behind `slow`. Alternatively, a more elegant way is to start `fast` slightly ahead or adjust the loop condition so that `slow` stops just before the middle node.

### Complexity Analysis

*   **Time Complexity:** $O(N)$, where $N$ is the number of nodes in the linked list. We traverse the list exactly once.
*   **Space Complexity:** $O(1)$, as we only use a constant amount of extra space for pointers, regardless of the input list size.