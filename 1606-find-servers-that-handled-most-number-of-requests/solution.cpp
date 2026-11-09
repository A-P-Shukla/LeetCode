#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        vector<int> cnt(k, 0);

        // busy: min‑heap of (free_time, server_id)
        using P = pair<long long,int>;
        priority_queue<P, vector<P>, greater<P>> busy;

        // free: ordered set of idle server ids
        set<int> free;
        for (int i = 0; i < k; ++i) free.insert(i);

        for (int i = 0; i < n; ++i) {
            long long curTime = arrival[i];

            // release servers that have finished by curTime
            while (!busy.empty() && busy.top().first <= curTime) {
                int id = busy.top().second;
                busy.pop();
                free.insert(id);
            }

            if (free.empty()) continue; // request dropped

            int pref = i % k;
            auto it = free.lower_bound(pref);
            if (it == free.end()) it = free.begin(); // wrap around

            int server = *it;
            ++cnt[server];
            free.erase(it);
            busy.emplace(curTime + load[i], server);
        }

        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> ans;
        for (int i = 0; i < k; ++i)
            if (cnt[i] == mx) ans.push_back(i);
        return ans;
    }
};