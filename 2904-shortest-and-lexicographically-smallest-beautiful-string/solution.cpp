#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string shortestBeautifulString(std::string s, int k) {
        std::vector<int> ones;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1') {
                ones.push_back(i);
            }
        }

        // If there are fewer than k '1's, no beautiful substring exists
        if (ones.size() < k) {
            return "";
        }

        std::string ans = "";

        // Iterate through all windows of k '1's
        for (size_t i = 0; i + k - 1 < ones.size(); ++i) {
            int start = ones[i];
            int end = ones[i + k - 1];
            std::string sub = s.substr(start, end - start + 1);

            // Update ans if sub is shorter, or same length but lexicographically smaller
            if (ans.empty() || sub.length() < ans.length() || 
               (sub.length() == ans.length() && sub < ans)) {
                ans = sub;
            }
        }

        return ans;
    }
};