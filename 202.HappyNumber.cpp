class Solution {
public:
int getsum(int n){
    int sum = 0;
    while (n>0) {
        int digit = n%10;
        sum += digit*digit;
        n = n/10;
    }
    return sum;
}
     bool isHappy(int n) {
        int slow = n;
        int fast = getsum(n);
        while(fast != 1 && slow != fast){
            slow=getsum(slow);
            fast=getsum(getsum(fast));
        }
        return fast == 1;
    }
};
