#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // Sort to locate median
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int median = nums[n / 2];               // works for both even and odd n
        long long moves = 0;                    // use 64‑bit to avoid overflow
        for (int x : nums) {
            moves += llabs(static_cast<long long>(x) - median);
        }
        return static_cast<int>(moves);         // problem guarantees 32‑bit fit
    }
};