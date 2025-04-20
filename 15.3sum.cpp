/* 
Algo:
Sort: Sort nums. O(N log N).
Outer Loop (for i): Iterate i from 0 to n-3.
Skip Duplicates (for i): Skip if nums[i] == nums[i-1].
Inner Loop (for j): Iterate j from i+1 to n-2.
Skip Duplicates (for j): Skip if j > i+1 and nums[j] == nums[j-1].
Calculate Target: Find target = -nums[i] - nums[j].
Binary Search: Perform a binary search for target in the subarray nums[j+1 ... n-1]. O(log N).
Store Result: If target is found by binary search, add {nums[i], nums[j], target} to a result set (or vector, handling duplicates carefully). Using a std::set<vector<int>> is easiest.
Convert Result: Convert the set to a vector of vectors.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> results_set;
        int n = nums.size();
        if (n < 3) return {};
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 1; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int target = -nums[i] - nums[j];
                if (binary_search(nums.begin() + j + 1, nums.end(), target)) {
                    results_set.insert({nums[i], nums[j], target});
                }
            }
        }
        vector<vector<int>> ans(results_set.begin(), results_set.end());
        return ans;
    }
};
