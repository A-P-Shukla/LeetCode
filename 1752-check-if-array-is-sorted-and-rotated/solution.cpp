#include <vector>

class Solution {
public:
    bool check(std::vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            // Compare current element with the next element in a circular manner
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
            // If we have more than one rotation boundary (drop point), it's invalid
            if (count > 1) {
                return false;
            }
        }
        
        return true;
    }
};