#include <bits/stdc++.h>
using namespace std;

// KMP prefix table for pattern pat
static vector<int> buildLPS(const vector<int>& pat) {
    int m = pat.size();
    vector<int> lps(m, 0);
    for (int i = 1, len = 0; i < m; ) {
        if (pat[i] == pat[len]) {
            lps[i++] = ++len;
        } else if (len) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}

// Return true iff target is a cyclic rotation of source
static bool isCyclicEqual(const vector<int>& source, const vector<int>& target) {
    int k = source.size();
    if (k == 0) return true;
    const vector<int> lps = buildLPS(target);
    int i = 0, j = 0;                     // i -> index in virtual text source+source
    while (i < 2 * k) {
        int txt = source[i % k];
        if (txt == target[j]) {
            ++i; ++j;
            if (j == k) {
                int startIdx = i - j;   // match starts at startIdx
                if (startIdx < k) return true;
                j = lps[j - 1];          // continue searching
            }
        } else {
            if (j) j = lps[j - 1];
            else ++i;
        }
    }
    return false;
}

// Check whether divisor k is sortable
static bool checkK(const vector<int>& nums, const vector<int>& sorted, int k) {
    int n = nums.size();
    for (int start = 0; start < n; start += k) {
        vector<int> src(nums.begin() + start, nums.begin() + start + k);
        vector<int> tgt(sorted.begin() + start, sorted.begin() + start + k);
        if (!isCyclicEqual(src, tgt)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    vector<int> nums(n);
    for (int &x : nums) cin >> x;
    
    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());
    
    // collect all divisors of n
    vector<int> divisors;
    for (int i = 1; i * 1LL * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) divisors.push_back(n / i);
        }
    }
    
    long long ans = 0;
    for (int k : divisors) {
        if (checkK(nums, sorted, k))
            ans += k;
    }
    
    cout << ans << '\n';
    return 0;
}