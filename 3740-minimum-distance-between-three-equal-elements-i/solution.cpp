#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    /**
     * Calculates the minimum distance of a good tuple (i, j, k).
     * The distance simplifies to 2 * (max_index - min_index).
     */
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        // Map to store indices for each value encountered
        unordered_map<int, vector<int>> valueToIndices;
        
        for (int i = 0; i < n; ++i) {
            valueToIndices[nums[i]].push_back(i);
        }
        
        int minDistance = INT_MAX;
        bool found = false;
        
        for (auto const& [val, indices] : valueToIndices) {
            // A good tuple requires at least 3 occurrences of the same value
            if (indices.size() >= 3) {
                found = true;
                // To minimize 2 * (indices[k] - indices[i]), we check 
                // consecutive triplets in the sorted indices list.
                for (size_t i = 0; i <= indices.size() - 3; ++i) {
                    int currentDist = 2 * (indices[i + 2] - indices[i]);
                    if (currentDist < minDistance) {
                        minDistance = currentDist;
                    }
                }
            }
        }
        
        return found ? minDistance : -1;
    }
};