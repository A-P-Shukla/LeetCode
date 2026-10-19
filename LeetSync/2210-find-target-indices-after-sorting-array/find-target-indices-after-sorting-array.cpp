class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        auto lower = lower_bound(nums.begin(), nums.end(), target);
        if (lower == nums.end() || *lower != target) {
            
            return {};
        }
        auto upper = upper_bound(nums.begin(), nums.end(), target);

        int L = static_cast<int>(lower - nums.begin());
        int R = static_cast<int>(upper - nums.begin());

        vector<int> result;
        result.reserve(R - L);
        for (int i = L; i < R; ++i) {
            result.push_back(i);
        }
        return result;
    }
};