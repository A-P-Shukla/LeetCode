#include <vector>

class Solution {
public:
    /**
     * Iterates through all possible subarrays and checks the majority condition.
     * The condition 'count of target > length / 2' is equivalent to
     * (2 * count_target) > length.
     */
    int countSubarrays(std::vector<int>& nums, int target) {
        int n = nums.size();
        int validSubarrays = 0;

        for (int i = 0; i < n; ++i) {
            int countTarget = 0;
            for (int j = i; j < n; ++j) {
                if (nums[j] == target) {
                    countTarget++;
                }
                
                int length = j - i + 1;
                // Majority condition: count > length / 2
                // Multiply by 2 to avoid floating point issues: 2 * count > length
                if (2 * countTarget > length) {
                    validSubarrays++;
                }
            }
        }
        
        return validSubarrays;
    }
};