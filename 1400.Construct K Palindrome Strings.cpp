//Brute Force:
class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k) return false;
        vector<char> charCount;
        for (char c : s) {
            auto it = find(charCount.begin(), charCount.end(), c);
            if (it != charCount.end()) {
                charCount.erase(it);
            } else {
                charCount.push_back(c);
            }
        }

        return charCount.size() <= k;
    }
};

//Optimized:
class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k) return false;
        vector<int> charCount(26, 0);
        for (char c : s) {
            charCount[c - 'a']++;
        }
        int oddCount = 0;
        for (int count : charCount) {
            if (count % 2 != 0) {
                oddCount++;
            }
        }
        return oddCount <= k;
    }
};
