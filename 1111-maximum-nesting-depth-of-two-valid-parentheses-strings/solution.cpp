#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        ans.reserve(seq.size());
        int depth = 0;                         // current nesting depth
        for (char ch : seq) {
            if (ch == '(') {
                ++depth;                       // go deeper first
                ans.push_back(depth & 1);      // parity decides group (0 or 1)
            } else { // ch == ')'
                ans.push_back(depth & 1);      // use same parity as its matching '('
                --depth;                       // then retreat
            }
        }
        return ans;
    }
};