#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
    long long d;
};

class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<Point> pts(n);
        for (int i = 0; i < n; ++i) {
            pts[i].x = points[i][0];
            pts[i].y = points[i][1];
            pts[i].d = getPerimeterDist(pts[i].x, pts[i].y, side);
        }

        sort(pts.begin(), pts.end(), [](const Point& a, const Point& b) {
            return a.d < b.d;
        });

        vector<long long> ds(n);
        for (int i = 0; i < n; ++i) ds[i] = pts[i].d;

        auto can = [&](int D) {
            // We only need to check the first n/k points as potential starts
            for (int i = 0; i <= n / k; ++i) {
                int count = 1;
                int lastIdx = i;
                for (int step = 1; step < k; ++step) {
                    long long target = ds[lastIdx] + D;
                    auto it = lower_bound(ds.begin() + lastIdx + 1, ds.end(), target);
                    if (it == ds.end()) {
                        count = -1;
                        break;
                    }
                    lastIdx = distance(ds.begin(), it);
                    count++;
                }
                if (count == k) {
                    // Check the wrap-around Manhattan distance
                    long long wrapDist = abs((long long)pts[lastIdx].x - pts[i].x) + 
                                         abs((long long)pts[lastIdx].y - pts[i].y);
                    if (wrapDist >= D) return true;
                }
            }
            return false;
        };

        int low = 1, high = side, ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (can(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

private:
    long long getPerimeterDist(long long x, long long y, long long side) {
        if (y == 0) return x;                   // Bottom edge
        if (x == side) return side + y;         // Right edge
        if (y == side) return 3 * side - x;     // Top edge
        return 4 * side - y;                    // Left edge
    }
};