#include <vector>
#include <string>

class Solution {
public:
    int numOfStrings(std::vector<std::string>& patterns, std::string word) {
        int count = 0;
        
        // Iterate through each pattern in the patterns vector
        for (const std::string& pattern : patterns) {
            // Check if the current pattern exists as a substring in the word.
            // string::npos is returned if the substring is not found.
            if (word.find(pattern) != std::string::npos) {
                count++;
            }
        }
        
        return count;
    }
};