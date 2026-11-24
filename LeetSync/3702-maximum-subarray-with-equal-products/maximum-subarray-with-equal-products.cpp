class Solution {
public:
    int maxLength(vector<int>& nums) {
        const int primes[4] = {2, 3, 5, 7};
        int n = nums.size();

        vector<array<int,4>> exp(n);
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            for (int k = 0; k < 4; ++k) {
                int cnt = 0;
                while (x % primes[k] == 0) {
                    x /= primes[k];
                    ++cnt;
                }
                exp[i][k] = cnt;
            }
        }

        int best = 0;
        for (int l = 0; l < n; ++l) {
            array<int,4> sum{0,0,0,0};
            array<int,4> mx{0,0,0,0};
            array<int,4> mn{INT_MAX,INT_MAX,INT_MAX,INT_MAX};

            for (int r = l; r < n; ++r) {
                for (int k = 0; k < 4; ++k) {
                    int e = exp[r][k];
                    sum[k] += e;
                    mx[k] = max(mx[k], e);
                    mn[k] = min(mn[k], e);
                }

                bool ok = true;
                for (int k = 0; k < 4; ++k) {
                    if (sum[k] != mx[k] + mn[k]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) best = max(best, r - l + 1);
            }
        }
        return best;
    }
};