#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Check if nums is a left rotation of the sorted array [0,1,...,n-1].
    // If yes, return the required number of left rotations (index of 0), else -1.
    int rotationCost(const vector<int>& nums) {
        int n = nums.size();
        int idx0 = -1;
        for (int i = 0; i < n; ++i) if (nums[i] == 0) { idx0 = i; break; }
        if (idx0 == -1) return -1;               // should never happen for a permutation
        for (int j = 0; j < n; ++j) {
            if (nums[(idx0 + j) % n] != j) return -1;
        }
        return idx0;                             // k left rotations bring 0 to front
    }

    // Check if nums is a left rotation of the reversed sorted array [n-1,...,0].
    // If yes, return the index of (n-1) which equals the rotation offset k,
    // otherwise return -1.
    int revRotationCost(const vector<int>& nums) {
        int n = nums.size();
        int idxMax = -1;
        for (int i = 0; i < n; ++i) if (nums[i] == n - 1) { idxMax = i; break; }
        if (idxMax == -1) return -1;              // should never happen for a permutation
        for (int j = 0; j < n; ++j) {
            if (nums[(idxMax + j) % n] != n - 1 - j) return -1;
        }
        return idxMax;                            // k rotations before a reversal
    }

    int minimumOperations(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) return 0;                     // already sorted

        int ans = INT_MAX;

        int rot = rotationCost(nums);
        if (rot != -1) ans = min(ans, rot);

        int revRot = revRotationCost(nums);
        if (revRot != -1) ans = min(ans, revRot + 1); // 1 reversal + revRot rotations

        return (ans == INT_MAX) ? -1 : ans;
    }
};