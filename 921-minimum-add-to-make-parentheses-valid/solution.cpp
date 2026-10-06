class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0;   // unmatched '(' count
        int additions = 0; // number of insertions needed

        for (char c : s) {
            if (c == '(') {
                ++balance;                 // an opening bracket needs a future ')'
            } else { // c == ')'
                if (balance > 0) {
                    --balance;             // match with a previous '('
                } else {
                    ++additions;           // need an extra '(' before this ')'
                }
            }
        }
        // any remaining '(' need a ')' each
        return additions + balance;
    }
};