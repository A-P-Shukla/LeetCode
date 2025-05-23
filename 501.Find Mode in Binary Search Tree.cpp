//Code 1:
class Solution {
 public:
  vector<int> findMode(TreeNode* root) {
    vector<int> ans;
    int count = 0;
    int maxCount = 0;

    inorder(root, count, maxCount, ans);
    return ans;
  }

 private:
  TreeNode* pred = nullptr;

  void inorder(TreeNode* root, int& count, int& maxCount, vector<int>& ans) {
    if (root == nullptr)
      return;

    inorder(root->left, count, maxCount, ans);
    updateCount(root, count, maxCount, ans);
    inorder(root->right, count, maxCount, ans);
  }

  void updateCount(TreeNode* root, int& count, int& maxCount,
                   vector<int>& ans) {
    if (pred && pred->val == root->val)
      ++count;
    else
      count = 1;

    if (count > maxCount) {
      maxCount = count;
      ans = {root->val};
    } else if (count == maxCount) {
      ans.push_back(root->val);
    }

    pred = root;
  }
};

//Code 2:
class Solution {
 public:
  TreeNode* previous;
    int maxFrequency, currentCount;
    vector<int> modes;
    vector<int> findMode(TreeNode* root) {
        previous = nullptr;
        maxFrequency = 0;
        currentCount = 0;
        modes.clear();
        inOrderTraversal(root);
        return modes;
    }
    void inOrderTraversal(TreeNode* node) {
        if (!node) return;
        inOrderTraversal(node->left);
        if (previous != nullptr && previous->val == node->val) {
            currentCount++;
        } else {
            currentCount = 1;
        }
      
        if (currentCount > maxFrequency) {
            modes.clear();
            modes.push_back(node->val);
            maxFrequency = currentCount;
        } else if (currentCount == maxFrequency) {
            modes.push_back(node->val);
        }
        previous = node;
        inOrderTraversal(node->right);
    }
};
