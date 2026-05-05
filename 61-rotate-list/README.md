# 61. Rotate List

### Metadata Table
Property | Value
--- | ---
Difficulty | Medium
Topics | Linked List, Two Pointers
Date | May 5, 2026
LeetCode Link | [https://leetcode.com/problems/rotate-list/](https://leetcode.com/problems/rotate-list/)

### Intuition
The problem asks us to shift a linked list to the right by $k$ places. Shifting a list by its length $n$ results in the same list. Therefore, the actual number of rotations we need to perform is $k \pmod n$. 

To efficiently perform this rotation, we can visualize the list as a ring. If we connect the tail of the list to the head, we create a circular linked list. Rotating the list then becomes a matter of breaking this circle at the correct position. 

If we shift the list right by $k$ positions, the new head will be at the $(n - k)$-th position (using 1-based indexing) from the original start, and the new tail will be the node immediately preceding it. 

The algorithmic steps are:
1. Handle edge cases: if the list is empty, has one node, or $k=0$, return the head.
2. Traverse the list to find its length $n$ and locate the original tail node.
3. Since $k$ can be larger than $n$, calculate the effective rotation: $k = k \pmod n$. If $k = 0$, the list remains unchanged.
4. Link the tail node to the head node to form a circle.
5. Move $n - k - 1$ steps from the original tail to find the new tail of the rotated list.
6. Identify the new head (the node after the new tail), break the circular link by setting the new tail's `next` to `nullptr`, and return the new head.

### Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of nodes in the linked list. We traverse the list once to find the length and tail, and then at most another $N$ steps to find the new split point.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for pointers.