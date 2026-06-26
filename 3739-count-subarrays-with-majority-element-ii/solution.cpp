#include <vector>
#include <algorithm>

using namespace std;

class FenwickTree {
    int n;
    vector<int> tree;

public:
    FenwickTree(int n) : n(n), tree(n + 1, 0) {}

    void add(int i, int delta) {
        for (; i <= n; i += i & -i) tree[i] += delta;
    }

    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
};

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        // Prefixes range from -n to n. Offset by n+1 to make them 1-indexed.
        vector<int> p(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            p[i + 1] = p[i] + (nums[i] == target ? 1 : -1);
        }

        int offset = n + 1;
        int max_val = 2 * n + 1;
        FenwickTree ft(max_val);
        long long count = 0;

        for (int val : p) {
            // Count how many previous prefix sums are strictly less than current
            count += ft.query(val + offset - 1);
            ft.add(val + offset, 1);
        }

        return count;
    }
};