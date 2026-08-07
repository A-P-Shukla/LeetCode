class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;

        int og = x;
        long long rn = 0;

        while(og > 0){
            int rem = og % 10;

            rn = rn*10 + rem;

            og /= 10;
        }

        return rn == x;
    }
};