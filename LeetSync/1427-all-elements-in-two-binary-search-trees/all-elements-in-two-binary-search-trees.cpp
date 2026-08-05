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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        TreeNode* r1 = root1;
        TreeNode* r2 = root2;
        vector<int> res;

        while(r1 != nullptr || r2 != nullptr || !s1.empty() || !s2.empty()){
            while(r1 != nullptr){
                s1.push(r1);
                r1 = r1->left;
            }

            while(r2 != nullptr){
                s2.push(r2);
                r2 = r2->left;
            }

            if(s2.empty() || (!s1.empty() && s1.top() -> val <= s2.top() -> val)){
                TreeNode* temp = s1.top();
                s1.pop();
                res.push_back(temp -> val);
                r1 = temp -> right;
            }
            else{
                TreeNode* temp = s2.top();
                s2.pop();
                res.push_back(temp -> val);
                r2 = temp -> right;
            }
        } 

        return res;
    }
};