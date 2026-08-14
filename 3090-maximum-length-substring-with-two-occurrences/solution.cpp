class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxLen = 0;
        int left = 0;
        int count[26] = {0};

        for (int right = 0; right < s.length(); ++right) {
            count[s[right] - 'a']++;

            // Shrink window from the left until the current character's count is <= 2
            while (count[s[right] - 'a'] > 2) {
                count[s[left] - 'a']--;
                left++;
            }

            // Update the maximum valid substring length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};