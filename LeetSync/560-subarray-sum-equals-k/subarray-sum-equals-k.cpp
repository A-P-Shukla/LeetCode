class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        mp[0] = 1;

        int curr_sum = 0;
        int count = 0;

        for(int num : nums){
            curr_sum += num;
            auto it = mp.find(curr_sum - k);
            if(it != mp.end()){
                count += it->second;
            }

            mp[curr_sum]++;
        }

        return count;
    }
};