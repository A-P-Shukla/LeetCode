#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @brief Rearranges nums into the next lexicographically greater permutation in-place.
     * Steps:
     *   1. Find the rightmost index i where nums[i] < nums[i+1] (the "pivot").
     *   2. Find the rightmost index j > i where nums[j] > nums[i], then swap.
     *   3. Reverse the suffix after position i to get the smallest arrangement.
     */
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;

        // Step 1: find pivot
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) { pivot = i; break; }
        }

        if (pivot == -1) {
            // Already the largest permutation — wrap around to smallest
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: swap pivot with the smallest element to its right that is larger
        for (int j = n - 1; j > pivot; --j) {
            if (nums[j] > nums[pivot]) { swap(nums[j], nums[pivot]); break; }
        }

        // Step 3: reverse suffix
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};
