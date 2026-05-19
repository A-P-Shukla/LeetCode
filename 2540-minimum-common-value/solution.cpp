#include <vector>

using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0; // Pointer for nums1
        int j = 0; // Pointer for nums2
        int n = nums1.size();
        int m = nums2.size();

        // Traverse both arrays using two pointers
        while (i < n && j < m) {
            if (nums1[i] == nums2[j]) {
                // Since arrays are sorted, the first match found is the minimum
                return nums1[i];
            } else if (nums1[i] < nums2[j]) {
                // Increment pointer of the array with the smaller value
                i++;
            } else {
                j++;
            }
        }

        // No common element found
        return -1;
    }
};