#include <vector>
#include <algorithm>
#include <climits>

class Solution {
private:
    // Helper function to calculate the sum of digits of a number
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int minElement(std::vector<int>& nums) {
        int minVal = INT_MAX;
        for (int num : nums) {
            minVal = std::min(minVal, getDigitSum(num));
        }
        return minVal;
    }
};