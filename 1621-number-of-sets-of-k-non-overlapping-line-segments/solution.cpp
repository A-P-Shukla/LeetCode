class Solution {
private:
    static constexpr int MOD = 1e9 + 7;
    
    // Helper function to compute (base^exp) % MOD
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

public:
    int numberOfSets(int n, int k) {
        int N = n + k - 1;
        int R = 2 * k;
        
        if (R > N) return 0;
        
        long long num = 1;
        long long den = 1;
        
        // Compute N! / (R! * (N - R)!) modulo 10^9 + 7
        for (int i = 1; i <= R; ++i) {
            num = (num * (N - i + 1)) % MOD;
            den = (den * i) % MOD;
        }
        
        // num * den^(-1) % MOD using Fermat's Little Theorem
        return (num * power(den, MOD - 2)) % MOD;
    }
};