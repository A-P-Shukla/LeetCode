#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumScore(vector<int>& nums) {
        int n = nums.size();
        if (n <= 3) return 0;                     // we can make all equal
        sort(nums.begin(), nums.end());

        long long ans = LLONG_MAX;
        // remove two smallest
        if (n - 1 >= 2) ans = min(ans, (long long)nums[n - 1] - nums[2]);
        // remove two largest
        if (n - 3 >= 0) ans = min(ans, (long long)nums[n - 3] - nums[0]);
        // remove smallest and largest
        if (n - 2 >= 1) ans = min(ans, (long long)nums[n - 2] - nums[1]);
        // remove only smallest
        ans = min(ans, (long long)nums[n - 1] - nums[1]);
        // remove only largest
        ans = min(ans, (long long)nums[n - 2] - nums[0]);

        return ans;    // low score can be forced to 0
    }
};