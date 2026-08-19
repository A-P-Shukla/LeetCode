class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string, int> mp;

        for(int i = 0;  i < s.length(); i++){
            string temp = s.substr(i, 10);

            mp[temp]++;

            if(mp[temp] == 2){
                ans.push_back(temp);
            }
        }

        return ans;
    }
};