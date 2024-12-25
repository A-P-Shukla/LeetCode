class Solution {
public:
    bool validPalindrome(string s) ;

    bool TestPalindrome(const string &s, int i, int j);
};


bool Solution :: TestPalindrome(const string &s, int i, int j){
    while(i<j){
        if(s[i] == s[j]){
            i++;
            j--;
        } else {
            return false;
        }
    }
    return true;
}

bool Solution :: validPalindrome (string s){
    int i = 0, j = s.size() - 1;

    while(i<j){
        if(s[i] == s[j]){
            i++;
            j--;
        } else {
            return TestPalindrome(s, i+1, j) || TestPalindrome(s, i, j-1);
        }
    }
    return true;
}
