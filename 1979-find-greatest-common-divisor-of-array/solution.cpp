#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int findGCD(std::vector<int>& nums) {
        // Find min and max elements in the array
        auto [min_it, max_it] = std::minmax_element(nums.begin(), nums.end());
        int min_val = *min_it;
        int max_val = *max_it;
        
        // Use the built-in GCD function from <numeric> (C++17)
        // Alternatively, use std::__gcd(min_val, max_val) for pre-C++17
        return std::gcd(min_val, max_val);
    }
};