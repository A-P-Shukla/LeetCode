class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> res;
        unordered_map<int, int> mp;
        int count = 0;

        for(int i = 0; i < n; i++){
            int rem = ((arr[i] % k) + k) % k;;
            res.push_back(rem);
            if(!mp[rem])
                mp[rem] = 1;
            else{
                mp[rem]++;
            }
        }

        if(mp[0] % 2 != 0){
            return false;
        }

        for (int rem = 1; rem < k; rem++) {
            int complement = k - rem;

            if (mp[rem] != mp[complement])
                return false;
        }

        return true;
    }
};