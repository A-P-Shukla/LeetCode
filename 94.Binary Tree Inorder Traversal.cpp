//Simple Approach:
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
    void inorderTraverse(TreeNode* root, vector<int>& nums) {
        if (root == nullptr) {
            return;
        }
        inorderTraverse(root->left, nums);
        nums.push_back(root->val);
        inorderTraverse(root->right, nums);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nums;
        inorderTraverse(root, nums);
        return nums;
    }
};
