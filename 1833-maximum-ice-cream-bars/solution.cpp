#include <vector>
#include <algorithm>

class Solution {
public:
    int maxIceCream(std::vector<int>& costs, int coins) {
        // Find the maximum cost to determine the size of the frequency array
        int max_cost = 0;
        for (int cost : costs) {
            max_cost = std::max(max_cost, cost);
        }

        // Create frequency array
        std::vector<int> freq(max_cost + 1, 0);
        for (int cost : costs) {
            freq[cost]++;
        }

        int count = 0;
        // Iterate through costs in ascending order
        for (int cost = 1; cost <= max_cost; ++cost) {
            if (freq[cost] > 0) {
                // Determine how many bars of this price we can afford
                long long can_buy = std::min((long long)freq[cost], (long long)coins / cost);
                
                count += (int)can_buy;
                coins -= (int)(can_buy * cost);
                
                // If we cannot afford anymore of the current price, we stop
                if (coins < cost) break;
            }
        }
        
        return count;
    }
};