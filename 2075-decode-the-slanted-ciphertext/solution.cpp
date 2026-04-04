#include <string>
#include <vector>

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1) return encodedText;
        
        int n = encodedText.length();
        int cols = n / rows;
        std::string res = "";
        
        // The original text follows diagonals starting from each column in the first row
        for (int j = 0; j < cols; ++j) {
            for (int r = 0, c = j; r < rows && c < cols; ++r, ++c) {
                // index in the encodedText string based on row-wise storage
                res += encodedText[r * cols + c];
            }
        }
        
        // Remove trailing spaces as per problem statement
        while (!res.empty() && res.back() == ' ') {
            res.pop_back();
        }
        
        return res;
    }
};