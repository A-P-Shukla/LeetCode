#include <bits/stdc++.h>
using namespace std;

/*
 * Longest Valid Parentheses – O(n) time, O(n) space using a stack.
 * The stack stores indices of characters that are "boundaries" of
 * potential valid substrings. An initial -1 is pushed to handle the
 * edge case where a valid substring starts at index 0.
 */
class Solution {
public:
    int longestValidParentheses(const string& s) {
        int maxLen = 0;
        vector<int> st;
        st.reserve(s.size() + 1);
        st.push_back(-1);                     // sentinel

        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == '(') {
                st.push_back(i);              // possible start of a valid block
            } else { // s[i] == ')'
                if (!st.empty()) st.pop_back(); // discard the matching '(' or sentinel
                if (st.empty()) {
                    // No matching '(' left, set new sentinel
                    st.push_back(i);
                } else {
                    // Current valid length = i - index of last unmatched char
                    maxLen = max(maxLen, i - st.back());
                }
            }
        }
        return maxLen;
    }
};