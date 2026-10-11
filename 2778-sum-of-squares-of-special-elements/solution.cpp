#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumOfSquares(vector<int>& nums) {
        int n = nums.size();               // array length (1‑indexed in the statement)
        long long ans = 0;
        for (int i = 1; i <= n; ++i) {     // i is the 1‑based index
            if (n % i == 0) {              // i divides n → special element
                long long val = nums[i - 1];
                ans += val * val;          // add square
            }
        }
        return ans;
    }
};