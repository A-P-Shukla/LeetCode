#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution {
public:
    bool check(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long totalSum = 0;
        unordered_map<int, int> totalMap;

        // Build total sum and frequency map of all cells
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                totalSum += grid[i][j];
                totalMap[grid[i][j]]++;
            }
        }

        // 1. Check Horizontal Cuts (Cut after row i)
        long long s1 = 0;
        unordered_map<int, int> leftMap;
        unordered_map<int, int> rightMap = totalMap;
        for (int i = 0; i < m - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                int val = grid[i][j];
                leftMap[val]++;
                if (--rightMap[val] == 0) rightMap.erase(val);
                s1 += val;
            }
            long long s2 = totalSum - s1;
            if (s1 == s2) return true;

            if (s1 > s2) {
                long long v = s1 - s2;
                if (v <= 100000) { // Max cell value is 10^5
                    int H = i + 1, W = n;
                    if (H > 1 && W > 1) {
                        if (leftMap.count((int)v)) return true;
                    } else if (H == 1 && W > 1) {
                        if (grid[0][0] == v || grid[0][n - 1] == v) return true;
                    } else if (H > 1 && W == 1) {
                        if (grid[0][0] == v || grid[i][0] == v) return true;
                    }
                }
            } else {
                long long v = s2 - s1;
                if (v <= 100000) {
                    int H = m - 1 - i, W = n;
                    if (H > 1 && W > 1) {
                        if (rightMap.count((int)v)) return true;
                    } else if (H == 1 && W > 1) {
                        if (grid[m - 1][0] == v || grid[m - 1][n - 1] == v) return true;
                    } else if (H > 1 && W == 1) {
                        if (grid[i + 1][0] == v || grid[m - 1][0] == v) return true;
                    }
                }
            }
        }

        // 2. Check Vertical Cuts (Cut after column j)
        s1 = 0;
        leftMap.clear();
        rightMap = totalMap;
        for (int j = 0; j < n - 1; ++j) {
            for (int i = 0; i < m; ++i) {
                int val = grid[i][j];
                leftMap[val]++;
                if (--rightMap[val] == 0) rightMap.erase(val);
                s1 += val;
            }
            long long s2 = totalSum - s1;
            if (s1 == s2) return true;

            if (s1 > s2) {
                long long v = s1 - s2;
                if (v <= 100000) {
                    int H = m, W = j + 1;
                    if (H > 1 && W > 1) {
                        if (leftMap.count((int)v)) return true;
                    } else if (H == 1 && W > 1) {
                        if (grid[0][0] == v || grid[0][j] == v) return true;
                    } else if (H > 1 && W == 1) {
                        if (grid[0][0] == v || grid[m - 1][0] == v) return true;
                    }
                }
            } else {
                long long v = s2 - s1;
                if (v <= 100000) {
                    int H = m, W = n - 1 - j;
                    if (H > 1 && W > 1) {
                        if (rightMap.count((int)v)) return true;
                    } else if (H == 1 && W > 1) {
                        if (grid[0][j + 1] == v || grid[0][n - 1] == v) return true;
                    } else if (H > 1 && W == 1) {
                        if (grid[0][n - 1] == v || grid[m - 1][n - 1] == v) return true;
                    }
                }
            }
        }

        return false;
    }
};
---