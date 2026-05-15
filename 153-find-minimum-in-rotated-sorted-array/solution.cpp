#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        // Binary search to find the minimum element
        while (left < right) {
            int mid = left + (right - left) / 2;

            // If mid element is greater than the rightmost element, 
            // the minimum must be in the right half.
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } 
            // Otherwise, the minimum is in the left half (including mid).
            else {
                right = mid;
            }
        }

        // When left == right, we have found the minimum element.
        return nums[left];
    }
};