#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @brief Converts a string into zigzag pattern across numRows rows,
     *        then reads it row by row.
     */
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= (int)s.size()) return s;

        vector<string> rows(numRows);
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currentRow] += c;
            if (currentRow == 0 || currentRow == numRows - 1)
                goingDown = !goingDown;
            currentRow += goingDown ? 1 : -1;
        }

        string result;
        for (const string& row : rows)
            result += row;
        return result;
    }
};
