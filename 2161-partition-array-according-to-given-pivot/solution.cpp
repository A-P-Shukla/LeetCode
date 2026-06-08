#include <vector>

class Solution {
public:
    std::vector<int> pivotArray(std::vector<int>& nums, int pivot) {
        int n = nums.size();
        std::vector<int> result(n);
        int left = 0;
        int right = n - 1;
        
        // Pass 1: Fill elements smaller than pivot from left to right
        for (int i = 0; i < n; ++i) {
            if (nums[i] < pivot) {
                result[left++] = nums[i];
            }
        }
        
        // Pass 2: Fill elements larger than pivot from right to left
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] > pivot) {
                result[right--] = nums[i];
            }
        }
        
        // Pass 3: Fill the remaining middle section with the pivot value
        while (left <= right) {
            result[left++] = pivot;
        }
        
        return result;
    }
};