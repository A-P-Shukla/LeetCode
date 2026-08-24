class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        
        long long pref_sum = 0;
        for (int stone : stones) {
            pref_sum += stone;
        }
        long long dp = pref_sum;

        for (int i = n - 1; i >= 2; --i) {
            pref_sum -= stones[i];
            dp = max(dp, pref_sum - dp);
        }

        return dp;
    }
};