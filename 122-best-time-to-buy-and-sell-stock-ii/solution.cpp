#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @brief Maximises profit by collecting every upward price movement.
     * Equivalent to summing all positive day-over-day differences.
     */
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < (int)prices.size(); ++i) {
            if (prices[i] > prices[i - 1])
                profit += prices[i] - prices[i - 1];
        }
        return profit;
    }
};
