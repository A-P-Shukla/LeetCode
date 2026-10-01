#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @brief Finds the smallest missing positive integer in O(n) time and O(1) space.
     * Uses the array itself as a hash map: place each value v in index v-1 if 1 <= v <= n.
     */
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Cyclic sort: put nums[i] at index nums[i]-1
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // First index where nums[i] != i+1 is the answer
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) return i + 1;
        }

        return n + 1;
    }
};
