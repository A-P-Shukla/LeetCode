//Random line worked
class Solution {
public:
    int numberOfMatches(int n) {
        return n-1;
    }
};
//Coded Seriously
class Solution {
public:
    int numberOfMatches(int n) {
        int match = 0;
        while(n>1){
            if(n % 2 == 0){
                match += n / 2;
                n = n/2;
            }
            else{
                match += (n - 1)/2;
                n = (n-1)/2;
                n += 1;
            }
        }
        return match;
    }
};
//Same Code But also Handles Edge Case:
class Solution {
public:
    int numberOfMatches(int n) {
        int match = 0;
        if(n == 1) return 0;//Edge case
        while(n != 1){
            if(n % 2 == 0){
                match += n / 2;
                n = n/2;
            }
            else{
                match += (n - 1)/2;
                n = (n-1)/2;
                n += 1;
            }
        }
        return match;
    }
};
