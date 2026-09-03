#include <vector>
#include <algorithm>

class Solution {
public:
    bool canConstructArray(std::vector<int>& nums1) {
        int min_val = nums1[0];
        bool all_even = true;

        for (int x : nums1) {
            if (x < min_val) {
                min_val = x;
            }
            if (x % 2 != 0) {
                all_even = false;
            }
        }

        // We can succeed if the minimum element is odd (making all elements odd)
        // or if all elements are already even (making all elements even).
        return (min_val % 2 != 0) || all_even;
    }
};