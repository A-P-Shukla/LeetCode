#include <string>

class Solution {
public:
    bool rotateString(string s, string goal) {
        // If lengths differ, s can never be transformed into goal
        if (s.length() != goal.length()) {
            return false;
        }

        // Any rotation of s is a substring of s + s
        string doubled = s + s;

        // Check if goal exists within the doubled string
        // string::find returns string::npos if the substring is not found
        return doubled.find(goal) != string::npos;
    }
};