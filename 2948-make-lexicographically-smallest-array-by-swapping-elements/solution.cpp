#include <vector>
#include <algorithm>
#include <unordered_map>
#include <deque>

class Solution {
public:
    std::vector<int> lexicographicallySmallestArray(std::vector<int>& nums, int limit) {
        int n = nums.size();
        
        // Make a sorted copy of nums to group connected elements
        std::vector<int> sortedNums = nums;
        std::sort(sortedNums.begin(), sortedNums.end());

        std::vector<std::deque<int>> groupQueues;
        std::unordered_map<int, int> numToGroup;

        // Group elements: adjacent elements with difference <= limit belong to the same group
        for (int i = 0; i < n; ++i) {
            if (i == 0 || sortedNums[i] - sortedNums[i - 1] > limit) {
                groupQueues.push_back({});
            }
            groupQueues.back().push_back(sortedNums[i]);
            numToGroup[sortedNums[i]] = groupQueues.size() - 1;
        }

        // Reconstruct the lexicographically smallest array
        std::vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            int group = numToGroup[nums[i]];
            result[i] = groupQueues[group].front();
            groupQueues[group].pop_front();
        }

        return result;
    }
};