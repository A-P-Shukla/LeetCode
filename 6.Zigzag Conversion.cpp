//Code 1:
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) {
            return s;
        }
        vector<string> rows(numRows);
        int currentRow = 0;
        bool goingDown = false;
        for (char c : s) {
            rows[currentRow] += c;
            if (currentRow == 0 || currentRow == numRows - 1) goingDown = !goingDown;
            currentRow += goingDown ? 1 : -1;
        }
        string result;
        for (string row : rows) {
            result += row;
        }
        return result;
    }
};

//Code 2:
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;
        string result;
        int cycleLen = 2 * numRows - 2;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < s.size(); j += cycleLen) {
                result += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < s.size()) {
                    result += s[j + cycleLen - i];
                }
            }
        }
        return result;
    }
};
