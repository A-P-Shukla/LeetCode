#include <vector>
#include <unordered_set>

class Solution {
public:
    int missingMultiple(std::vector<int>& nums, int k) {
        // Store all elements of nums in a hash set for O(1) lookup time
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        
        // Start checking from the first positive multiple of k
        int multiple = k;
        
        // Increment by k until we find a multiple not present in the set
        while (numSet.count(multiple)) {
            multiple += k;
        }
        
        return multiple;
    }
};