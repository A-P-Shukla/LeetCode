#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        // Stack holds intermediate scores; a 0 acts as a marker for '('
        vector<int> stk;
        for (char c : s) {
            if (c == '(') {
                // Marker for a new group
                stk.push_back(0);
            } else { // c == ')'
                if (!stk.empty() && stk.back() == 0) {
                    // Found "()", replace marker with score 1
                    stk.back() = 1;
                } else {
                    // Compute score of "(A)" where A may be a sum of scores
                    int inner = 0;
                    while (!stk.empty() && stk.back() != 0) {
                        inner += stk.back();
                        stk.pop_back();
                    }
                    // Pop the '(' marker
                    if (!stk.empty()) stk.pop_back();
                    // Double the inner score and push back
                    stk.push_back(2 * inner);
                }
            }
        }

        // Sum all top‑level scores
        int result = 0;
        for (int v : stk) result += v;
        return result;
    }
};