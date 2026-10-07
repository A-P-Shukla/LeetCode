#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper to check if a string has valid parentheses
    bool isValid(const string& s) {
        int balance = 0;
        for (char c : s) {
            if (c == '(') ++balance;
            else if (c == ')') {
                if (balance == 0) return false;
                --balance;
            }
        }
        return balance == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> visited;          // avoid repeats
        queue<string> q;
        vector<string> result;
        bool found = false;

        q.push(s);
        visited.insert(s);

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string cur = q.front(); q.pop();

                if (isValid(cur)) {
                    result.push_back(cur);
                    found = true;                 // we reached minimal deletions
                }

                if (found) continue;               // do not generate deeper states

                // generate next level by removing one parenthesis at each position
                for (size_t i = 0; i < cur.size(); ++i) {
                    if (cur[i] != '(' && cur[i] != ')') continue; // only remove parentheses

                    string nxt = cur.substr(0, i) + cur.substr(i + 1);
                    if (!visited.count(nxt)) {
                        visited.insert(nxt);
                        q.push(nxt);
                    }
                }
            }
            if (found) break;   // stop after processing the level that produced valid strings
        }

        // If no valid string found (should not happen), return empty string
        if (result.empty()) result.push_back("");
        return result;
    }
};