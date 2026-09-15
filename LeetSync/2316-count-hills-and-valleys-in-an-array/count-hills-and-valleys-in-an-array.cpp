class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int hill = 0;
        vector<int> a;

        for(int x: nums){
            if(a.empty() || a.back() != x)
                a.push_back(x);
        }

        for(int i = 1; i < a.size()-1; i++){
            if((a[i] > a[i - 1] && a[i] > a[i + 1]) ||
                (a[i] < a[i - 1] && a[i] < a[i + 1])){
                hill++;
            }
        }
        return hill;
    }
};