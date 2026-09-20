class Solution {
public:
    int reverseDegree(string s) {
        int totalDegree = 0;
        
        for (int i = 0; i < static_cast<int>(s.length()); ++i) {
            int charWeight = 'z' - s[i] + 1;
            int position = i + 1;
            
            totalDegree += charWeight * position;
        }
        
        return totalDegree;
    }
};