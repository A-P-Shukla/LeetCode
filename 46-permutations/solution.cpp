#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @brief Returns all permutations of distinct integers using backtracking.
     */
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        do {
            result.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return result;
    }
};
