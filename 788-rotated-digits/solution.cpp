#include <vector>
#include <string>

class Solution {
public:
    /**
     * Checks if a number is "good" based on rotation rules.
     * 0, 1, 8 rotate to themselves.
     * 2, 5, 6, 9 rotate to different digits.
     * 3, 4, 7 are invalid.
     */
    int rotatedDigits(int n) {
        int count = 0;
        for (int i = 1; i <= n; ++i) {
            if (isGood(i)) {
                count++;
            }
        }
        return count;
    }

private:
    bool isGood(int num) {
        bool hasRotatingDigit = false;
        
        while (num > 0) {
            int digit = num % 10;
            
            // If it contains 3, 4, or 7, it's invalid
            if (digit == 3 || digit == 4 || digit == 7) {
                return false;
            }
            
            // If it contains 2, 5, 6, or 9, it's a candidate for being "good"
            if (digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                hasRotatingDigit = true;
            }
            
            num /= 10;
        }
        
        // A number is good only if it's valid and different from itself
        return hasRotatingDigit;
    }
};