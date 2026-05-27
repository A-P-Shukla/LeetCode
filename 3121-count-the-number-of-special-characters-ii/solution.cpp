#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        // Track the last occurrence of lowercase letters and first occurrence of uppercase letters
        vector<int> last_lower(26, -1);
        vector<int> first_upper(26, -1);
        
        int n = word.length();
        for (int i = 0; i < n; ++i) {
            char c = word[i];
            if (c >= 'a' && c <= 'z') {
                last_lower[c - 'a'] = i;
            } else if (c >= 'A' && c <= 'Z') {
                // We only record the first occurrence of the uppercase letter
                if (first_upper[c - 'A'] == -1) {
                    first_upper[c - 'A'] = i;
                }
            }
        }
        
        int special_count = 0;
        // Check conditions for each of the 26 English letters
        for (int i = 0; i < 26; ++i) {
            if (last_lower[i] != -1 && first_upper[i] != -1 && last_lower[i] < first_upper[i]) {
                special_count++;
            }
        }
        
        return special_count;
    }
};