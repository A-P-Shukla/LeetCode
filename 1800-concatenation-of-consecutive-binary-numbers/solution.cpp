class Solution {
public:
    /**
     * @brief Calculates the decimal value of concatenated binary representations from 1 to n.
     * 
     * The approach uses bit manipulation to shift the current result by the bit-length 
     * of the current number 'i' and then add 'i' to the result.
     */
    int concatenatedBinary(int n) {
        long long res = 0;
        const int MOD = 1e9 + 7;
        int length = 0;

        for (int i = 1; i <= n; ++i) {
            // When i is a power of 2, the number of bits required to represent i increases.
            // Example: 1 (1 bit), 2 (2 bits), 4 (3 bits), 8 (4 bits).
            if ((i & (i - 1)) == 0) {
                length++;
            }

            // Shift the current result to make room for i, then add i (using OR or addition).
            // (res << length) moves existing bits to the left.
            // i provides the new bits to fill the lower 'length' positions.
            res = ((res << length) | i) % MOD;
        }

        return (int)res;
    }
};