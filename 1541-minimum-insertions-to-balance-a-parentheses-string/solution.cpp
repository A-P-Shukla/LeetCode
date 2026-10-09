#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        long long ans = 0;   // total insertions
        long long need = 0;  // how many ')' we still need

        for (char c : s) {
            if (c == '(') {
                need += 2;                 // '(' expects two ')'
                if (need % 2 == 1) {       // need is odd → insert one ')'
                    ans++;                 // insert extra ')'
                    need--;                // one requirement satisfied
                }
            } else { // c == ')'
                need--;                     // use one required ')'
                if (need == -1) {           // too many ')'
                    ans++;                 // insert '(' before this ')'
                    need = 1;              // that '(' now needs two ')', one is already used
                }
            }
        }
        ans += need; // insert remaining needed ')'
        return (int)ans;
    }
};