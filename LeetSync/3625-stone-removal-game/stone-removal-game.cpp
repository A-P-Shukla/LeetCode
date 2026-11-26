class Solution {
public:
    bool canAliceWin(int n) {
        int required = 10;         
        bool aliceTurn = true;     
        while (required > 0 && n >= required) {
            n -= required;          
            required--;             
            aliceTurn = !aliceTurn; 
        }

        return !aliceTurn;
    }
};