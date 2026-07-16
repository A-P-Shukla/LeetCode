#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    long long sumOfGcdOfFormedPairs(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> prefixGcd(n);
        int currentMax = 0;

        // Construct prefixGcd array
        for (int i = 0; i < n; ++i) {
            currentMax = std::max(currentMax, nums[i]);
            prefixGcd[i] = std::gcd(nums[i], currentMax);
        }

        // Sort to facilitate the smallest-largest pairing strategy
        std::sort(prefixGcd.begin(), prefixGcd.end());

        long long totalSum = 0;
        int left = 0;
        int right = n - 1;

        // Use two pointers to pair smallest and largest
        while (left < right) {
            totalSum += std::gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }

        return totalSum;
    }
};