#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::string smallestSubsequence(std::string s) {
        std::vector<int> last_occurrence(26, -1);
        for (int i = 0; i < s.length(); ++i) {
            last_occurrence[s[i] - 'a'] = i;
        }

        std::vector<bool> visited(26, false);
        std::string stack = "";

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (visited[c - 'a']) continue;

            // While stack is not empty, current char is smaller than top,
            // and the top character appears later in the string
            while (!stack.empty() && c < stack.back() && last_occurrence[stack.back() - 'a'] > i) {
                visited[stack.back() - 'a'] = false;
                stack.pop_back();
            }

            stack.push_back(c);
            visited[c - 'a'] = true;
        }

        return stack;
    }
};