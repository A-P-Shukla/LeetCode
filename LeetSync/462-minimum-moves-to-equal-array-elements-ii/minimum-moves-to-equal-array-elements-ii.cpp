class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int median = nums[n / 2];
        long long moves = 0;                    
        for (int x : nums) {
            moves += llabs(static_cast<long long>(x) - median);
        }
        return static_cast<int>(moves);      
    }
};