#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    /**
     * @brief Checks if a string is a palindrome considering only alphanumeric characters.
     * Uses two pointers that skip non-alphanumeric characters.
     */
    bool isPalindrome(string s) {
        int left = 0, right = (int)s.size() - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left]))  ++left;
            while (left < right && !isalnum(s[right])) --right;
            if (tolower(s[left]) != tolower(s[right])) return false;
            ++left; --right;
        }
        return true;
    }
};
