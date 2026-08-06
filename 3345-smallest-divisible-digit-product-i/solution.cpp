class Solution {
private:
    // Helper function to calculate the product of digits of a given number
    int getDigitProduct(int num) {
        int product = 1;
        while (num > 0) {
            product *= (num % 10);
            num /= 10;
        }
        return product;
    }

public:
    int smallestNumber(int n, int t) {
        // Iterate starting from n until we find a number with a digit product divisible by t
        while (true) {
            if (getDigitProduct(n) % t == 0) {
                return n;
            }
            n++;
        }
    }
};