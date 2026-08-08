class Solution {
public:
    int countPrimes(int n) {

        if(n <= 2) return 0;

        vector<bool> isPrime(n, true);

        isPrime[0] = false;
        isPrime[1] = false;
        
        for(int num = 2; num * num < n; num++){
            if(isPrime[num]){
                for(int i = num * num; i < n; i += num){
                    isPrime[i] = false;
                }
            }
        }

        int count = 0;

        for(int i = 2; i < n; i++){
            if(isPrime[i])  
                count++;
        }

        return count;
    }
};