#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        // Map values to all indices containing that value
        unordered_map<int, vector<int>> indicesOfValue;
        for (int i = 0; i < n; i++) {
            indicesOfValue[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(0);
        visited[0] = true;
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int i = q.front();
                q.pop();

                // Target reached
                if (i == n - 1) return steps;

                // Move 1: i + 1
                if (i + 1 < n && !visited[i + 1]) {
                    visited[i + 1] = true;
                    q.push(i + 1);
                }

                // Move 2: i - 1
                if (i - 1 >= 0 && !visited[i - 1]) {
                    visited[i - 1] = true;
                    q.push(i - 1);
                }

                // Move 3: jump to indices with same value
                if (indicesOfValue.count(arr[i])) {
                    for (int nextIndex : indicesOfValue[arr[i]]) {
                        if (!visited[nextIndex]) {
                            visited[nextIndex] = true;
                            q.push(nextIndex);
                        }
                    }
                    // Optimization: Once all same-value jumps are processed, 
                    // clear the list to avoid O(N^2) behavior.
                    indicesOfValue.erase(arr[i]);
                }
            }
            steps++;
        }

        return -1;
    }
};