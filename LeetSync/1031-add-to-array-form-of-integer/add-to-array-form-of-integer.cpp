class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        int carry = 0;

        for (int i = n - 1; i >= 0 && (k > 0 || carry > 0); i--) {
            num[i] = num[i] + k % 10 + carry;
            
            if (num[i] > 9) {
                carry = num[i] / 10;
                num[i] = num[i] % 10;
            } else {
                carry = 0;
            }

            k /= 10;
        }

        while (k > 0 || carry > 0) {
            int x = k % 10 + carry;
            num.insert(num.begin(), x % 10);
            carry = x / 10;
            k /= 10;
        }

        return num;
    }
};