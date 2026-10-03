class Solution {
public:
    int longestValidParentheses(const string& s) {
        int maxLen = 0;
        vector<int> st;
        st.reserve(s.size() + 1);
        st.push_back(-1);                   

        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == '(') {
                st.push_back(i);             
            } else { 
                if (!st.empty()) st.pop_back();
                if (st.empty()) {
                    st.push_back(i);
                } else {
                    maxLen = max(maxLen, i - st.back());
                }
            }
        }
        return maxLen;
    }
};