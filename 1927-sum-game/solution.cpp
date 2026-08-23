#include <string>

class Solution {
public:
    bool sumGame(std::string num) {
        int n = num.length();
        int leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;

        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') {
                leftQ++;
            } else {
                leftSum += num[i] - '0';
            }
        }

        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') {
                rightQ++;
            } else {
                rightSum += num[i] - '0';
            }
        }

        // Bob wins if and only if 2 * (leftSum - rightSum) + 9 * (leftQ - rightQ) == 0.
        // If it equals 0, Bob wins (return false). Otherwise, Alice wins (return true).
        return 2 * (leftSum - rightSum) + 9 * (leftQ - rightQ) != 0;
    }
};