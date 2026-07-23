#include <vector>

class Solution {
public:
    int uniqueXorTriplets(std::vector<int>& nums) {
        int n = nums.size();
        
        // Base cases
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        // For n >= 3, the answer is 2^(bit_length(n))
        int bit_len = 32 - __builtin_clz(n);
        return 1 << bit_len;
    }
};