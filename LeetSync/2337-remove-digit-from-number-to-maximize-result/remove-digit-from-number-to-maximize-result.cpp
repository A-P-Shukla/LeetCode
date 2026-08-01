class Solution {
public:
    string removeDigit(string number, char digit) {
        string s = "";
        int n = number.length();

        for(int i = 0; i < n; i++){
            string temp = "";
            if(number[i] == digit){
                temp = number.substr(0, i) + number.substr(i + 1);
            }

            if(temp > s)
                s = temp;
        }

        return s;
    }
};