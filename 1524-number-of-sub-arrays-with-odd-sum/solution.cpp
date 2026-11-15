#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const long long MOD = 1'000'000'007LL;
        long long cntEven = 1;    // empty prefix (sum = 0) is even
        long long cntOdd  = 0;
        long long ans     = 0;
        int parity = 0;           // current prefix parity: 0 = even, 1 = odd

        for (int v : arr) {
            parity ^= (v & 1);    // flip parity if v is odd
            if (parity) {
                // current prefix is odd -> pair with previous even prefixes
                ans = (ans + cntEven) % MOD;
                ++cntOdd;
            } else {
                // current prefix is even -> pair with previous odd prefixes
                ans = (ans + cntOdd) % MOD;
                ++cntEven;
            }
        }
        return static_cast<int>(ans);
    }
};