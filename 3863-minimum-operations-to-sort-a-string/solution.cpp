#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(string s) {
        int n = s.size();
        string t = s;
        sort(t.begin(), t.end());
        if (s == t) return 0;                     // already sorted
        if (n == 2) return -1;                    // only single‑char substrings possible

        int L = 0, R = n - 1;
        while (L < n && s[L] == t[L]) ++L;        // first mismatch
        while (R >= 0 && s[R] == t[R]) --R;       // last mismatch

        // If the mismatching interval is not the whole string, one operation suffices
        if (L > 0 || R < n - 1) return 1;
        // Otherwise we need exactly two operations (proved by constructive argument)
        return 2;
    }
};