class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int n : nums){
            if(mp.find(n) != mp.end())
                return true;
            else
                mp[n]++;
        }

        return false;
    }
};