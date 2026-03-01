class Solution {
public:
    /**
     * The minimum number of deci-binary numbers needed to sum up to n 
     * is equal to the maximum digit present in n.
     */
    int minPartitions(string n) {
        char maxDigit = '0';
        
        for (char c : n) {
            // Update the maximum digit found so far
            if (c > maxDigit) {
                maxDigit = c;
            }
            
            // Optimization: If we find '9', we can't go higher, so return immediately
            if (maxDigit == '9') return 9;
        }
        
        // Convert char to int
        return maxDigit - '0';
    }
};