#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> separateDigits(std::vector<int>& nums) {
        std::vector<int> result;
        
        // Iterate through each number in the input array
        for (int num : nums) {
            // Temporary storage for digits of the current number
            // because mathematical extraction gives digits in reverse order
            std::vector<int> currentDigits;
            
            while (num > 0) {
                currentDigits.push_back(num % 10);
                num /= 10;
            }
            
            // Add digits to result in the correct order (left-to-right)
            for (int i = currentDigits.size() - 1; i >= 0; --i) {
                result.push_back(currentDigits[i]);
            }
        }
        
        return result;
    }
};