#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(const string& s) {
        int low = 0;   // minimum possible '(' count
        int high = 0;  // maximum possible '(' count

        for (char ch : s) {
            if (ch == '(') {
                ++low;
                ++high;
            } else if (ch == ')') {
                --low;
                --high;
            } else { // ch == '*'
                // * as ')' reduces low, * as '(' increases high
                --low;
                ++high;
            }

            // low cannot be negative: we can treat extra '*' as empty
            if (low < 0) low = 0;

            // If high becomes negative, too many ')'
            if (high < 0) return false;
        }

        // If we can end with zero '(' in the best case, it's valid
        return low == 0;
    }
};