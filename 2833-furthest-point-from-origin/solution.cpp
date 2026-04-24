#include <string>
#include <cmath>
#include <algorithm>

class Solution {
public:
    /**
     * Calculates the furthest point from the origin by counting the frequency
     * of each move type and greedily assigning the underscores.
     */
    int furthestDistanceFromOrigin(std::string moves) {
        int countL = 0;
        int countR = 0;
        int countUnderscore = 0;

        for (char move : moves) {
            if (move == 'L') {
                countL++;
            } else if (move == 'R') {
                countR++;
            } else {
                countUnderscore++;
            }
        }

        // The logic: abs(net_fixed_distance) + total_flexible_moves
        return std::abs(countL - countR) + countUnderscore;
    }
};