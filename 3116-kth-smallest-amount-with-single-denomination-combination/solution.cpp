#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
private:
    // Helper function to calculate GCD
    long long gcd(long long a, long long b) {
        while (b) {
            a %= b;
            std::swap(a, b);
        }
        return a;
    }

    // Helper function to calculate LCM
    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

public:
    long long findKthSmallest(std::vector<int>& coins, int k) {
        // Step 1: Filter out redundant coins
        // E.g., if 3 is present, 6 and 9 are redundant as any multiple of 6 is a multiple of 3.
        std::sort(coins.begin(), coins.end());
        std::vector<long long> filtered_coins;
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

        // Step 2: Function to count multiples <= x using Inclusion-Exclusion Principle
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

        // Step 3: Binary Search for the k-th smallest amount
        long long low = 1;
        long long high = filtered_coins[0] * (long long)k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (count(mid) >= k) {
                ans = mid;
                high = mid - 1; // Try to find a smaller valid amount
            } else {
                low = mid + 1;  // Increase the amount
            }
        }

        return ans;
    }
};