class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        int bit_len = 32 - __builtin_clz(n);
        return 1 << bit_len;
    }
};