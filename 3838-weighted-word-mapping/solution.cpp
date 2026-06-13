#include <vector>
#include <string>

class Solution {
public:
    std::string weightedWordMapping(std::vector<std::string>& words, std::vector<int>& weights) {
        std::string result = "";
        
        for (const std::string& word : words) {
            int totalWeight = 0;
            // Calculate total weight of the word
            for (char c : word) {
                totalWeight += weights[c - 'a'];
            }
            
            // Map the weight modulo 26 to a char in reverse alphabetical order
            // 0 -> 'z', 1 -> 'y', ..., 25 -> 'a'
            int remainder = totalWeight % 26;
            char mappedChar = 'z' - remainder;
            
            result += mappedChar;
        }
        
        return result;
    }
};