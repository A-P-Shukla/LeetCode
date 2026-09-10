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

            left_sum, left_cnt = dfs(node.left)
            right_sum, right_cnt = dfs(node.right)

            total_sum = left_sum + right_sum + node.val
            total_cnt = left_cnt + right_cnt + 1

            if node.val == total_sum // total_cnt:
                matching_count += 1

            return total_sum, total_cnt

        dfs(root)
        return matching_count