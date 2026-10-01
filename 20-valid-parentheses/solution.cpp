#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // Stack to keep track of opening brackets
        stack<char> st;
        // Mapping from closing to opening bracket for quick check
        unordered_map<char, char> match = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char ch : s) {
            // If it's an opening bracket, push onto the stack
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else { // It's a closing bracket
                // Stack must not be empty and top must match
                if (st.empty() || st.top() != match[ch]) {
                    return false;
                }
                st.pop(); // Pair matched, remove the opening bracket
            }
        }
        // Valid if no unmatched opening brackets remain
        return st.empty();
    }
};