//Just built in function of string TC O(n):
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int s = pref.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            if ((words[i].compare(0, s, pref)) == 0){
                count++;
            }
        }
        return count;
    }
};
