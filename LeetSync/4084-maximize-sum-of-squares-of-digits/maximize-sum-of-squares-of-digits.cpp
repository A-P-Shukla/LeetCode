class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9LL * num) return "";
        string ans;
        ans.reserve(num);
        for (int i = 0; i < num; ++i) {
            int positionsLeft = num - i - 1;
            int start = 0;
            if (i == 0 && num > 1) start = 1;
            int chosen = -1;
            for (int d = 9; d >= start; --d) {
                int remaining = sum - d;
                if (remaining < 0) continue;                     
                if (remaining > 9LL * positionsLeft) continue;   
                chosen = d;
                break;
            }
            if (chosen == -1) return ""; 
            ans.push_back('0' + chosen);
            sum -= chosen;
        }
        if (sum != 0) return "";
        return ans;
    }
};