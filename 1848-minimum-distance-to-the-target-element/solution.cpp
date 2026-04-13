#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

class Solution {
public:
    /**
     * Finds the minimum absolute distance |i - start| such that nums[i] == target.
     * 
     * @param nums The input integer array.
     * @param target The value we are looking for.
     * @param start The reference index to calculate distance from.
     * @return The minimum distance found.
     */
    int getMinDistance(std::vector<int>& nums, int target, int start) {
        int minDistance = INT_MAX;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                // Calculate absolute difference
                int currentDistance = std::abs(i - start);
                
                // Update the global minimum distance
                if (currentDistance < minDistance) {
                    minDistance = currentDistance;
                }
                
                // Early exit optimization: if distance is 0, it can't get any smaller
                if (minDistance == 0) return 0;
            }
        }
        
        return minDistance;
    }
};