#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    int maxNumberOfBalloons(std::string text) {
        // Frequency map to store counts of characters in text
        std::vector<int> counts(26, 0);
        for (char c : text) {
            counts[c - 'a']++;
        }

        // We need: b:1, a:1, l:2, o:2, n:1
        // We calculate how many full sets of each we have
        int b = counts['b' - 'a'];
        int a = counts['a' - 'a'];
        int l = counts['l' - 'a'] / 2;
        int o = counts['o' - 'a'] / 2;
        int n = counts['n' - 'a'];

        // The result is the bottleneck (the minimum of these requirements)
        return std::min({b, a, l, o, n});
    }
};