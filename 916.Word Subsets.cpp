//My code:
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxCount(26, 0);
        for (const string& word : words2) {
            vector<int> count(26, 0);
            for (char c : word) {
                count[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                maxCount[i] = max(maxCount[i], count[i]);
            }
        }
        vector<string> result;
        for (const string& word : words1) {
            vector<int> count(26, 0);
            for (char c : word) {
                count[c - 'a']++;
            }
            bool isUniversal = true;
            for (int i = 0; i < 26; i++) {
                if (count[i] < maxCount[i]) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                result.push_back(word);
            }
        }
        return result;
    }
};
