#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumPushes(std::string word) {
        // Frequency array for 26 lowercase English letters
        std::vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        
        // Sort frequencies in descending order
        std::sort(freq.rbegin(), freq.rend());
        
        int totalPushes = 0;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] == 0) {
                break; // No more characters present in the string
            }
            // First 8 characters take 1 push, next 8 take 2 pushes, etc.
            int multiplier = (i / 8) + 1;
            totalPushes += freq[i] * multiplier;
        }
        
        return totalPushes;
    }
};