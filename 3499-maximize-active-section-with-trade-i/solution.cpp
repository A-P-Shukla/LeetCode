#include <vector>
#include <string>
#include <algorithm>
#include <climits>

class Solution {
public:
    int maximizeActiveSection(std::string s) {
        int n = s.length();
        std::vector<int> ones, zeros;
        
        // Parse the string into blocks of 1s and 0s
        int total_ones = 0;
        int i = 0;
        bool start_with_one = (s[0] == '1');
        
        while (i < n) {
            int count = 0;
            char target = s[i];
            while (i < n && s[i] == target) {
                count++;
                i++;
            }
            if (target == '1') {
                ones.push_back(count);
                total_ones += count;
            } else {
                zeros.push_back(count);
            }
        }

        if (zeros.empty()) return total_ones;

        // If s starts with 0, add a dummy 0-length 1 block at start
        if (!start_with_one) ones.insert(ones.begin(), 0);
        // If s ends with 0, add a dummy 0-length 1 block at end
        if (s.back() == '0') ones.push_back(0);

        int max_gain = 0;
        // For each block of 0s, we can flip it to 1s.
        // We must remove a block of 1s that is adjacent to this block of 0s.
        for (size_t j = 0; j < zeros.size(); ++j) {
            int gain = zeros[j] - std::min(ones[j], ones[j + 1]);
            max_gain = std::max(max_gain, gain);
        }

        return total_ones + max_gain;
    }
};