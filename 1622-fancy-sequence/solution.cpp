#include <vector>

using namespace std;

class Fancy {
private:
    long long multiplier = 1;
    long long increment = 0;
    vector<long long> nums;
    const int MOD = 1e9 + 7;

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

    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    Fancy() {
        nums.reserve(100000);
    }
    
    void append(int val) {
        // We want to store x such that (multiplier * x + increment) % MOD == val
        // x = (val - increment) * inv(multiplier) % MOD
        long long val_long = val;
        long long x = (val_long - increment + MOD) % MOD;
        x = (x * modInverse(multiplier)) % MOD;
        nums.push_back(x);
    }
    
    void addAll(int inc) {
        increment = (increment + inc) % MOD;
    }
    
    void multAll(int m) {
        multiplier = (multiplier * m) % MOD;
        increment = (increment * m) % MOD;
    }
    
    int getIndex(int idx) {
        if (idx >= nums.size()) return -1;
        // Apply current global transformation to the stored normalized value
        return (nums[idx] * multiplier + increment) % MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */