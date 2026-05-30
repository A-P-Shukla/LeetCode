#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> tree;

public:
    SegmentTree(int n) {
        this->n = n;
        tree.assign(4 * n, 0);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = start + (end - start) / 2;
        return max(query(2 * node, start, mid, l, r),
                   query(2 * node + 1, mid + 1, end, l, r));
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int max_x = 0;
        for (const auto& q : queries) {
            max_x = max(max_x, q[1]);
        }

        SegmentTree st(max_x + 1);
        set<int> obstacles;
        obstacles.insert(0);
        vector<bool> results;

        for (const auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];
                auto it = obstacles.lower_bound(x);
                int prev_val = *prev(it);
                
                // Set the size of the new interval starting at prev_val ending at x
                st.update(1, 0, max_x, x, x - prev_val);
                
                // If there is an obstacle to the right of x, its interval shrinks
                if (it != obstacles.end()) {
                    int next_val = *it;
                    st.update(1, 0, max_x, next_val, next_val - x);
                }
                
                obstacles.insert(x);
            } else {
                int x = q[1];
                int sz = q[2];
                
                // Find the largest obstacle <= x
                auto it = obstacles.upper_bound(x);
                int prev_val = *prev(it);
                
                // Find the maximum gap inside [0, prev_val]
                int max_gap = st.query(1, 0, max_x, 0, prev_val);
                
                // The remaining gap is the space from prev_val to x
                int rem = x - prev_val;
                
                results.push_back(max(max_gap, rem) >= sz);
            }
        }

        return results;
    }
};