class Solution {
public:
    int minimumPushes(string word) {
        int totalPushes = 0;
        int n = word.length();
            for (int i = 0; i < n; ++i) {
            totalPushes += (i / 8) + 1;
        }

        return totalPushes;
    }
};