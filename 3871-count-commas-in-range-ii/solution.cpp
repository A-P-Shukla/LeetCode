class Solution {
public:
    long long countCommas(long long n) {
        long long totalCommas = 0;
        long long threshold = 1000;
        
        // Count how many numbers reach each comma threshold (1,000, 1,000,000, etc.)
        while (n >= threshold) {
            totalCommas += (n - threshold + 1);
            
            // Prevent 64-bit integer overflow when advancing threshold
            if (threshold > LLONG_MAX / 1000) {
                break;
            }
            threshold *= 1000;
        }
        
        return totalCommas;
    }
};