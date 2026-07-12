#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    std::vector<int> arrayRankTransform(std::vector<int>& arr) {
        if (arr.empty()) return {};

        // 1. Create a sorted copy of unique elements
        std::vector<int> sortedArr = arr;
        std::sort(sortedArr.begin(), sortedArr.end());
        
        // Remove duplicates to get unique values
        auto last = std::unique(sortedArr.begin(), sortedArr.end());
        sortedArr.erase(last, sortedArr.end());

        // 2. Map values to their ranks (index + 1)
        std::unordered_map<int, int> rankMap;
        for (int i = 0; i < sortedArr.size(); ++i) {
            rankMap[sortedArr[i]] = i + 1;
        }

        // 3. Transform the original array using the map
        std::vector<int> result;
        result.reserve(arr.size());
        for (int x : arr) {
            result.push_back(rankMap[x]);
        }

        return result;
    }
};