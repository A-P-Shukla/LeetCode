#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * Helper function to check if all workers can reduce the mountain height
     * to zero within the given time 'mid'.
     */
    bool canReduce(long long mid, int mountainHeight, const vector<int>& workerTimes) {
        long long totalHeightReduced = 0;
        
        for (int wTime : workerTimes) {
            // Formula: wTime * x * (x + 1) / 2 <= mid
            // Solving for x: x^2 + x - (2 * mid / wTime) <= 0
            // Using quadratic formula: x = (-1 + sqrt(1 + 8 * mid / wTime)) / 2
            double limit = (2.0 * mid) / wTime;
            long long x = (-1.0 + sqrt(1.0 + 4.0 * limit)) / 2.0;
            
            totalHeightReduced += x;
            
            // Early exit if we've already met the target
            if (totalHeightReduced >= mountainHeight) {
                return true;
            }
        }
        
        return totalHeightReduced >= mountainHeight;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        // Lower bound: 1 second (or 0 if height is already 0)
        // Upper bound: The slowest worker handles the entire mountain height.
        // If wTime = 10^6 and mountainHeight = 10^5, T approx 10^6 * (10^10 / 2) = 5 * 10^15.
        long long low = 0;
        long long high = 1e16; // Sufficiently large for constraints
        long long result = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (canReduce(mid, mountainHeight, workerTimes)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
};
