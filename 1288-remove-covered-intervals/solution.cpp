#include <vector>
#include <algorithm>

class Solution {
public:
    int removeCoveredIntervals(std::vector<std::vector<int>>& intervals) {
        // Sort: ascending start, descending end for same starts
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });

        int count = 0;
        int max_r = 0;

        for (const auto& interval : intervals) {
            // If current interval's end is within the max_r, it's covered
            if (interval[1] > max_r) {
                // Not covered, update max_r and count it
                max_r = interval[1];
                count++;
            }
        }

        return count;
    }
};