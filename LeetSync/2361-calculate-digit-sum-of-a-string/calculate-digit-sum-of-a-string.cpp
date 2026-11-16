class Solution {
public:
    string digitSum(string s, int k) {
        while (static_cast<int>(s.size()) > k) {
            string next;
            for (int i = 0; i < static_cast<int>(s.size()); i += k) {
                int sum = 0;
                int limit = min(i + k, static_cast<int>(s.size()));
                for (int j = i; j < limit; ++j) {
                    sum += s[j] - '0';          
                }
                next += to_string(sum);          
            }
            s.swap(next);                       
        }
        return s;
    }
};