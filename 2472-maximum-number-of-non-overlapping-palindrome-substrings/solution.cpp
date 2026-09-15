#include <string>

class Solution {
private:
    // Helper function to check if s[left..right] is a palindrome
    bool isPalindrome(const std::string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

public:
    int maxPalindromes(std::string s, int k) {
        int n = s.length();
        int count = 0;
        int last_end = 0; // Tracks the end of the last selected substring

        for (int i = k - 1; i < n; ++i) {
            // Check for palindrome of length k ending at i
            if (i - k + 1 >= last_end && isPalindrome(s, i - k + 1, i)) {
                count++;
                last_end = i + 1;
            }
            // Check for palindrome of length k + 1 ending at i
            else if (i - k >= last_end && isPalindrome(s, i - k, i)) {
                count++;
                last_end = i + 1;
            }
        }

        return count;
    }
};