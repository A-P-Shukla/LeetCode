class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        long long ends_with[26] = {0};
        
        for (char c : s) {
            int idx = c - 'a';
            long long new_subsequences_ending_in_c = 1;
            
            for (int i = 0; i < 26; ++i) {
                new_subsequences_ending_in_c = (new_subsequences_ending_in_c + ends_with[i]) % MOD;
            }
            
            ends_with[idx] = new_subsequences_ending_in_c;
        }
        
        long long total = 0;
        for (int i = 0; i < 26; ++i) {
            total = (total + ends_with[i]) % MOD;
        }
        
        return total;
    }
};