#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;      // total insertions performed
        int need = 0;     // how many ')' we still need to close current '('

        for (char c : s) {
            if (c == '(') {
                // each '(' wants a pair "))"
                need += 2;
            } else { // c == ')'
                // we use one ')'
                need--;
                if (need < 0) {
                    // extra ')' without a matching '(' -> insert '(' before it
                    ans++;       // insertion of '('
                    need = 1;    // after insertion, we still need one more ')'
                }
                // if need is odd, we have a single ')' pending; fix by inserting '('
                if (need % 2 == 1) {
                    ans++;       // insert '(' to balance the single ')'
                    need--;      // now need becomes even
                }
            }
        }
        // any remaining need are ')' to be appended at the end
        return ans + need;
    }
};