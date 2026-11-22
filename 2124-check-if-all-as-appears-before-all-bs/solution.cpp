#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Returns true if every 'a' appears before every 'b' in the string s.
    bool checkString(const string& s) {
        bool seenB = false;                // Flag: have we encountered a 'b' yet?
        for (char ch : s) {
            if (ch == 'b') {
                seenB = true;               // Once a 'b' appears, all subsequent chars must be 'b'.
            } else { // ch == 'a'
                if (seenB) {
                    // An 'a' after a 'b' violates the required ordering.
                    return false;
                }
            }
        }
        return true;                       // No violation found.
    }
};