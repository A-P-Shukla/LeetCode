#include <vector>
#include <string>

// Generate Parentheses - Backtracking solution
class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        std::string current;
        backtrack(n, n, current, result);
        return result;
    }

private:
    // left: number of '(' remaining to place
    // right: number of ')' remaining to place
    void backtrack(int left, int right, std::string &current,
                   std::vector<std::string> &result) {
        // If no brackets remain, we have a complete combination
        if (left == 0 && right == 0) {
            result.push_back(current);
            return;
        }

        // Place '(' if we still have any left
        if (left > 0) {
            current.push_back('(');
            backtrack(left - 1, right, current, result);
            current.pop_back(); // backtrack
        }

        // Place ')' only if it won't break the well‑formed property
        if (right > left) { // more ')' available than '(' currently open
            current.push_back(')');
            backtrack(left, right - 1, current, result);
            current.pop_back(); // backtrack
        }
    }
};