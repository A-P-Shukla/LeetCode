#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int maximumLength(std::vector<int>& nums) {
        std::unordered_map<long long, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        int max_len = 1;

        // Handle base 1 separately
        if (counts.count(1)) {
            int ones = counts[1];
            if (ones % 2 == 0) ones--;
            max_len = std::max(max_len, ones);
        }

        // Handle bases > 1
        for (auto const& [x, count] : counts) {
            if (x == 1) continue;

            long long curr = x;
            int current_len = 0;
            
            while (counts.count(curr) && counts[curr] >= 2) {
                current_len += 2;
                curr *= curr;
            }
            
            if (counts.count(curr)) {
                current_len += 1;
            } else {
                // If we ran out, the last squared value was actually the middle
                current_len -= 1;
            }
            
            max_len = std::max(max_len, current_len);
        }

        return max_len;
    }
};