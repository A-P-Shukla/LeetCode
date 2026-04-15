#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int minDistance = -1;

        for (int i = 0; i < n; ++i) {
            if (words[i] == target) {
                // Calculate the absolute distance between indices
                int directDist = abs(i - startIndex);
                
                // In a circular array of size n, the distance between two indices 
                // is either the direct distance or the wrap-around distance
                int currentDist = min(directDist, n - directDist);
                
                // Initialize minDistance or update if a smaller distance is found
                if (minDistance == -1 || currentDist < minDistance) {
                    minDistance = currentDist;
                }
            }
        }

        return minDistance;
    }
};