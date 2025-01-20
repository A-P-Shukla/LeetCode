//Code 1:
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        long counts[60] = {};
        for(auto &t : time)
            ++counts[t%60];
        
        long ans = 0;
        for(int i = 1; i < 30; ++i)
            ans += counts[i]*counts[60-i];
        ans += (counts[0]*(counts[0]-1)/2);
        ans += (counts[30]*(counts[30]-1)/2);

        return ans;
    }
};

//Code 2:
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0 ;
        unordered_map<int,int>mp;
        for(int &t :time){
            int rem = t%60;
            if(rem == 0) count+=mp[0];
            else count+= mp[60-rem];
            mp[rem]++;
        }
        return count ;
    }
};

//Code 3:
class Solution {
 public:
  int numPairsDivisibleBy60(vector<int>& time) {
    int ans = 0;
    vector<int> count(60);

    for (int t : time) {
      t %= 60;
      ans += count[(60 - t) % 60];
      ++count[t];
    }

    return ans;
  }
};

//Code 4:
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& times) {
        int remainderCount[60] = {};
        for (int& time : times) {
            ++remainderCount[time % 60];
        }
        int pairsCount = 0;
        for (int i = 1; i < 30; ++i) {
            pairsCount += remainderCount[i] * remainderCount[60 - i];
        }
        pairsCount += static_cast<long long>(remainderCount[0]) * (remainderCount[0] - 1) / 2;
        pairsCount += static_cast<long long>(remainderCount[30]) * (remainderCount[30] - 1) / 2;
        return pairsCount;
    }
};
