class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string token;
        int countWords = 0;

        while(getline(ss, token, ' ')){
            words.push_back(token);
            countWords++;
        }

        int n = pattern.size();

        if(n != countWords)
            return false;

        unordered_map<string, char> mp;
        set<char> st;
        
        for(int i = 0; i < n; i++){
            if(mp.find(words[i]) == mp.end() && st.find(pattern[i]) == st.end()){
                mp[words[i]] = pattern[i];
                st.insert(pattern[i]);
            }
            else if(mp[words[i]] != pattern[i])
                return false;
        }

        return true;
    }
};