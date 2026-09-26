#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        // Build hash map from key to value
        unordered_map<string, string> mp;
        mp.reserve(knowledge.size() * 2);
        for (const auto& kv : knowledge) {
            mp[kv[0]] = kv[1];
        }

        string result;
        result.reserve(s.size());  // result will be at most length of s * (max value length)

        const int n = s.size();
        for (int i = 0; i < n; ) {
            if (s[i] != '(') {
                // Normal character, copy as‑is
                result.push_back(s[i]);
                ++i;
            } else {
                // Found a '(' – locate the matching ')'
                int j = i + 1;
                while (j < n && s[j] != ')') ++j;   // guaranteed to find ')'
                string key = s.substr(i + 1, j - i - 1);
                auto it = mp.find(key);
                if (it != mp.end())
                    result.append(it->second);
                else
                    result.push_back('?');
                i = j + 1;   // move past ')'
            }
        }
        return result;
    }
};