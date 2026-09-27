#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> partner(n, -1);          // partner[i] = index of matching '(' or ')'
        stack<int> st;                       // holds indices of '(' encountered so far

        // First pass: find matching pairs
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int j = st.top(); st.pop();  // j is the matching '('
                partner[i] = j;
                partner[j] = i;
            }
        }

        string result;
        result.reserve(n);                    // final length ≤ n (brackets are removed)
        int i = 0, dir = 1;                  // start scanning forward

        while (i < n) {
            if (s[i] == '(' || s[i] == ')') {
                // Jump to the matching parenthesis and reverse traversal direction
                i = partner[i];
                dir = -dir;
            } else {
                result.push_back(s[i]);
            }
            i += dir;
        }
        return result;
    }
};