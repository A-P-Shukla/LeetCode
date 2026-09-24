#include <vector>

class Solution {
private:
    // Helper function to calculate the sum of digits of a non-negative integer
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int smallestIndex(std::vector<int>& nums) {
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            // Check if the sum of digits equals the current index
            if (getDigitSum(nums[i]) == i) {
                return i; // Return immediately as we iterate in increasing order
            }
        }
        return -1; // No valid index found
    }
};