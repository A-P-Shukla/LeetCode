#include <vector>
#include <string>
#include <cstring>

using namespace std;

// Flat, pool-allocated Trie Node structure for high performance
struct Node {
    int children[26];
    int best_index;
};

class Solution {
private:
    vector<Node> trie;

    int create_node() {
        Node n;
        memset(n.children, -1, sizeof(n.children));
        n.best_index = -1;
        trie.push_back(n);
        return trie.size() - 1;
    }

    void insert(const string& s, int idx, const vector<string>& wordsContainer) {
        int curr = 0; // Root is always at index 0
        
        // Helper lambda to update the best index at a node
        auto update_best = [&](int node_idx) {
            int& best = trie[node_idx].best_index;
            if (best == -1 || wordsContainer[idx].length() < wordsContainer[best].length()) {
                best = idx;
            }
        };

        update_best(curr);
        
        // Traverse the string in reverse order to build the suffix trie
        for (int i = s.length() - 1; i >= 0; --i) {
            int c = s[i] - 'a';
            if (trie[curr].children[c] == -1) {
                trie[curr].children[c] = create_node();
            }
            curr = trie[curr].children[c];
            update_best(curr);
        }
    }

    int query(const string& s) {
        int curr = 0;
        int best = trie[curr].best_index;
        
        // Match characters in reverse order
        for (int i = s.length() - 1; i >= 0; --i) {
            int c = s[i] - 'a';
            if (trie[curr].children[c] == -1) {
                break;
            }
            curr = trie[curr].children[c];
            best = trie[curr].best_index;
        }
        return best;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        trie.clear();
        create_node(); // Create root node
        
        for (int i = 0; i < wordsContainer.size(); ++i) {
            insert(wordsContainer[i], i, wordsContainer);
        }
        
        vector<int> ans;
        ans.reserve(wordsQuery.size());
        for (const string& q : wordsQuery) {
            ans.push_back(query(q));
        }
        
        return ans;
    }
};