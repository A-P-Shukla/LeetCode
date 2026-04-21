#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;

class UnionFind {
public:
    vector<int> parent;
    UnionFind(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        UnionFind uf(n);
        
        // Build connected components of indices
        for (const auto& swap : allowedSwaps) {
            uf.unite(swap[0], swap[1]);
        }
        
        // Group source elements by their component root
        unordered_map<int, unordered_map<int, int>> components;
        for (int i = 0; i < n; ++i) {
            int root = uf.find(i);
            components[root][source[i]]++;
        }
        
        int matches = 0;
        // For each index, check if target[i] exists in its component's multiset
        for (int i = 0; i < n; ++i) {
            int root = uf.find(i);
            int targetVal = target[i];
            
            if (components[root].count(targetVal) && components[root][targetVal] > 0) {
                matches++;
                components[root][targetVal]--;
            }
        }
        
        return n - matches;
    }
};