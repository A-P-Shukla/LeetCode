#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    std::vector<int> answerQueries(int n, std::vector<int>& nums, int maxDiff, std::vector<std::vector<int>>& queries) {
        struct Node { int val, id; };
        std::vector<Node> sortedNodes(n);
        for (int i = 0; i < n; ++i) sortedNodes[i] = {nums[i], i};
        
        std::sort(sortedNodes.begin(), sortedNodes.end(), [](const Node& a, const Node& b) {
            return a.val < b.val;
        });

        std::vector<int> compId(n);
        int currentComp = 0;
        compId[sortedNodes[0].id] = currentComp;

        for (int i = 1; i < n; ++i) {
            if (sortedNodes[i].val - sortedNodes[i - 1].val > maxDiff) {
                currentComp++;
            }
            compId[sortedNodes[i].id] = currentComp;
        }

        std::vector<int> results;
        results.reserve(queries.size());
        for (const auto& q : queries) {
            int u = q[0], v = q[1];
            if (u == v) {
                results.push_back(0);
            } else if (compId[u] != compId[v]) {
                results.push_back(-1);
            } else {
                results.push_back(std::abs(nums[u] - nums[v]) <= maxDiff ? 1 : 2);
            }
        }
        return results;
    }
};