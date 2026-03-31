#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    /**
     * Generates the lexicographically smallest string satisfying str1 and str2 constraints.
     */
    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int N = n + m - 1;
        
        string res(N, '?');
        vector<bool> fixed(N, false);

        // Step 1: Process 'T' constraints to fix mandatory characters
        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'T') {
                for (int k = 0; k < m; ++k) {
                    if (res[i + k] != '?' && res[i + k] != str2[k]) {
                        return ""; // Overlap conflict
                    }
                    res[i + k] = str2[k];
                    fixed[i + k] = true;
                }
            }
        }

        // Step 2: Initialize unassigned positions with 'a' for lexicographical minimality
        for (int i = 0; i < N; ++i) {
            if (res[i] == '?') {
                res[i] = 'a';
            }
        }

        // Step 3: Handle 'F' violations greedily from left to right
        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'F') {
                // If the substring matches str2, we must break the match
                if (memcmp(res.data() + i, str2.data(), m) == 0) {
                    bool resolved = false;
                    
                    // Try changing the rightmost possible character to minimize impact on prefix
                    for (int j = i + m - 1; j >= i; --j) {
                        if (fixed[j]) continue;
                        
                        char original_char = res[j];
                        for (char c = 'a'; c <= 'z'; ++c) {
                            // Must change to a different character that doesn't match str2 at this pos
                            if (c == original_char || c == str2[j - i]) continue;
                            
                            res[j] = c;
                            bool valid = true;
                            
                            // Ensure this change doesn't violate any constraints from 0 to i
                            // Only windows overlapping with index j need to be re-checked
                            for (int k = max(0, j - m + 1); k <= i; ++k) {
                                if (str1[k] == 'F') {
                                    if (memcmp(res.data() + k, str2.data(), m) == 0) {
                                        valid = false;
                                        break;
                                    }
                                }
                            }
                            
                            if (valid) {
                                resolved = true;
                                break;
                            }
                            res[j] = original_char; // Backtrack
                        }
                        if (resolved) break;
                    }
                    
                    if (!resolved) return ""; // No character choice satisfies constraints
                }
            }
        }

        return res;
    }
};