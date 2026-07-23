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
    void inOrder(TreeNode* root, TreeNode*& ans, int k){
        int val = k;

        if(root == nullptr)
            return;

        inOrder(root->left, ans, val);
        if(root->val == val)
            ans = root;
        inOrder(root->right, ans, val);
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* ans = nullptr;
        inOrder(root, ans, val);
        return ans;
    }
};