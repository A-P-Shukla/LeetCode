//Code 1:
class Solution {
 public:
void dfs(const vector<int>& nums, vector<bool>&& used, vector<int>&& path,
    vector<vector<int>>& ans) {
    if (path.size() == nums.size()) {
      ans.push_back(path);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (used[i])
        continue;
      if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
        continue;
      used[i] = true;
      path.push_back(nums[i]);
      dfs(nums, std::move(used), std::move(path), ans);
      path.pop_back();
      used[i] = false;
    }
    }
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;
    ranges::sort(nums);
    dfs(nums, vector<bool>(nums.size()), {}, ans);
    return ans;
  }
};

//Code 2:
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res{{}};
        for (int num : nums) {
            for (int k = res.size(); k > 0; --k) {
                vector<int> t = res.front();
                res.erase(res.begin());
                for (int i = 0; i <= t.size(); ++i) {
                    vector<int> one = t;
                    one.insert(one.begin() + i, num);
                    res.push_back(one);
                    if (i < t.size() && num == t[i]) break;
                }
            }
        }
        return res;
    }
};
