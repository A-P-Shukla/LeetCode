#include <string>
#include <iostream>

class Solution {
public:
    long long concatenateNonZeroDigitsAndMultiplyBySum(int n) {
        if (n == 0) return 0;
        
        std::string s = std::to_string(n);
        std::string x_str = "";
        
        // Filter out non-zero digits
        for (char c : s) {
            if (c != '0') {
                x_str += c;
            }
        }
        
        // Handle edge case where no non-zero digits are found
        if (x_str.empty()) return 0;
        
        long long x = std::stoll(x_str);
        long long digit_sum = 0;
        
        // Calculate sum of digits of x
        for (char c : x_str) {
            digit_sum += (c - '0');
        }
        
        return x * digit_sum;
    }
};