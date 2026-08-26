class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> ones;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1') {
                ones.push_back(i);
            }
        }

        if (ones.size() < k) {
            return "";
        }

        string ans = "";

        for (size_t i = 0; i + k - 1 < ones.size(); ++i) {
            int start = ones[i];
            int end = ones[i + k - 1];
            string sub = s.substr(start, end - start + 1);

            if (ans.empty() || sub.length() < ans.length() || 
               (sub.length() == ans.length() && sub < ans)) {
                ans = sub;
            }
        }

        return ans;
    }
};