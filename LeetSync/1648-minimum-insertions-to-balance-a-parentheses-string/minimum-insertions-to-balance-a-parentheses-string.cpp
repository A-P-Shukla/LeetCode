class Solution {
public:
    int minInsertions(string s) {
        long long ans = 0;   
        long long need = 0;  

        for (char c : s) {
            if (c == '(') {
                need += 2;                 
                if (need % 2 == 1) {       
                    ans++;                 
                    need--;                
                }
            } else { 
                need--;                     
                if (need == -1) {           
                    ans++;                 
                    need = 1;              
                }
            }
        }
        ans += need; 
        return (int)ans;
    }
};