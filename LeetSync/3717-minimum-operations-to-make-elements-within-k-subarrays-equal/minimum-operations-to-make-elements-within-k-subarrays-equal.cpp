#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    using ll = long long;
    const ll INF = (1LL << 60);

    class SlidingWindow {
        int x, targetLow;
        int lowSize = 0, highSize = 0;
        priority_queue<ll> low; 
        priority_queue<ll, vector<ll>, greater<ll>> high;
        unordered_map<ll, int> delayedLow, delayedHigh;
        ll sumLow = 0, sumHigh = 0;

        void pruneLow() {
            while (!low.empty()) {
                ll v = low.top();
                auto it = delayedLow.find(v);
                if (it != delayedLow.end() && it->second > 0) {
                    if (--it->second == 0) delayedLow.erase(it);
                    low.pop();
                } else {
                    break;
                }
            }
        }

        void pruneHigh() {
            while (!high.empty()) {
                ll v = high.top();
                auto it = delayedHigh.find(v);
                if (it != delayedHigh.end() && it->second > 0) {
                    if (--it->second == 0) delayedHigh.erase(it);
                    high.pop();
                } else {
                    break;
                }
            }
        }

        void rebalance() {
            pruneLow();
            pruneHigh();

            while (lowSize > targetLow && !low.empty()) {
                ll v = low.top(); low.pop();
                sumLow -= v;
                high.push(v);
                sumHigh += v;
                lowSize--;
                highSize++;
                pruneLow();
            }

            while (lowSize < targetLow && !high.empty()) {
                ll v = high.top(); high.pop();
                sumHigh -= v;
                low.push(v);
                sumLow += v;
                highSize--;
                lowSize++;
                pruneHigh();
            }

            pruneLow();
            pruneHigh();
        }

    public:
        explicit SlidingWindow(int _x) : x(_x), targetLow((_x + 1) / 2) {}

        void add(ll v) {
            pruneLow();
            if (low.empty() || v <= low.top()) {
                low.push(v);
                sumLow += v;
                lowSize++;
            } else {
                high.push(v);
                sumHigh += v;
                highSize++;
            }
            rebalance();
        }

        void remove(ll v) {
            pruneLow();
            if (!low.empty() && v <= low.top()) {
                delayedLow[v]++;
                sumLow -= v;
                lowSize--;
            } else {
                delayedHigh[v]++;
                sumHigh -= v;
                highSize--;
            }
            rebalance();
        }

        ll median() {
            pruneLow();
            return low.top();
        }

        ll cost() {
            ll med = median();
            return (med * lowSize - sumLow) + (sumHigh - med * highSize);
        }
    };

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        int windows = n - x + 1;
        vector<ll> windowCost(windows);

        SlidingWindow sw(x);
        for (int i = 0; i < x; ++i) {
            sw.add(nums[i]);
        }
        windowCost[0] = sw.cost();

        for (int s = 1; s < windows; ++s) {
            sw.remove(nums[s - 1]);
            sw.add(nums[s + x - 1]);
            windowCost[s] = sw.cost();
        }

        vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, INF));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);

                if (i >= x && j >= 1 && dp[i - x][j - 1] != INF) {
                    ll cand = dp[i - x][j - 1] + windowCost[i - x];
                    dp[i][j] = min(dp[i][j], cand);
                }
            }
        }

        return dp[n][k];
    }
};