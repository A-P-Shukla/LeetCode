class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        const int ALL_BITS = (1 << 30) - 1;          
        int k = ALL_BITS;
        bool hasMisplaced = false;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] != i) {                     
                hasMisplaced = true;
                k &= i;                              
                k &= nums[i];                        
            }
        }
        return hasMisplaced ? k : 0;    
    }
};