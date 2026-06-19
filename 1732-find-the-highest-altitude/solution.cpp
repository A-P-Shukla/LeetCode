#include <vector>
#include <algorithm>

class Solution {
public:
    /**
     * Calculates the highest altitude reached by a biker.
     * We track the current altitude by accumulating gains and update
     * the maximum altitude observed so far.
     */
    int largestAltitude(std::vector<int>& gain) {
        int maxAltitude = 0;
        int currentAltitude = 0;

        for (int g : gain) {
            currentAltitude += g;
            // Update maxAltitude if the current path leads higher
            if (currentAltitude > maxAltitude) {
                maxAltitude = currentAltitude;
            }
        }

        return maxAltitude;
    }
};