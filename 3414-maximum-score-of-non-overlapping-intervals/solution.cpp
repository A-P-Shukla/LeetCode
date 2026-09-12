#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    long long l, r, weight;
    int orig_idx;
};

struct State {
    long long score = 0;
    vector<int> indices;
};

class Solution {
private:
    // Helper function to decide if state 'a' is strictly better than state 'b'
    bool isBetter(const State& a, const State& b) {
        if (a.score != b.score) {
            return a.score > b.score; // Larger score is preferred
        }
        return a.indices < b.indices; // Lexicographically smaller indices are preferred
    }

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        // Sort intervals by start time; tie-break by end time, then original index
        sort(arr.begin(), arr.end(), [](const Interval& a, const Interval& b) {
            if (a.l != b.l) return a.l < b.l;
            if (a.r != b.r) return a.r < b.r;
            return a.orig_idx < b.orig_idx;
        });

        // dp_prev[i] stores the optimal State for suffix i using at most (k-1) intervals
        vector<State> dp_prev(n + 1);

        // Max up to 4 intervals
        for (int k = 1; k <= 4; ++k) {
            vector<State> dp_curr(n + 1);
            for (int i = n - 1; i >= 0; --i) {
                // Option 1: Skip interval i
                State best = dp_curr[i + 1];

                // Option 2: Take interval i
                // Binary search for the first interval starting strictly after interval i ends
                int low = i + 1, high = n - 1, next_idx = n;
                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    if (arr[mid].l > arr[i].r) {
                        next_idx = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }

                State take;
                take.score = arr[i].weight + dp_prev[next_idx].score;
                take.indices = dp_prev[next_idx].indices;

                // Insert interval i's original index into take.indices maintaining sorted order
                auto pos = lower_bound(take.indices.begin(), take.indices.end(), arr[i].orig_idx);
                take.indices.insert(pos, arr[i].orig_idx);

                if (isBetter(take, best)) {
                    best = take;
                }

                dp_curr[i] = best;
            }
            dp_prev = std::move(dp_curr);
        }

        return dp_prev[0].indices;
    }
};