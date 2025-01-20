//Code 1:
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        long counts[60] = {};
        for(auto &t : time)
            ++counts[t%60];
        
        long ans = 0;
        for(int i = 1; i < 30; ++i)
            ans += counts[i]*counts[60-i];
        ans += (counts[0]*(counts[0]-1)/2);
        ans += (counts[30]*(counts[30]-1)/2);

        return ans;
    }
};
