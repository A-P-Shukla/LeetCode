#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        // pref[i]: smallest index in word1 matching word2[0..i] with 0 mismatches
        vector<int> pref(m, -1);
        int ptr = 0;
        for (int i = 0; i < m; ++i) {
            while (ptr < n && word1[ptr] != word2[i]) {
                ptr++;
            }
            if (ptr < n) {
                pref[i] = ptr;
                ptr++;
            } else {
                break;
            }
        }

        // suf[i]: largest index in word1 matching word2[i..m-1] with 0 mismatches
        vector<int> suf(m + 2, -1);
        suf[m] = n;
        suf[m + 1] = n + 1;
        ptr = n - 1;
        for (int i = m - 1; i >= 0; --i) {
            ptr = min(ptr, suf[i + 1] - 1);
            while (ptr >= 0 && word1[ptr] != word2[i]) {
                ptr--;
            }
            suf[i] = ptr;
        }

        // valid_mismatch[k]: true if mismatch can be placed at index k in word2
        vector<bool> valid_mismatch(m, false);
        for (int k = 0; k < m; ++k) {
            int prev_idx = (k == 0) ? -1 : pref[k - 1];
            if (k > 0 && prev_idx == -1) {
                valid_mismatch[k] = false;
            } else {
                valid_mismatch[k] = (prev_idx + 1 < suf[k + 1]);
            }
        }

        // has_valid_suffix[i]: true if a valid match exists for suffix starting at i
        vector<bool> has_valid_suffix(m + 1, false);
        has_valid_suffix[m] = (pref[m - 1] != -1);
        for (int i = m - 1; i >= 0; --i) {
            has_valid_suffix[i] = has_valid_suffix[i + 1] || valid_mismatch[i];
        }

        if (!has_valid_suffix[0]) {
            return {};
        }

        vector<int> seq(m);
        int last_idx = -1;
        bool mismatch_used = false;

        for (int i = 0; i < m; ++i) {
            if (mismatch_used) {
                int p = last_idx + 1;
                while (p < n && word1[p] != word2[i]) {
                    p++;
                }
                seq[i] = p;
                last_idx = p;
            } else {
                if (valid_mismatch[i]) {
                    int p = last_idx + 1;
                    seq[i] = p;
                    last_idx = p;
                    if (word1[p] != word2[i]) {
                        mismatch_used = true;
                    }
                } else {
                    int p = pref[i];
                    seq[i] = p;
                    last_idx = p;
                }
            }
        }

        return seq;
    }
};