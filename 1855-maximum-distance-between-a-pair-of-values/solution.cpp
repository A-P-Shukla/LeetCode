#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * Finds the maximum distance j - i such that i <= j and nums1[i] <= nums2[j].
     * Uses a two-pointer approach leveraging the non-increasing property of both arrays.
     */
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int maxDist = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();

        while (i < n1 && j < n2) {
            // Check if the condition is satisfied
            if (nums1[i] <= nums2[j]) {
                // Since i <= j is required, and we start both at 0, 
                // we only calculate distance if i <= j.
                // However, the logic below naturally handles i <= j 
                // because if i > j, nums1[i] <= nums2[j] might be true,
                // but j - i would be negative, which won't update maxDist.
                maxDist = max(maxDist, j - i);
                
                // Try to increase j to maximize the distance
                j++;
            } else {
                // If nums1[i] is too large, move i to a smaller value
                i++;
                // Optimization: Ensure i doesn't lag too far behind j 
                // to maintain i <= j logic, though max(0, j-i) handles this.
            }
        }

        return maxDist;
    }
};