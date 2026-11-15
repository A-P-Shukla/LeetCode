class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const long long MOD = 1'000'000'007LL;
        long long cntEven = 1;    
        long long cntOdd  = 0;
        long long ans     = 0;
        int parity = 0;           

        for (int v : arr) {
            parity ^= (v & 1);    
            if (parity) {
                ans = (ans + cntEven) % MOD;
                ++cntOdd;
            } else {
                ans = (ans + cntOdd) % MOD;
                ++cntEven;
            }
        }
        return static_cast<int>(ans);
    }
};