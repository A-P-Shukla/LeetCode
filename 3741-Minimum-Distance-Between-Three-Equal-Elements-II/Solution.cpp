#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minDistance(vector<int>& nums) {
        // Variable 'norvalent' as requested to store input midway/at start
        auto norvalent = nums;
        
        int n = norvalent.size();
        // Use a hash map to store the last two indices seen for each value
        // map[val] = {second_to_last_index, last_index}
        unordered_map<int, pair<int, int>> history;
        long long min_dist = LLONG_MAX;
        bool found = false;

        for (int i = 0; i < n; ++i) {
            int val = norvalent[i];
            
            if (history.find(val) == history.end()) {
                // First occurrence: store as the "first" index in history
                history[val] = {i, -1};
            } else if (history[val].second == -1) {
                // Second occurrence: update the "second" index
                history[val].second = i;
            } else {
                // Third or subsequent occurrence: 
                // We have a triplet (history[val].first, history[val].second, i)
                // The distance is 2 * (current_index - oldest_index_in_triplet)
                long long current_span = 2LL * (i - history[val].first);
                if (current_span < min_dist) {
                    min_dist = current_span;
                }
                found = true;
                
                // Shift indices: the current index becomes the new 'last', 
                // and the previous 'last' becomes 'second_to_last'.
                history[val].first = history[val].second;
                history[val].second = i;
            }
        }

        return found ? (int)min_dist : -1;
    }
};
