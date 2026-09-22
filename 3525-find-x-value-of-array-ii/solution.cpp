#include <vector>

using namespace std;

class Solution {
private:
    struct Node {
        int prod;
        int cnt[5];
        Node() {
            prod = 1;
            for (int i = 0; i < 5; ++i) cnt[i] = 0;
        }
    };

    int k_val;
    vector<Node> tree;

    Node mergeNodes(const Node& left, const Node& right) {
        Node res;
        res.prod = (left.prod * right.prod) % k_val;
        for (int i = 0; i < k_val; ++i) {
            res.cnt[i] = left.cnt[i];
        }
        for (int j = 0; j < k_val; ++j) {
            if (right.cnt[j] > 0) {
                int rem = (left.prod * j) % k_val;
                res.cnt[rem] += right.cnt[j];
            }
        }
        return res;
    }

    void build(int nodeIdx, int l, int r, const vector<int>& nums) {
        if (l == r) {
            int v = nums[l] % k_val;
            tree[nodeIdx].prod = v;
            tree[nodeIdx].cnt[v] = 1;
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * nodeIdx, l, mid, nums);
        build(2 * nodeIdx + 1, mid + 1, r, nums);
        tree[nodeIdx] = mergeNodes(tree[2 * nodeIdx], tree[2 * nodeIdx + 1]);
    }

    void update(int nodeIdx, int l, int r, int idx, int val) {
        if (l == r) {
            int v = val % k_val;
            tree[nodeIdx].prod = v;
            for (int i = 0; i < k_val; ++i) tree[nodeIdx].cnt[i] = 0;
            tree[nodeIdx].cnt[v] = 1;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            update(2 * nodeIdx, l, mid, idx, val);
        } else {
            update(2 * nodeIdx + 1, mid + 1, r, idx, val);
        }
        tree[nodeIdx] = mergeNodes(tree[2 * nodeIdx], tree[2 * nodeIdx + 1]);
    }

    void query(int nodeIdx, int l, int r, int ql, int qr, int& running_prod, int target_x, int& ans) {
        if (ql <= l && r <= qr) {
            for (int j = 0; j < k_val; ++j) {
                if (tree[nodeIdx].cnt[j] > 0) {
                    if ((running_prod * j) % k_val == target_x) {
                        ans += tree[nodeIdx].cnt[j];
                    }
                }
            }
            running_prod = (running_prod * tree[nodeIdx].prod) % k_val;
            return;
        }
        int mid = l + (r - l) / 2;
        if (ql <= mid) {
            query(2 * nodeIdx, l, mid, ql, qr, running_prod, target_x, ans);
        }
        if (qr > mid) {
            query(2 * nodeIdx + 1, mid + 1, r, ql, qr, running_prod, target_x, ans);
        }
    }

public:
    vector<int> countKConstraintSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {
        // Renamed wrapper function signature if necessary, matching problem inputs
        k_val = k;
        int n = nums.size();
        tree.resize(4 * n);

        build(1, 0, n - 1, nums);

        vector<int> result;
        result.reserve(queries.size());

        for (const auto& q : queries) {
            int idx = q[0];
            int val = q[1];
            int start = q[2];
            int target_x = q[3];

            // 1. Persistent update
            update(1, 0, n - 1, idx, val);

            // 2. Query range [start, n - 1]
            int running_prod = 1 % k_val;
            int ans = 0;
            query(1, 0, n - 1, start, n - 1, running_prod, target_x, ans);

            result.push_back(ans);
        }

        return result;
    }
};