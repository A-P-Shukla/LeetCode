#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int min_finish_time = 2e9; // Initialize with a very large value

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // Option 1: Land ride first, then Water ride
                int land_finish = landStartTime[i] + landDuration[i];
                int water_start = max(land_finish, waterStartTime[j]);
                int finish_option_1 = water_start + waterDuration[j];

                // Option 2: Water ride first, then Land ride
                int water_finish = waterStartTime[j] + waterDuration[j];
                int land_start = max(water_finish, landStartTime[i]);
                int finish_option_2 = land_start + landDuration[i];

                // Keep track of the minimum possible finish time
                min_finish_time = min({min_finish_time, finish_option_1, finish_option_2});
            }
        }

        return min_finish_time;
    }
};