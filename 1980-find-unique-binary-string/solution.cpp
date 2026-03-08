#include <string>
#include <vector>

class Solution {
public:
    /**
     * Finds a binary string of length n that does not appear in nums.
     * We use Cantor's Diagonal Argument: flip the i-th bit of the i-th string.
     */
    std::string findDifferentBinaryString(std::vector<std::string>& nums) {
        std::string result = "";
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            // If the i-th char of the i-th string is '0', append '1' to result.
            // If it is '1', append '0'.
            if (nums[i][i] == '0') {
                result += '1';
            } else {
                result += '0';
            }
        }
        
        return result;
    }
};
