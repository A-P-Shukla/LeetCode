#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(const string& s) {
        string ans;
        ans.reserve(s.size());          // reserve to avoid reallocations
        int depth = 0;                  // current nesting level

        for (char c : s) {
            if (c == '(') {
                // If we are already inside a primitive, keep this '('
                if (depth > 0) ans.push_back(c);
                ++depth;
            } else { // c == ')'
                --depth;
                // If after closing we are still inside, keep this ')'
                if (depth > 0) ans.push_back(c);
            }
        }
        return ans;
    }
};