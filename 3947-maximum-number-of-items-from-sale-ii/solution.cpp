#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    long long maxItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        
        // Precompute which items' factors divide others'. Map item id -> {ids it activates}
        vector<vector<int>> activated(n);
        vector<int> factors(n);
        for(int i = 0; i < n; ++i){
            factors[i] = items[i][0];
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(i == j) continue;
                if(factors[j] % factors[i] == 0){
                    activated[i].push_back(j);
                }
            }
        }

        vector<pair<long long, int>> sorted_items;
        for(int i = 0; i < n; ++i){
            sorted_items.emplace_back(static_cast<long long>(items[i][1]), i); // price, index
        }

        sort(sorted_items.begin(), sorted_items.end());

        long long res = 0;
        long long spent = 0;

        // To avoid reactivating same (source,target) combo twice
        vector<bool> activated_flags(n, false);

        for(const auto& p : sorted_items){
            long long price = p.first;
            int idx = p.second;

            if(spent + price > budget) continue;

            // Buy as many as permissible under remaining budget
            long long buy_count = (budget - spent) / price;
            if(buy_count == 0) continue;
            
            spent += buy_count * price;
            res += buy_count;

            // Claim bonus for this item type only if not already done before
            if(!activated_flags[idx]){
                for(auto target : activated[idx]){
                    res += 1;  // One-time reward activation
                }
                activated_flags[idx] = true;
            }
        }

        return res;
    }
};