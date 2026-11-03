#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Returns the minimum total moves to make all elements equal by only incrementing.
    int minMoves(vector<int>& nums) {
        int maxVal = 0;
        for (int x : nums) {
            if (x > maxVal) maxVal = x;               // track maximum
        }
        long long moves = 0;                         // use 64‑bit to avoid overflow
        for (int x : nums) {
            moves += static_cast<long long>(maxVal - x);
        }
        return static_cast<int>(moves);
    }
};