#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        // Find the global minimum.
        int mn = nums[0];
        for (int v : nums) {
            if (v < mn) mn = v;
        }
        // Accumulate differences using 64‑bit to avoid overflow.
        long long moves = 0;
        for (int v : nums) {
            moves += static_cast<long long>(v) - mn;
        }
        // Problem guarantees the result fits in 32‑bit signed int.
        return static_cast<int>(moves);
    }
};