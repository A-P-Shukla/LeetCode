class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        // ends_with[i] stores the number of distinct subsequences ending with ('a' + i)
        long long ends_with[26] = {0};
        
        for (char c : s) {
            int idx = c - 'a';
            // Start with 1 to account for the subsequence consisting solely of character c
            long long new_subsequences_ending_in_c = 1;
            
            // Append c to all existing distinct subsequences
            for (int i = 0; i < 26; ++i) {
                new_subsequences_ending_in_c = (new_subsequences_ending_in_c + ends_with[i]) % MOD;
            }
            
            // Update the count for character c
            ends_with[idx] = new_subsequences_ending_in_c;
        }
        
        // Sum up all distinct subsequences
        long long total = 0;
        for (int i = 0; i < 26; ++i) {
            total = (total + ends_with[i]) % MOD;
        }
        
        return total;
    }
};