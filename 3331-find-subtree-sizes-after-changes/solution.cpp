#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubtreeSizesAfterChanges(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; ++i) {
            children[parent[i]].push_back(i);
        }

        // Step 1: determine new parents using DFS with character stacks
        vector<int> newParent = parent;               // default = old parent
        vector<vector<int>> charStack(26);            // stacks for each letter

        // iterative DFS: pair<node, state> where state 0 = pre, 1 = post
        vector<pair<int,int>> stk;
        stk.reserve(2*n);
        stk.emplace_back(0, 0);                       // start at root

        while (!stk.empty()) {
            auto [u, state] = stk.back();
            stk.pop_back();

            if (state == 0) {                         // pre‑visit
                int c = s[u] - 'a';
                if (u != 0 && !charStack[c].empty()) {
                    newParent[u] = charStack[c].back();   // closest same‑char ancestor
                }
                charStack[c].push_back(u);

                // push post‑visit marker
                stk.emplace_back(u, 1);
                // push children for pre‑visit
                for (int v : children[u]) {
                    stk.emplace_back(v, 0);
                }
            } else {                                   // post‑visit
                int c = s[u] - 'a';
                charStack[c].pop_back();               // backtrack
            }
        }

        // Step 2: build final adjacency list
        vector<vector<int>> finalChildren(n);
        for (int i = 1; i < n; ++i) {
            finalChildren[newParent[i]].push_back(i);
        }

        // Step 3: compute subtree sizes with another iterative post‑order DFS
        vector<int> size(n, 1);
        vector<pair<int,int>> dfs2;
        dfs2.reserve(2*n);
        dfs2.emplace_back(0, 0);
        while (!dfs2.empty()) {
            auto [u, state] = dfs2.back();
            dfs2.pop_back();
            if (state == 0) {
                dfs2.emplace_back(u, 1);
                for (int v : finalChildren[u]) dfs2.emplace_back(v, 0);
            } else {
                for (int v : finalChildren[u]) size[u] += size[v];
            }
        }
        return size;
    }
};