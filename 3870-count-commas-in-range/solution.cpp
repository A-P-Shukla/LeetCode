class Solution {
public:
    int countCommas(int n) {
        long long totalCommas = 0;
        long long threshold = 1000;

        // Add the contribution for each threshold of 1000^k
        while (n >= threshold) {
            totalCommas += (n - threshold + 1);
            threshold *= 1000;
        }

        return totalCommas;
    }
};