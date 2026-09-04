class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
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

        return (min_val % 2 != 0) || all_even;
    }
};