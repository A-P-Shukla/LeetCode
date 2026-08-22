class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum = 0;
        int digitProduct = 1;
        int temp = n;

        // Extract digits and calculate sum and product
        while (temp > 0) {
            int digit = temp % 10;
            digitSum += digit;
            digitProduct *= digit;
            temp /= 10;
        }

        int total = digitSum + digitProduct;

        // Check divisibility
        return (n % total == 0);
    }
};