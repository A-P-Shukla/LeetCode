//Using Recursion:
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int ledge = maxDepth(root->left);
        int redge = maxDepth(root->right);
        return 1+max(ledge,redge);
    }
};
