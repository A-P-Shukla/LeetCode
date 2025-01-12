//Simple Recursion:
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
    void levelOrderHelper(TreeNode* node, int level, vector<vector<int>>& result) {
        if (!node) return;
        if (level == result.size()) {
            result.push_back(vector<int>());
        }
        result[level].push_back(node->val);
        levelOrderHelper(node->left, level + 1, result);
        levelOrderHelper(node->right, level + 1, result);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>> result;
        levelOrderHelper(root, 0, result);
        return result;
    }
};
