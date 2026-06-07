#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> valToNode;
        unordered_set<int> children;

        for (const auto& desc : descriptions) {
            int parentVal = desc[0];
            int childVal = desc[1];
            bool isLeft = desc[2];

            // If parent node doesn't exist yet, create it
            if (valToNode.find(parentVal) == valToNode.end()) {
                valToNode[parentVal] = new TreeNode(parentVal);
            }
            // If child node doesn't exist yet, create it
            if (valToNode.find(childVal) == valToNode.end()) {
                valToNode[childVal] = new TreeNode(childVal);
            }

            // Establish the parent-child connection
            if (isLeft) {
                valToNode[parentVal]->left = valToNode[childVal];
            } else {
                valToNode[parentVal]->right = valToNode[childVal];
            }

            // Record child to find the root later
            children.insert(childVal);
        }

        // The root node has no parent, so it won't be in the children set
        for (const auto& pair : valToNode) {
            int val = pair.first;
            if (children.find(val) == children.end()) {
                return pair.second;
            }
        }

        return nullptr;
    }
};