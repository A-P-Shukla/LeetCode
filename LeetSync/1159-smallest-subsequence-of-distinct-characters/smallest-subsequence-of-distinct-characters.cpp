class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last_occurrence(26, -1);
        for (int i = 0; i < s.length(); ++i) {
            last_occurrence[s[i] - 'a'] = i;
        }

        vector<bool> visited(26, false);
        string stack = "";

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (visited[c - 'a']) continue;

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