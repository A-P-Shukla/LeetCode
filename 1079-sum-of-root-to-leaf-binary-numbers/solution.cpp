/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /**
     * @brief Traverses the tree and calculates the sum of all root-to-leaf binary numbers.
     * @param root The root of the binary tree.
     * @return The total sum of all binary numbers formed by root-to-leaf paths.
     */
    int sumRootToLeaf(TreeNode* root) {
        return calculatePathSum(root, 0);
    }

private:
    /**
     * @brief Helper function using DFS to accumulate path values.
     * @param node Current node being visited.
     * @param currentSum The binary value accumulated from the root to the current node.
     * @return The sum of binary numbers for the subtree rooted at 'node'.
     */
    int calculatePathSum(TreeNode* node, int currentSum) {
        if (node == nullptr) {
            return 0;
        }

        // Shift current value left by 1 (multiply by 2) and add the current node's value
        // Using bitwise OR as an alternative to addition since node->val is 0 or 1
        currentSum = (currentSum << 1) | node->val;

        // If we reached a leaf node, return the accumulated path value
        if (node->left == nullptr && node->right == nullptr) {
            return currentSum;
        }

        // Otherwise, recursively sum the values from left and right children
        return calculatePathSum(node->left, currentSum) + calculatePathSum(node->right, currentSum);
    }
};