#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (1LL<<60);

/* Sliding‑window structure that maintains:
 *   - low : max‑heap (store negatives) containing ceil(x/2) smallest elements
 *   - high: min‑heap containing the rest
 *   - sumLow, sumHigh : sums of elements in each heap
 * Provides O(log x) insert, erase, and retrieval of median & cost.
 */
class SlidingWindow {
    int x, targetLow;               // target size of low heap = ceil(x/2)
    priority_queue<ll> low;         // max‑heap via default
    priority_queue<ll, vector<ll>, greater<ll>> high;
    unordered_map<ll,int> delayedLow, delayedHigh; // lazy deletions
    ll sumLow = 0, sumHigh = 0;

    // Clean top elements that are scheduled for deletion
    void pruneLow() {
        while (!low.empty()) {
            ll v = low.top();
            auto it = delayedLow.find(v);
            if (it != delayedLow.end() && it->second > 0) {
                if (--it->second == 0) delayedLow.erase(it);
                low.pop();
            } else break;
        }
    }
    void pruneHigh() {
        while (!high.empty()) {
            ll v = high.top();
            auto it = delayedHigh.find(v);
            if (it != delayedHigh.end() && it->second > 0) {
                if (--it->second == 0) delayedHigh.erase(it);
                high.pop();
            } else break;
        }
    }

    // Rebalance so that |low| = targetLow
    void rebalance() {
        // Ensure low size not exceed target
        while ((int)low.size() > targetLow) {
            pruneLow();
            ll v = low.top(); low.pop();
            sumLow -= v;
            high.push(v);
            sumHigh += v;
        }
        while ((int)low.size() < targetLow) {
            pruneHigh();
            ll v = high.top(); high.pop();
            sumHigh -= v;
            low.push(v);
            sumLow += v;
        }
        pruneLow(); pruneHigh();
    }

public:
    explicit SlidingWindow(int _x) : x(_x), targetLow((_x+1)/2) {}

    void add(ll v) {
        if (low.empty() || v <= low.top()) {
            low.push(v);
            sumLow += v;
        } else {
            high.push(v);
            sumHigh += v;
        }
        rebalance();
    }

    void remove(ll v) {
        // Lazy deletion from appropriate heap
        if (!low.empty() && v <= low.top()) {
            delayedLow[v]++;   // record deletion
            sumLow -= v;
        } else {
            delayedHigh[v]++;
            sumHigh -= v;
        }
        rebalance();
    }

    ll median() const {
        return low.top();   // low is max‑heap, top is median
    }

    ll cost() const {
        ll med = median();
        ll cntLow = (ll)low.size();
        ll cntHigh = (ll)high.size();
        return med*cntLow - sumLow + sumHigh - med*cntHigh;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Input format adapted for LeetCode style: read from stdin
    int n; 
    if(!(cin>>n)) return 0;
    vector<ll> nums(n);
    for(int i=0;i<n;++i) cin>>nums[i];
    int x,k; cin>>x>>k;

    int windows = n - x + 1;
    vector<ll> cost(windows);
    SlidingWindow sw(x);
    // initialise first window
    for(int i=0;i<x;++i) sw.add(nums[i]);
    cost[0] = sw.cost();
    for(int s=1; s<windows; ++s) {
        sw.remove(nums[s-1]);
        sw.add(nums[s+x-1]);
        cost[s] = sw.cost();
    }

    // DP: dp[i][j] = min cost using first i elements, j windows
    vector<vector<ll>> dp(n+1, vector<ll>(k+1, INF));
    for(int i=0;i<=n;++i) dp[i][0]=0;

    for(int i=1;i<=n;++i){
        for(int j=0;j<=k;++j){
            // skip element i-1
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
            if(i>=x && j>=1){
                ll cand = dp[i-x][j-1] + cost[i-x];
                dp[i][j] = min(dp[i][j], cand);
            }
        }
    }
    cout << dp[n][k] << "\n";
    return 0;
}