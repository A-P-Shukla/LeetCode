#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(const vector<int>& nums) {
        // Edge case: single element array
        if (nums.size() == 1) return 1;

        int inc_len = 1;    // current strictly increasing length
        int dec_len = 1;    // current strictly decreasing length
        int ans = 1;        // best length found so far

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1])
                ++inc_len;
            else
                inc_len = 1;               // reset; subarray of length 1 starts here

            if (nums[i] < nums[i - 1])
                ++dec_len;
            else
                dec_len = 1;               // reset

            ans = max({ans, inc_len, dec_len});
        }
        return ans;
    }
};