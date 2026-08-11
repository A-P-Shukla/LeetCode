#include <vector>
#include <unordered_set>

class Solution {
public:
    int missingInteger(std::vector<int>& nums) {
        // Step 1: Calculate the sum of the longest sequential prefix
        int sum_val = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                sum_val += nums[i];
            } else {
                break;
            }
        }
        
        // Step 2: Store elements in a hash set for O(1) lookups
        std::unordered_set<int> num_set(nums.begin(), nums.end());
        
        // Step 3: Find the smallest missing integer >= sum_val
        while (num_set.count(sum_val)) {
            sum_val++;
        }
        
        return sum_val;
    }
};