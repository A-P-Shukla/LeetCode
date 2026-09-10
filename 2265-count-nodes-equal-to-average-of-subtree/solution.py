# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def averageOfSubtree(self, root: Optional[TreeNode]) -> int:
        matching_count = 0

        def dfs(node: Optional[TreeNode]) -> tuple[int, int]:
            nonlocal matching_count
            if not node:
                return 0, 0

            # Post-order traversal: collect data from left and right children
            left_sum, left_cnt = dfs(node.left)
            right_sum, right_cnt = dfs(node.right)

            # Calculate total sum and node count for current subtree
            total_sum = left_sum + right_sum + node.val
            total_cnt = left_cnt + right_cnt + 1

            # Check if node's value equals average of subtree (rounded down)
            if node.val == total_sum // total_cnt:
                matching_count += 1

            return total_sum, total_cnt

        dfs(root)
        return matching_count