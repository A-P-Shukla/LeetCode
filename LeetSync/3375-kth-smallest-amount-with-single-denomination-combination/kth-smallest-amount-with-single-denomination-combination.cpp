class Solution {
private:
    long long gcd(long long a, long long b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

public:
    long long findKthSmallest(std::vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());
        vector<long long> filtered_coins;
        for (int coin : coins) {
            bool redundant = false;
            for (long long fc : filtered_coins) {
                if (coin % fc == 0) {
                    redundant = true;
                    break;
                }
            }
            if (!redundant) {
                filtered_coins.push_back(coin);
            }
        }

        int n = filtered_coins.size();

        auto count = [&](long long x) -> long long {
            long long total = 0;
            int total_subsets = 1 << n;
            for (int mask = 1; mask < total_subsets; ++mask) {
                long long current_lcm = 1;
                int subset_size = 0;
                for (int i = 0; i < n; ++i) {
                    if ((mask >> i) & 1) {
                        subset_size++;
                        current_lcm = lcm(current_lcm, filtered_coins[i]);
                    }
                }
                
                if (subset_size % 2 == 1) {
                    total += x / current_lcm;
                } else {
                    total -= x / current_lcm;
                }
            }
            return total;
        };

        long long low = 1;
        long long high = filtered_coins[0] * (long long)k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (count(mid) >= k) {
                ans = mid;
                high = mid - 1; 
            } else {
                low = mid + 1;  
            }
        }

        return ans;
    }
};