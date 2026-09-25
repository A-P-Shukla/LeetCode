#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Entry point
    vector<string> braceExpansionII(string expression) {
        int pos = 0;
        unordered_set<string> result = parseConcat(expression, pos);
        vector<string> ans(result.begin(), result.end());
        sort(ans.begin(), ans.end());
        return ans;
    }

private:
    // Parse a concatenation sequence until ',' or '}'
    unordered_set<string> parseConcat(const string& s, int& i) {
        unordered_set<string> cur = {""};          // start with empty string
        while (i < (int)s.size() && s[i] != '}' && s[i] != ',') {
            unordered_set<string> next;
            if (s[i] == '{') {
                ++i;                                 // skip '{'
                next = parseSet(s, i);               // parse the union inside braces
                ++i;                                 // skip '}'
            } else {                                 // a single letter
                next.insert(string(1, s[i]));
                ++i;
            }
            cur = cartesianProduct(cur, next);
        }
        return cur;
    }

    // Parse a union set: { expr1, expr2, ... }
    unordered_set<string> parseSet(const string& s, int& i) {
        unordered_set<string> total;
        while (true) {
            unordered_set<string> part = parseConcat(s, i);
            total.insert(part.begin(), part.end()); // union
            if (i >= (int)s.size() || s[i] == '}')
                break;
            // s[i] must be ',' here
            ++i; // skip ','
        }
        return total;
    }

    // Cartesian product of two sets of strings
    unordered_set<string> cartesianProduct(const unordered_set<string>& a,
                                            const unordered_set<string>& b) {
        unordered_set<string> res;
        for (const string& x : a) {
            for (const string& y : b) {
                res.insert(x + y);
            }
        }
        return res;
    }
};