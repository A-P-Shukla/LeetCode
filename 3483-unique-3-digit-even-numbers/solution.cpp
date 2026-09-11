#include <vector>

class Solution {
public:
    int countEvenNumbers(std::vector<int>& digits) {
        // Step 1: Count frequency of available digits
        std::vector<int> freq(10, 0);
        for (int digit : digits) {
            freq[digit]++;
        }
        
        int distinctCount = 0;
        
        // Step 2: Check every 3-digit even number from 100 to 998
        for (int num = 100; num <= 998; num += 2) {
            int hundred = num / 100;
            int ten = (num / 10) % 10;
            int unit = num % 10;
            
            std::vector<int> currentFreq(10, 0);
            currentFreq[hundred]++;
            currentFreq[ten]++;
            currentFreq[unit]++;
            
            // Step 3: Verify if current number can be formed
            bool isValid = true;
            for (int d = 0; d < 10; ++d) {
                if (currentFreq[d] > freq[d]) {
                    isValid = false;
                    break;
                }
            }
            
            if (isValid) {
                distinctCount++;
            }
        }
        
        return distinctCount;
    }
};