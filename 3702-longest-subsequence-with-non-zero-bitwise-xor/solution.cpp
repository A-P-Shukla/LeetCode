class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXor = 0;
        bool hasNonZero = false;

        for (int num : nums) {
            totalXor ^= num;
            if (num != 0) {
                hasNonZero = true;
            }
        }

        // Case 1: All elements are zero
        if (!hasNonZero) {
            return 0;
        }

        // Case 2: XOR sum of the whole array is non-zero
        if (totalXor != 0) {
            return nums.size();
        }

        // Case 3: XOR sum of whole array is zero, remove one non-zero element
        return nums.size() - 1;
    }
};