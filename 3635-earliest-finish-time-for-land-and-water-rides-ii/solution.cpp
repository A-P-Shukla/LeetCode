#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        
        // Find the earliest possible finish time for any land ride
        int L_fin_min = INT_MAX;
        for (int i = 0; i < n; ++i) {
            L_fin_min = min(L_fin_min, landStartTime[i] + landDuration[i]);
        }
        
        // Find the earliest possible finish time for any water ride
        int W_fin_min = INT_MAX;
        for (int j = 0; j < m; ++j) {
            W_fin_min = min(W_fin_min, waterStartTime[j] + waterDuration[j]);
        }
        
        // Case 1: Land Ride -> Water Ride
        // We use the land ride that achieves L_fin_min and pair it with the best water ride
        int min_L_to_W = INT_MAX;
        for (int j = 0; j < m; ++j) {
            int W_finish = waterStartTime[j] + waterDuration[j];
            int current_finish = max(W_finish, L_fin_min + waterDuration[j]);
            min_L_to_W = min(min_L_to_W, current_finish);
        }
        
        // Case 2: Water Ride -> Land Ride
        // We use the water ride that achieves W_fin_min and pair it with the best land ride
        int min_W_to_L = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int L_finish = landStartTime[i] + landDuration[i];
            int current_finish = max(L_finish, W_fin_min + landDuration[i]);
            min_W_to_L = min(min_W_to_L, current_finish);
        }
        
        return min(min_L_to_W, min_W_to_L);
    }
};