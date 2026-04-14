#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
    long long memo[101][101];
    const long long INF = 1e15; // Sufficiently large value for infinity

    long long solve(int robotIdx, int factoryIdx, const vector<int>& robot, const vector<vector<int>>& factory) {
        // Base case: All robots have been repaired
        if (robotIdx == robot.size()) return 0;
        // Base case: No more factories left, but robots remain
        if (factoryIdx == factory.size()) return INF;

        // Check memoization table
        if (memo[robotIdx][factoryIdx] != -1) return memo[robotIdx][factoryIdx];

        // Option 1: Skip the current factory entirely
        long long res = solve(robotIdx, factoryIdx + 1, robot, factory);

        // Option 2: Assign 'k' robots to the current factory
        long long currentDist = 0;
        int limit = factory[factoryIdx][1];
        int factoryPos = factory[factoryIdx][0];

        // Try assigning k robots, where 1 <= k <= factory limit and doesn't exceed remaining robots
        for (int k = 1; k <= limit && robotIdx + k <= robot.size(); ++k) {
            currentDist += abs(robot[robotIdx + k - 1] - factoryPos);
            long long subProblem = solve(robotIdx + k, factoryIdx + 1, robot, factory);
            
            if (subProblem != INF) {
                res = min(res, currentDist + subProblem);
            }
        }

        return memo[robotIdx][factoryIdx] = res;
    }

public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // Sort both to ensure relative order is preserved
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        // Initialize memo table with -1
        for (int i = 0; i <= robot.size(); ++i) {
            for (int j = 0; j <= factory.size(); ++j) {
                memo[i][j] = -1;
            }
        }

        return solve(0, 0, robot, factory);
    }
};