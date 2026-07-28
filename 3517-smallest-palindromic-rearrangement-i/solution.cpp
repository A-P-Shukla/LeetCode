#include <string>
#include <algorithm>

class Solution {
public:
    std::string smallestPalindrome(std::string s) {
        int n = s.length();
        int half_len = n / 2;
        
        // Extract the first half of the palindromic string
        std::string half = s.substr(0, half_len);
        
        // Sort the first half to achieve the lexicographically smallest prefix
        std::sort(half.begin(), half.end());
        
        // Create the right half by reversing the sorted left half
        std::string rev_half = half;
        std::reverse(rev_half.begin(), rev_half.end());
        
        // If length is odd, include the middle character from s[half_len]
        if (n % 2 == 1) {
            return half + s[half_len] + rev_half;
        } else {
            return half + rev_half;
        }
    }
};