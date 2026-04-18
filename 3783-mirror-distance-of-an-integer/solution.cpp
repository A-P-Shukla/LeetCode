#include <cmath>
#include <cstdlib>

class Solution {
public:
    /**
     * Calculates the absolute difference between n and its digit-wise reverse.
     * Uses long long to handle reversal safely.
     */
    long long mirrorDistance(int n) {
        long long original = n;
        long long reversedN = 0;
        long long temp = n;

        // Extract digits one by one and build the reversed number
        while (temp > 0) {
            int digit = temp % 10;
            reversedN = reversedN * 10 + digit;
            temp /= 10;
        }

        // Return the absolute difference
        return std::abs(original - reversedN);
    }
};