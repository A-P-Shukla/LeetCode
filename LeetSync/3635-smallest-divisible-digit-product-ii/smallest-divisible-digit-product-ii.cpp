#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    struct Factors {
        int f2 = 0, f3 = 0, f5 = 0, f7 = 0;
    };

    Factors getFactors(int d) {
        Factors f;
        if (d == 2) f.f2 = 1;
        else if (d == 3) f.f3 = 1;
        else if (d == 4) f.f2 = 2;
        else if (d == 5) f.f5 = 1;
        else if (d == 6) { f.f2 = 1; f.f3 = 1; }
        else if (d == 7) f.f7 = 1;
        else if (d == 8) f.f2 = 3;
        else if (d == 9) f.f3 = 2;
        return f;
    }

    bool isBetter(const string& a, const string& b) {
        if (a.length() != b.length()) return a.length() < b.length();
        return a < b;
    }

public:
    string smallestNumber(string num, long long t) {
        long long temp_t = t;
        int req2 = 0, req3 = 0, req5 = 0, req7 = 0;
        while (temp_t % 2 == 0) { req2++; temp_t /= 2; }
        while (temp_t % 3 == 0) { req3++; temp_t /= 3; }
        while (temp_t % 5 == 0) { req5++; temp_t /= 5; }
        while (temp_t % 7 == 0) { req7++; temp_t /= 7; }

        if (temp_t > 1) return "-1";

        const string INF(100, '9');
        vector<vector<string>> dp(48, vector<string>(31, INF));
        dp[0][0] = "";

        int available_digits[6] = {2, 3, 4, 6, 8, 9};

        for (int u = 0; u < 48; ++u) {
            for (int v = 0; v < 31; ++v) {
                if (u == 0 && v == 0) continue;
                string best = INF;
                for (int d : available_digits) {
                    Factors f = getFactors(d);
                    int pu = max(0, u - f.f2);
                    int pv = max(0, v - f.f3);
                    string cand = dp[pu][pv] + char('0' + d);
                    sort(cand.begin(), cand.end());
                    if (isBetter(cand, best)) {
                        best = cand;
                    }
                }
                dp[u][v] = best;
            }
        }

        auto getOptimalMultiset = [&](int r2, int r3, int r5, int r7) {
            string m = dp[max(0, r2)][max(0, r3)];
            if (r5 > 0) m.append(r5, '5');
            if (r7 > 0) m.append(r7, '7');
            sort(m.begin(), m.end());
            return m;
        };

        int n = num.length();
        int fz = -1;
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') {
                fz = i;
                break;
            }
        }

        vector<Factors> pref(n + 1);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i];
            if (num[i] >= '1' && num[i] <= '9') {
                Factors f = getFactors(num[i] - '0');
                pref[i + 1].f2 += f.f2;
                pref[i + 1].f3 += f.f3;
                pref[i + 1].f5 += f.f5;
                pref[i + 1].f7 += f.f7;
            }
        }

        if (fz == -1) {
            if (pref[n].f2 >= req2 && pref[n].f3 >= req3 && 
                pref[n].f5 >= req5 && pref[n].f7 >= req7) {
                return num;
            }
        }

        int max_i = (fz != -1) ? fz : n - 1;

        for (int i = max_i; i >= 0; --i) {
            int start_d = (num[i] - '0') + 1;
            for (int d_pos = start_d; d_pos <= 9; ++d_pos) {
                Factors f_d = getFactors(d_pos);
                int p2 = pref[i].f2 + f_d.f2;
                int p3 = pref[i].f3 + f_d.f3;
                int p5 = pref[i].f5 + f_d.f5;
                int p7 = pref[i].f7 + f_d.f7;

                string M = getOptimalMultiset(req2 - p2, req3 - p3, req5 - p5, req7 - p7);
                int rem_len = n - 1 - i;

                if ((int)M.length() <= rem_len) {
                    string res = num.substr(0, i);
                    res += char('0' + d_pos);
                    res.append(rem_len - M.length(), '1');
                    res += M;
                    return res;
                }
            }
        }

        string M = getOptimalMultiset(req2, req3, req5, req7);
        int target_len = max(n + 1, (int)M.length());
        string res = "";
        res.append(target_len - M.length(), '1');
        res += M;
        return res;
    }
};