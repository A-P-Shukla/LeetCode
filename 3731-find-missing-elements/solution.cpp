#include <vector>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    std::vector<int> findMissingIntegers(std::vector<int>& nums) {
        // Find the minimum and maximum values in the array
        int min_val = *std::min_element(nums.begin(), nums.end());
        int max_val = *std::max_element(nums.begin(), nums.end());
        
        // Insert all numbers into a hash set for O(1) lookup
        std::unordered_set<int> present(nums.begin(), nums.end());
        
        std::vector<int> missing;
        
        // Iterate through the entire range [min_val, max_val]
        for (int i = min_val; i <= max_val; ++i) {
            // If the integer is not found in the set, it is missing
            if (present.find(i) == present.end()) {
                missing.push_back(i);
            }
        }
        
        return missing;
    }
};