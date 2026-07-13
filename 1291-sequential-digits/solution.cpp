#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<int> sequentialDigits(int low, int high) {
        std::vector<int> result;
        std::string digits = "123456789";
        
        // Iterate over all possible lengths of sequential numbers
        for (int length = 2; length <= 9; ++length) {
            // Iterate over all possible starting positions
            for (int i = 0; i <= 9 - length; ++i) {
                std::string sub = digits.substr(i, length);
                int num = std::stoi(sub);
                
                // If the generated number is within range, add to results
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }
        
        // Although generation order naturally produces sorted output, 
        // explicit sorting ensures correctness if generation order changes.
        std::sort(result.begin(), result.end());
        return result;
    }
};