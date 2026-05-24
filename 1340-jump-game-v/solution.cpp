#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int n;
    vector<int> memo;

    int solve(int i, const vector<int>& arr, int d) {
        // If already computed, return the cached result
        if (memo[i] != -1) {
            return memo[i];
        }

        int max_visited = 1;

        // Try jumping to the right
        for (int j = i + 1; j <= min(n - 1, i + d); ++j) {
            if (arr[j] >= arr[i]) {
                break; // Met a "wall", cannot jump here or further
            }
            max_visited = max(max_visited, 1 + solve(j, arr, d));
        }

        // Try jumping to the left
        for (int j = i - 1; j >= max(0, i - d); --j) {
            if (arr[j] >= arr[i]) {
                break; // Met a "wall", cannot jump here or further
            }
            max_visited = max(max_visited, 1 + solve(j, arr, d));
        }

        return memo[i] = max_visited;
    }

public:
    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        memo.assign(n, -1);
        int ans = 0;

        // Find the maximum path starting from any index
        for (int i = 0; i < n; ++i) {
            ans = max(ans, solve(i, arr, d));
        }

        return ans;
    }
};