class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(n, n, current, result);
        return result;
    }

private:
    void backtrack(int left, int right, string &current,
                   vector<string> &result) {
        if (left == 0 && right == 0) {
            result.push_back(current);
            return;
        }

        if (left > 0) {
            current.push_back('(');
            backtrack(left - 1, right, current, result);
            current.pop_back();
        }
        if (right > left) { 
            current.push_back(')');
            backtrack(left, right - 1, current, result);
            current.pop_back(); 
        }
    }
};