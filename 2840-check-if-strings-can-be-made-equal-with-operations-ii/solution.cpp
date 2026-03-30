#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * Determines if s1 can be made equal to s2 by swapping characters 
     * at indices with the same parity (i % 2 == j % 2).
     */
    bool checkStrings(string s1, string s2) {
        int n = s1.length();
        
        // Frequency arrays for even and odd indexed characters
        // countEven[0][char] stores counts for s1, countEven[1][char] for s2
        vector<int> countEven1(26, 0);
        vector<int> countEven2(26, 0);
        vector<int> countOdd1(26, 0);
        vector<int> countOdd2(26, 0);

        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                countEven1[s1[i] - 'a']++;
                countEven2[s2[i] - 'a']++;
            } else {
                countOdd1[s1[i] - 'a']++;
                countOdd2[s2[i] - 'a']++;
            }
        }

        // Check if even-indexed character distributions match
        for (int i = 0; i < 26; ++i) {
            if (countEven1[i] != countEven2[i]) {
                return false;
            }
        }

        // Check if odd-indexed character distributions match
        for (int i = 0; i < 26; ++i) {
            if (countOdd1[i] != countOdd2[i]) {
                return false;
            }
        }

        return true;
    }
};