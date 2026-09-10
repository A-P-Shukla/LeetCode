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
private:
    int matchingNodesCount = 0;

    // Helper function returns pair<subtree_sum, subtree_count>
    pair<int, int> dfs(TreeNode* node) {
        if (!node) {
            return {0, 0};
        }

        // Compute subproblems for left and right subtrees
        auto [leftSum, leftCount] = dfs(node->left);
        auto [rightSum, rightCount] = dfs(node->right);

        // Aggregate results for current node
        int currentSum = leftSum + rightSum + node->val;
        int currentCount = leftCount + rightCount + 1;

        // Check condition (integer division automatically rounds down for non-negative integers)
        if (node->val == currentSum / currentCount) {
            matchingNodesCount++;
        }

        return {currentSum, currentCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        matchingNodesCount = 0;
        dfs(root);
        return matchingNodesCount;
    }
};