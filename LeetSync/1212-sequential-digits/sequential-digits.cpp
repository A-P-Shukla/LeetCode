class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        string digits = "123456789";
        
        for (int length = 2; length <= 9; ++length) {
            for (int i = 0; i <= 9 - length; ++i) {
                string sub = digits.substr(i, length);
                int num = stoi(sub);
                
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }
        
        sort(result.begin(), result.end());
        return result;
    }
};