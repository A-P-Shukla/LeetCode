class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        int odd_cnt = 0;
        char mid_char = '\0';
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                odd_cnt++;
                mid_char = (char)('a' + i);
            }
        }

        if (n % 2 == 0 && odd_cnt != 0) return "";
        if (n % 2 != 0 && odd_cnt != 1) return "";

        int half = n / 2;
        vector<int> half_count(26, 0);
        for (int i = 0; i < 26; ++i) {
            half_count[i] = count[i] / 2;
        }

        vector<int> temp_count = half_count;
        int max_match = 0;
        for (int i = 0; i < half; ++i) {
            int idx = target[i] - 'a';
            if (temp_count[idx] > 0) {
                temp_count[idx]--;
                max_match++;
            } else {
                break;
            }
        }

        if (max_match == half) {
            string p(n, ' ');
            for (int i = 0; i < half; ++i) {
                p[i] = target[i];
                p[n - 1 - i] = target[i];
            }
            if (n % 2 != 0) {
                p[half] = mid_char;
            }
            if (p > target) {
                return p;
            }
        }

        vector<vector<int>> avail_at_k(half + 1, half_count);
        for (int i = 0; i < max_match; ++i) {
            avail_at_k[i + 1] = avail_at_k[i];
            avail_at_k[i + 1][target[i] - 'a']--;
        }

        int start_k = min(half - 1, max_match);
        for (int k = start_k; k >= 0; --k) {
            vector<int> cur_avail = avail_at_k[k];
            int target_char_idx = target[k] - 'a';
            
            int chosen_char = -1;
            for (int c = target_char_idx + 1; c < 26; ++c) {
                if (cur_avail[c] > 0) {
                    chosen_char = c;
                    break;
                }
            }

            if (chosen_char != -1) {
                string p(n, ' ');
                for (int i = 0; i < k; ++i) {
                    p[i] = target[i];
                }
                p[k] = (char)('a' + chosen_char);
                cur_avail[chosen_char]--;

                int fill_idx = k + 1;
                for (int c = 0; c < 26; ++c) {
                    while (cur_avail[c] > 0) {
                        p[fill_idx++] = (char)('a' + c);
                        cur_avail[c]--;
                    }
                }

                if (n % 2 != 0) {
                    p[half] = mid_char;
                }

                for (int i = 0; i < half; ++i) {
                    p[n - 1 - i] = p[i];
                }

                return p;
            }
        }

        return "";
    }
};