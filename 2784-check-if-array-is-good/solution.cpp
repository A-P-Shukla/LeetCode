#include <vector>
#include <algorithm>

class Solution {
public:
    bool isGood(std::vector<int>& nums) {
        int len = nums.size();
        // Since base[n] has length n + 1, n must be len - 1
        int n = len - 1;
        
        // base[1] is the smallest valid case [1, 1], so len must be at least 2
        if (len < 2) return false;

        // Use a frequency array to count occurrences of each number
        // Max value of n is determined by len (100), but constraints say nums[i] up to 200
        std::vector<int> counts(201, 0);
        int maxVal = 0;

        for (int num : nums) {
            if (num > n) return false; // Any number > n violates base[n] structure
            counts[num]++;
            maxVal = std::max(maxVal, num);
        }

        // The maximum value in the array must be exactly n
        if (maxVal != n) return false;

        // Numbers 1 to n-1 must appear exactly once
        for (int i = 1; i < n; ++i) {
            if (counts[i] != 1) return false;
        }

        // The number n must appear exactly twice
        return counts[n] == 2;
    }
};