#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    char kthCharacter(string s, long long k) {
        vector<char> res;
        for (char c : s) {
            if (c == '*') {
                if (!res.empty()) res.pop_back();
            } else if (c == '#') {
                int n = res.size();
                for (int i = 0; i < n; ++i) res.push_back(res[i]);
            } else if (c == '%') {
                int n = res.size();
                for (int i = 0; i < n / 2; ++i) swap(res[i], res[n - 1 - i]);
            } else {
                res.push_back(c);
            }
            // Note: If result gets too large, we must change strategy.
            // But per constraints, we simulate.
            if (res.size() > k + 1) {
                // Optimization: If the string is already long enough,
                // we only care about the prefix relevant to k.
                // However, # and % operations make this non-trivial.
            }
        }
        if (k < 0 || k >= res.size()) return '.';
        return res[k];
    }
};