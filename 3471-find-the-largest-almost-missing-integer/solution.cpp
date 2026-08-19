#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Case 1: Subarrays of size 1 are just individual elements.
        if (k == 1) {
            unordered_map<int, int> counts;
            for (int num : nums) {
                counts[num]++;
            }
            int max_val = -1;
            for (auto& [num, count] : counts) {
                if (count == 1) {
                    max_val = max(max_val, num);
                }
            }
            return max_val;
        }
        
        // Case 2: Only one subarray of size n (the whole array).
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }
        
        // Case 3: 1 < k < n. Only boundary elements can be unique to a single subarray.
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }
        
        int max_val = -1;
        if (counts[nums[0]] == 1) {
            max_val = max(max_val, nums[0]);
        }
        if (counts[nums[n - 1]] == 1) {
            max_val = max(max_val, nums[n - 1]);
        }
        
        return max_val;
    }
};