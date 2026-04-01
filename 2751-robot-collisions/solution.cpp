#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);

        // Sort indices based on positions to process robots from left to right
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        vector<int> stack; // Stores indices of robots moving to the right
        vector<bool> destroyed(n, false);

        for (int i : indices) {
            if (directions[i] == 'R') {
                stack.push_back(i);
            } else {
                // Robot moving Left ('L')
                while (!stack.empty() && healths[i] > 0) {
                    int topIdx = stack.back();
                    
                    if (healths[topIdx] < healths[i]) {
                        // 'L' robot destroys 'R' robot
                        healths[topIdx] = 0;
                        destroyed[topIdx] = true;
                        stack.pop_back();
                        healths[i] -= 1;
                    } else if (healths[topIdx] > healths[i]) {
                        // 'R' robot destroys 'L' robot
                        healths[i] = 0;
                        destroyed[i] = true;
                        healths[topIdx] -= 1;
                    } else {
                        // Both destroyed
                        healths[topIdx] = 0;
                        destroyed[topIdx] = true;
                        stack.pop_back();
                        healths[i] = 0;
                        destroyed[i] = true;
                    }
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (!destroyed[i]) {
                result.push_back(healths[i]);
            }
        }
        return result;
    }
};