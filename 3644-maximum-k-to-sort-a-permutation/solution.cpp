class Solution {
public:
    int maximumK(std::vector<int>& nums) {
        const int ALL_BITS = (1 << 30) - 1;          // enough to cover all possible values (n ≤ 1e5)
        int k = ALL_BITS;
        bool hasMisplaced = false;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] != i) {                     // this position needs to be fixed
                hasMisplaced = true;
                k &= i;                              // include the index itself
                k &= nums[i];                        // include the value currently there
            }
        }
        return hasMisplaced ? k : 0;                // already sorted => answer 0
    }
};