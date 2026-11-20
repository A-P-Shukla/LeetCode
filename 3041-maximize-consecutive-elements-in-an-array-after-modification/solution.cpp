#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeConsecutiveElements(vector<int>& nums) {
        int n = nums.size();
        int maxVal = 0;
        for (int v : nums) maxVal = max(maxVal, v);
        // One extra position for possible increment to maxVal+1
        int size = maxVal + 2;
        vector<int> freq(size, 0);
        for (int v : nums) ++freq[v];

        long long ans = 0;
        long long curLen = 0;
        long long carry = 0; // number of elements carried from v-1 to v

        for (int v = 1; v < size; ++v) {
            long long supply = static_cast<long long>(freq[v]) + carry;
            if (supply == 0) {
                // run breaks
                curLen = 0;
                carry = 0;
                continue;
            }
            // we can place one element for value v
            ++curLen;
            if (carry > 0) {
                // use a carried element, keep all originals for next carry
                carry = freq[v];
            } else {
                // must use an original element, leave the rest for next carry
                carry = freq[v] - 1;
            }
            ans = max(ans, curLen);
        }
        return static_cast<int>(ans);
    }
};