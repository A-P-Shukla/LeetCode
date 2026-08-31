# 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points

### Metadata Table
Property | Value
--- | ---
Difficulty | Medium
Topics | Linked List
Date | 2026-08-31
LeetCode Link | https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/

### Intuition

A **critical point** in a linked list is a node that is strictly greater than both its predecessor and successor (local maxima) or strictly smaller than both (local minima).

To solve this problem efficiently in a single pass:
1. Traverse the linked list using three pointers or references (`prev`, `curr`, and `curr.next`) while keeping track of the current node's index.
2. Whenever a critical point is identified:
   - Record the index of the **first** critical point found (`first_critical`).
   - Calculate the distance from the **immediately preceding** critical point (`prev_critical`) to update the running minimum distance (`minDistance = min(minDistance, curr_index - prev_critical)`).
   - Update `prev_critical` to the current index.
3. After completing the traversal:
   - If fewer than two critical points were found, return `[-1, -1]`.
   - The maximum distance is simply the difference between the last found critical point and the very first one: `prev_critical - first_critical`.
   - Return `[minDistance, maxDistance]`.

This strategy guarantees optimal time complexity by visiting each node exactly once and optimal space complexity by maintaining only a few tracking variables.

### Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the number of nodes in the linked list. We perform a single linear traversal over all nodes.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space. We only maintain constant extra space for pointers and index variables.