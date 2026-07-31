class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int rm = n/20;
        double sum = 0.00;

        for(int i = rm; i < n-rm; i++){
            sum += arr[i];
        }

        return sum/(n- 2 * rm);
    }
};