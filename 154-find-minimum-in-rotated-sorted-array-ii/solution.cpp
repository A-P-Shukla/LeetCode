#include <vector>

class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                // The minimum is in the right half
                left = mid + 1;
            } else if (nums[mid] < nums[right]) {
                // The minimum is mid or to the left
                right = mid;
            } else {
                // Ambigious case: nums[mid] == nums[right]
                // We cannot discard half, but we can safely ignore the rightmost element
                // because nums[mid] provides a value at least as small.
                right--;
            }
        }

        return nums[left];
    }
};