//Using ASCII value Logic:
class Solution {
 public:
  int getNumber(const string& word) {
    int num = 0;
    for (const char c : word)
      num = num * 10 + (c - 'a');
    return num;
  }
  bool isSumEqual(string firstWord, string secondWord, string targetWord) {
    const int first = getNumber(firstWord);
    const int second = getNumber(secondWord);
    const int target = getNumber(targetWord);
    return first + second == target;
  }
};
