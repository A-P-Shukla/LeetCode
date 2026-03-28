#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string word(n, '\0');
        char cur = 'a';

        // Greedy assignment: Try to assign the smallest available char 'a'-'z'
        for (int i = 0; i < n; ++i) {
            if (word[i] != '\0') continue;
            
            // If we run out of lowercase English letters, no solution exists
            if (cur > 'z') return "";
            
            for (int j = i; j < n; ++j) {
                if (lcp[i][j] > 0) {
                    word[j] = cur;
                }
            }
            cur++;
        }

        // Verification: Check if the generated string matches the LCP matrix
        // We use the LCP matrix itself or a DP approach to verify consistency.
        // word[i, n-1] and word[j, n-1] LCP calculation:
        // if word[i] == word[j]: LCP(i, j) = 1 + LCP(i+1, j+1)
        // else: LCP(i, j) = 0
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int expected_lcp = 0;
                if (word[i] == word[j]) {
                    expected_lcp = (i + 1 < n && j + 1 < n) ? 1 + lcp[i + 1][j + 1] : 1;
                }
                
                if (lcp[i][j] != expected_lcp) {
                    return "";
                }
            }
        }

        return word;
    }
};