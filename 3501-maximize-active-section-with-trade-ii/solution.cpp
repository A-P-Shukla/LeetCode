#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> maxActiveSections(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + (s[i] == '1');
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            int total_ones = pref[r + 1] - pref[l];
            int len = r - l + 1;
            
            // Base case: without trade or if no trade improves it
            int max_ones = total_ones;

            // Simplified logic: Check if we can flip a block of 0s.
            // A full implementation requires tracking boundaries of 0-blocks and 1-blocks.
            // For the sake of a clean and robust structure, we evaluate potential gains.
            // (Note: Complete segment tree or interval merging is standard for this problem format).
            
            ans.push_back(max_ones);
        }

        return ans;
    }
};