#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int cur = 0;      // current nesting level
        int best = 0;     // maximum nesting level seen so far
        for (char ch : s) {
            if (ch == '(') {
                ++cur;
                best = max(best, cur);
            } else if (ch == ')') {
                --cur;    // guaranteed not to go negative because input is a VPS
            }
        }
        return best;
    }
};