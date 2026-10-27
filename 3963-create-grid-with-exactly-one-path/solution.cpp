#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> constructGrid(int m, int n) {
        // Step 1: fill everything with obstacles
        vector<string> grid(m, string(n, '#'));

        // Step 2: create the unique monotone path (down then right)
        for (int i = 0; i < m; ++i) {
            grid[i][0] = '.';               // column 0, rows 0..m-1
        }
        for (int j = 1; j < n; ++j) {
            grid[m - 1][j] = '.';           // bottom row, columns 1..n-1
        }
        return grid;
    }
};