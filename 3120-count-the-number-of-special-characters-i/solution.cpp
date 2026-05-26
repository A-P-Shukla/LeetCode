#include <string>

class Solution {
public:
    int numberOfSpecialChars(std::string word) {
        // Bitmasks to track the presence of lowercase and uppercase English letters
        int lower_mask = 0;
        int upper_mask = 0;
        
        for (char c : word) {
            if (c >= 'a' && c <= 'z') {
                lower_mask |= (1 << (c - 'a'));
            } else if (c >= 'A' && c <= 'Z') {
                upper_mask |= (1 << (c - 'A'));
            }
        }
        
        // Find the intersection of both masks and count set bits
        return __builtin_popcount(lower_mask & upper_mask);
    }
};