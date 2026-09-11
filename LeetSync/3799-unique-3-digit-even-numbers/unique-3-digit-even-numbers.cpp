class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int>freq(10, 0);

        for(int digit: digits){
            freq[digit]++;
        }

        int count = 0;

        for(int num = 100; num < 999; num += 2){
            int hundred = num/100;
            int ten = (num / 10) % 10;
            int unit = num % 10;

            vector<int>currentFreq(10, 0);
            currentFreq[hundred]++;
            currentFreq[ten]++;
            currentFreq[unit]++;


            bool valid = true;
            for(int i = 0; i < 10; i++){
                if(currentFreq[i] > freq[i]){
                    valid = false;
                    break;
                }
            }

            if(valid){
                count++;
            }            
        }

        return count;
    }
};