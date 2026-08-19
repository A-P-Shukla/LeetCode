class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l = 0;
        int r = height.size() - 1;

        while(l < r){
            int high = min(height[l], height[r]);
            int width = r - l;

            ans = max(ans, high * width);

            if(height[l] < height[r]){
                l++;
            }
            else{
                r--;
            }
        }

        return ans;
    }
};