class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        const long long INF = (1LL<<60);
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
        }

        vector<vector<long long>> dist(n, vector<long long>(k+1, INF));
        using State = tuple<long long,int,int>; 
        priority_queue<State, vector<State>, greater<State>> pq;

        dist[0][1] = 0;
        pq.emplace(0LL, 0, 1);

        while (!pq.empty()) {
            auto [d, u, run] = pq.top(); pq.pop();
            if (d != dist[u][run]) continue;
            if (u == n-1) {
            }
            for (auto &[v, w] : adj[u]) {
                int newRun = (labels[v] == labels[u]) ? run + 1 : 1;
                if (newRun > k) continue;
                long long nd = d + w;
                if (nd < dist[v][newRun]) {
                    dist[v][newRun] = nd;
                    pq.emplace(nd, v, newRun);
                }
            }
        }

        long long ans = INF;
        for (int run = 1; run <= k; ++run) ans = min(ans, dist[n-1][run]);
        return (ans == INF) ? -1 : static_cast<int>(ans);
    }
};