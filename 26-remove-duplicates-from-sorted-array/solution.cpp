#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @brief Removes duplicates in-place from a sorted array using two pointers.
     * @return The number of unique elements.
     */
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int k = 1; // pointer for the next unique position
        for (int i = 1; i < (int)nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};
