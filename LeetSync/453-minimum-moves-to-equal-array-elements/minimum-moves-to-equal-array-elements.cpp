class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = nums[0];
        for (int v : nums) {
            if (v < mn) mn = v;
        }
        long long moves = 0;
        for (int v : nums) {
            moves += static_cast<long long>(v) - mn;
        }
        return static_cast<int>(moves);
    }
};