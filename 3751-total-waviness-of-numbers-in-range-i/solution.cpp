#include <string>

class Solution {
private:
    // Helper function to calculate waviness of a single number
    int getWaviness(int n) {
        std::string s = std::to_string(n);
        int len = s.length();
        if (len < 3) {
            return 0;
        }
        
        int waviness = 0;
        for (int i = 1; i < len - 1; ++i) {
            if ((s[i] > s[i - 1] && s[i] > s[i + 1]) || 
                (s[i] < s[i - 1] && s[i] < s[i + 1])) {
                waviness++;
            }
        }
        return waviness;
    }

public:
    int sumWaviness(int num1, int num2) {
        int totalWaviness = 0;
        for (int i = num1; i <= num2; ++i) {
            totalWaviness += getWaviness(i);
        }
        return totalWaviness;
    }
};