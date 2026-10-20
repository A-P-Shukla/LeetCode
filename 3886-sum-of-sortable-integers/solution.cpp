#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumOfSortableIntegers(vector<int> nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        // collect all divisors of n
        vector<int> divisors;
        for (int i = 1; i * 1LL * i <= n; ++i) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (i != n / i) divisors.push_back(n / i);
            }
        }

        long long ans = 0;
        for (int k : divisors) {
            bool ok = true;
            for (int start = 0; start < n && ok; start += k) {
                // original block
                const int *orig = &nums[start];
                // target block from sorted array
                const int *target = &sorted[start];

                // try to find a rotation offset
                bool block_ok = false;
                for (int offset = 0; offset < k; ++offset) {
                    if (orig[(offset) % k] != target[0]) continue;
                    bool match = true;
                    for (int i = 0; i < k; ++i) {
                        if (orig[(offset + i) % k] != target[i]) {
                            match = false;
                            break;
                        }
                    }
                    if (match) {
                        block_ok = true;
                        break;
                    }
                }
                if (!block_ok) ok = false;
            }
            if (ok) ans += k;
        }
        return ans;
    }
};