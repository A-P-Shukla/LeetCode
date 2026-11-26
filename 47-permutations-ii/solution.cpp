#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @brief Returns all unique permutations of nums (may contain duplicates).
     * Uses backtracking with a sorted array and a "skip same element at same
     * depth" rule to avoid duplicate permutations.
     */
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        vector<int> path;
        backtrack(nums, used, path, result);
        return result;
    }

private:
    void backtrack(const vector<int>& nums, vector<bool>& used,
                   vector<int>& path, vector<vector<int>>& result) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (used[i]) continue;
            // Skip duplicate: same value as previous, and previous not used at this level
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtrack(nums, used, path, result);
            path.pop_back();
            used[i] = false;
        }
    }
};
