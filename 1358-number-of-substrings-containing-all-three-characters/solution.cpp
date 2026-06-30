#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int numberOfSubstrings(std::string s) {
        // frequency array to store count of 'a', 'b', and 'c'
        int count[3] = {0, 0, 0};
        int left = 0, result = 0;
        int n = s.length();

        for (int right = 0; right < n; ++right) {
            // Update the count for the character at the right boundary
            count[s[right] - 'a']++;

            // While the current window is valid (has at least one of each)
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                // If s[left...right] is valid, then all s[i...right] where 
                // i <= left are also valid. There are (left + 1) such substrings.
                result += (n - right);
                
                // Shrink the window from the left
                count[s[left] - 'a']--;
                left++;
            }
        }
        return result;
    }
};