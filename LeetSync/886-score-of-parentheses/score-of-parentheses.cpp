class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int> stk;
        for (char c : s) {
            if (c == '(') {
                stk.push_back(0);
            } else {
                if (!stk.empty() && stk.back() == 0) {
                    stk.back() = 1;
                } else {
                    int inner = 0;
                    while (!stk.empty() && stk.back() != 0) {
                        inner += stk.back();
                        stk.pop_back();
                    }
                    if (!stk.empty()) stk.pop_back();
                    stk.push_back(2 * inner);
                }
            }
        }

        int result = 0;
        for (int v : stk) result += v;
        return result;
    }
};