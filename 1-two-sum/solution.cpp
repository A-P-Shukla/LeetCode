#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
     * @brief Finds two indices whose values sum to target using a hash map.
     * @param nums Input array of integers.
     * @param target The target sum.
     * @return Indices of the two numbers that add up to target.
     */
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // value -> index
        for (int i = 0; i < (int)nums.size(); ++i) {
            int complement = target - nums[i];
            if (seen.count(complement)) {
                return {seen[complement], i};
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};
