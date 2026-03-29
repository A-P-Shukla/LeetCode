class Solution {
public:
    /**
     * Checks if string s1 can be made equal to s2 by swapping characters 
     * at indices i and j where |i - j| = 2.
     * 
     * For a string of length 4, this means:
     * - s1[0] can swap with s1[2]
     * - s1[1] can swap with s1[3]
     */
    bool canBeEqual(string s1, string s2) {
        // Check even indices (0 and 2)
        // They are equal if (s1[0]==s2[0] and s1[2]==s2[2]) OR (s1[0]==s2[2] and s1[2]==s2[0])
        bool evenMatch = (s1[0] == s2[0] && s1[2] == s2[2]) || 
                         (s1[0] == s2[2] && s1[2] == s2[0]);
        
        // Check odd indices (1 and 3)
        // They are equal if (s1[1]==s2[1] and s1[3]==s2[3]) OR (s1[1]==s2[3] and s1[3]==s2[1])
        bool oddMatch = (s1[1] == s2[1] && s1[3] == s2[3]) || 
                        (s1[1] == s2[3] && s1[3] == s2[1]);
        
        // Both sets must be able to match their respective counterparts in s2
        return evenMatch && oddMatch;
    }
};