#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Directions: 0: North, 1: East, 2: South, 3: West
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        // Use a hash set for O(1) obstacle lookup.
        // Pack (x, y) into a long long: (x + 30000) << 16 | (y + 30000)
        // Coordinates are between -30000 and 30000.
        unordered_set<long long> obstacleSet;
        for (const auto& obs : obstacles) {
            long long x = obs[0] + 30000;
            long long y = obs[1] + 30000;
            obstacleSet.insert((x << 16) | y);
        }
        
        int x = 0, y = 0, dir = 0;
        int maxDistSq = 0;
        
        for (int cmd : commands) {
            if (cmd == -2) {
                // Turn left: North -> West -> South -> East
                dir = (dir + 3) % 4;
            } else if (cmd == -1) {
                // Turn right: North -> East -> South -> West
                dir = (dir + 1) % 4;
            } else {
                // Move forward cmd steps
                for (int k = 0; k < cmd; ++k) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    
                    long long code = (((long long)nx + 30000) << 16) | ((long long)ny + 30000);
                    if (obstacleSet.find(code) != obstacleSet.end()) {
                        break; // Stop moving in this direction
                    }
                    
                    x = nx;
                    y = ny;
                    maxDistSq = max(maxDistSq, x * x + y * y);
                }
            }
        }
        
        return maxDistSq;
    }
};