#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        const int n = nums.size();
        using u64 = unsigned long long;
        const u64 BASE = 91138233ULL;            // random odd constant

        // prefix hash: pref[i] = hash of nums[0..i-1]
        vector<u64> pref(n + 1, 0), power(n + 1, 1);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] * BASE + static_cast<u64>(nums[i] + 1);
            power[i + 1] = power[i] * BASE;
        }

        auto hasUnique = [&](int len) -> bool {
            unordered_map<u64, int> cnt;
            cnt.reserve(n - len + 1);
            for (int i = 0; i + len <= n; ++i) {
                u64 h = pref[i + len] - pref[i] * power[len];
                ++cnt[h];
            }
            for (const auto& kv : cnt) {
                if (kv.second == 1) return true;
            }
            return false;
        };

        int lo = 1, hi = n, ans = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (hasUnique(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};