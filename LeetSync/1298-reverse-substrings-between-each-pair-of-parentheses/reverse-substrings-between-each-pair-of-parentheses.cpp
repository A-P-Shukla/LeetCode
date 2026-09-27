class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> partner(n, -1);          
        stack<int> st;                       
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int j = st.top(); st.pop();
                partner[i] = j;
                partner[j] = i;
            }
        }

        string result;
        result.reserve(n);
        int i = 0, dir = 1;                  

        while (i < n) {
            if (s[i] == '(' || s[i] == ')') {
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