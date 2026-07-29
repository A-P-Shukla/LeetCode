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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }

    pair<int, TreeNode*> dfs(TreeNode* node){
        if(!node) return {0, nullptr};

        auto [leftDepth, leftLCA] = dfs(node->left);
        auto [rightDepth, rightLCA] = dfs(node->right);

        if(leftDepth == rightDepth){
            return {leftDepth + 1, node};
        }
        else if(leftDepth > rightDepth){
            return {leftDepth + 1, leftLCA};
        }
        else{
            return {rightDepth + 1, rightLCA};
        }
    }
};