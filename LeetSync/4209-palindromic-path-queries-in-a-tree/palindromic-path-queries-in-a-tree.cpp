struct HLD {
    int n, timer;
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos, sz;
    vector<int> value;               

    HLD(int n) : n(n), timer(0) {
        adj.assign(n, {});
        parent.assign(n, -1);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        sz.assign(n, 0);
        value.assign(n, 0);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int dfs(int v, int p) {
        parent[v] = p;
        sz[v] = 1;
        int maxSub = 0;
        for (int to : adj[v]) if (to != p) {
            depth[to] = depth[v] + 1;
            int sub = dfs(to, v);
            sz[v] += sub;
            if (sub > maxSub) {
                maxSub = sub;
                heavy[v] = to;
            }
        }
        return sz[v];
    }
    void decompose(int v, int h) {
        head[v] = h;
        pos[v] = timer++;
        if (heavy[v] != -1) decompose(heavy[v], h);
        for (int to : adj[v]) if (to != parent[v] && to != heavy[v]) {
            decompose(to, to);
        }
    }
    void init(int root = 0) {
        dfs(root, -1);
        decompose(root, root);
    }
};

struct SegTree {
    int n;
    vector<int> tree;    
    SegTree(int n = 0) { init(n); }
    void init(int n_) {
        n = 1;
        while (n < n_) n <<= 1;
        tree.assign(2 * n, 0);
    }
    void build(const vector<int>& base) {
        for (size_t i = 0; i < base.size(); ++i) tree[n + i] = base[i];
        for (int i = n - 1; i > 0; --i) tree[i] = tree[i << 1] ^ tree[i << 1 | 1];
    }
    void pointUpdate(int idx, int val) {   
        int i = idx + n;
        tree[i] = val;
        for (i >>= 1; i; i >>= 1) tree[i] = tree[i << 1] ^ tree[i << 1 | 1];
    }
    int rangeQuery(int l, int r) const {
        int res = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res ^= tree[l++];
            if (r & 1) res ^= tree[--r];
        }
        return res;
    }
};

class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                        string s, vector<string>& queries) {
        
        HLD hld(n);
        for (auto &e : edges) hld.addEdge(e[0], e[1]);
        hld.init(0);


        vector<int> base(n);
        for (int i = 0; i < n; ++i) {
            int mask = 1 << (s[i] - 'a');
            base[hld.pos[i]] = mask;
            hld.value[i] = mask;
        }


        SegTree seg(n);
        seg.build(base);

        vector<bool> answer;
        for (const string& cmd : queries) {

            stringstream ss(cmd);
            string type; ss >> type;
            if (type == "update") {
                int u; char c; ss >> u >> c;
                int newMask = 1 << (c - 'a');
                seg.pointUpdate(hld.pos[u], newMask);
                hld.value[u] = newMask;
            } else { 
                int u, v; ss >> u >> v;
                int xorMask = 0;
                while (hld.head[u] != hld.head[v]) {
                    if (hld.depth[hld.head[u]] < hld.depth[hld.head[v]]) swap(u, v);
                    int headU = hld.head[u];
                    xorMask ^= seg.rangeQuery(hld.pos[headU], hld.pos[u]);
                    u = hld.parent[headU];
                }

                int l = min(hld.pos[u], hld.pos[v]);
                int r = max(hld.pos[u], hld.pos[v]);
                xorMask ^= seg.rangeQuery(l, r);

                answer.push_back((xorMask & (xorMask - 1)) == 0);
            }
        }
        return answer;
    }
};