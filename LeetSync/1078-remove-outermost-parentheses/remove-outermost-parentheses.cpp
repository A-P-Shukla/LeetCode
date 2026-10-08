class Solution {
public:
    string removeOuterParentheses(const string& s) {
        string ans;
        ans.reserve(s.size());          
        int depth = 0;

        for (char c : s) {
            if (c == '(') {
                if (depth > 0) ans.push_back(c);
                ++depth;
            } else { 
                --depth;
                if (depth > 0) ans.push_back(c);
            }
        }
        return ans;
    }
};