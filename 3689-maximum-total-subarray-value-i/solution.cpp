#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        if (nums.empty()) {
            return 0;
        }
        
        int min_val = nums[0];
        int max_val = nums[0];
        
        // Find the global minimum and maximum in one pass
        for (int num : nums) {
            if (num < min_val) {
                min_val = num;
            }
            if (num > max_val) {
                max_val = num;
            }
        }
        
        // Use 1LL to prevent integer overflow during multiplication
        return 1LL * (max_val - min_val) * k;
    }
};