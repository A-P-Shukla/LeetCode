from typing import List, Optional

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        val_to_node = {}
        children = set()

        for parent, child, is_left in descriptions:
            # Create nodes dynamically if they don't already exist
            if parent not in val_to_node:
                val_to_node[parent] = TreeNode(parent)
            if child not in val_to_node:
                val_to_node[child] = TreeNode(child)

            # Establish relationship
            if is_left == 1:
                val_to_node[parent].left = val_to_node[child]
            else:
                val_to_node[parent].right = val_to_node[child]

            # Mark this node as a child
            children.add(child)

        # The root is the only parent node that is never a child
        for parent in val_to_node:
            if parent not in children:
                return val_to_node[parent]

        return None