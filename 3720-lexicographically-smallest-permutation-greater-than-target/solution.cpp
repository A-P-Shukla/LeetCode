#include <string>
#include <vector>
#include <numeric>

class Solution {
public:
    string nextPermutation(string s, string target) {
        int n = s.length();
        vector<int> counts(26, 0);
        
        // Count frequencies of characters in s
        for (char c : s) {
            counts[c - 'a']++;
        }
        
        // Find maximum prefix length L of target that s can match
        int L = 0;
        while (L < n && counts[target[L] - 'a'] > 0) {
            counts[target[L] - 'a']--;
            L++;
        }
        
        // If target was completely matched, adjust L to n - 1 and restore target[n - 1]
        if (L == n) {
            L--;
            counts[target[L] - 'a']++;
        }
        
        // Try to find the largest index i where we can place a character > target[i]
        for (int i = L; i >= 0; --i) {
            int targetCharIndex = target[i] - 'a';
            
            // Look for the smallest available character > target[i]
            int replacementChar = -1;
            for (int c = targetCharIndex + 1; c < 26; ++c) {
                if (counts[c] > 0) {
                    replacementChar = c;
                    break;
                }
            }
            
            if (replacementChar != -1) {
                // Found a valid configuration! Construct the answer string
                string result = target.substr(0, i);
                
                // Place the strictly greater character
                result += (char)('a' + replacementChar);
                counts[replacementChar]--;
                
                // Fill the rest with remaining characters in ascending order
                for (int c = 0; c < 26; ++c) {
                    while (counts[c] > 0) {
                        result += (char)('a' + c);
                        counts[c]--;
                    }
                }
                
                return result;
            }
            
            // If index i cannot be made larger, backtrack target[i - 1] for index i - 1
            if (i > 0) {
                counts[target[i - 1] - 'a']++;
            }
        }
        
        return "";
    }
};