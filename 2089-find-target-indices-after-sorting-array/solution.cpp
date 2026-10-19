#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        // 1. Sort the array to group equal values together.
        sort(nums.begin(), nums.end());

        // 2. Locate the first index where nums[i] >= target.
        auto lower = lower_bound(nums.begin(), nums.end(), target);
        if (lower == nums.end() || *lower != target) {
            // Target not present.
            return {};
        }
        // 3. Locate the first index where nums[i] > target.
        auto upper = upper_bound(nums.begin(), nums.end(), target);

        // 4. Convert iterators to integer indices.
        int L = static_cast<int>(lower - nums.begin());
        int R = static_cast<int>(upper - nums.begin());

        // 5. Build the answer list [L, L+1, ..., R-1].
        vector<int> result;
        result.reserve(R - L);
        for (int i = L; i < R; ++i) {
            result.push_back(i);
        }
        return result;
    }
};