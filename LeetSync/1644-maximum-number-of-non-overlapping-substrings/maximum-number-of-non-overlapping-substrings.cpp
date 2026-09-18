class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26, -1), last(26, -1);
        
        for (int i = 0; i < n; ++i) {
            int ch = s[i] - 'a';
            if (first[ch] == -1) {
                first[ch] = i;
            }
            last[ch] = i;
        }

        vector<pair<int, int>> candidates;

        for (int i = 0; i < 26; ++i) {
            if (first[i] == -1) continue;

            int L = first[i];
            int R = last[i];
            bool valid = true;

            for (int j = L; j <= R; ++j) {
                int ch = s[j] - 'a';
                if (first[ch] < L) {
                    valid = false;
                    break;
                }
                R = max(R, last[ch]);
            }

            if (valid) {
                candidates.push_back({L, R});
            }
        }

        sort(candidates.begin(), candidates.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });

        vector<string> result;
        int last_end = -1;

        for (const auto& interval : candidates) {
            int L = interval.first;
            int R = interval.second;
            if (L > last_end) {
                result.push_back(s.substr(L, R - L + 1));
                last_end = R;
            }
        }

        return result;
    }
};