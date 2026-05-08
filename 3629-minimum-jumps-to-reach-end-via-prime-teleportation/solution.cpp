#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAXV = 1000001;
int spf[MAXV];
bool sieve_init = false;

class Solution {
public:
    void ensure_sieve() {
        if (sieve_init) return;
        iota(spf, spf + MAXV, 0);
        for (int i = 2; i * i < MAXV; ++i) {
            if (spf[i] == i) {
                for (int j = i * i; j < MAXV; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }
        sieve_init = true;
    }

    int minimumJumps(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        ensure_sieve();

        // Identify which primes are actually present as values in the array
        vector<bool> is_prime_val(MAXV, false);
        for (int x : nums) {
            if (x > 1 && spf[x] == x) {
                is_prime_val[x] = true;
            }
        }

        // Map primes to indices where the prime is a factor of nums[j]
        // Only track primes that are actually values in nums
        static vector<int> prime_to_indices[MAXV];
        vector<int> active_primes;
        for (int i = 0; i < n; ++i) {
            int temp = nums[i];
            while (temp > 1) {
                int p = spf[temp];
                if (is_prime_val[p]) {
                    if (prime_to_indices[p].empty()) active_primes.push_back(p);
                    prime_to_indices[p].push_back(i);
                }
                while (temp % p == 0) temp /= p;
            }
        }

        queue<int> q;
        vector<int> dist(n, -1);
        vector<bool> prime_used(MAXV, false);

        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == n - 1) {
                // Cleanup static memory for LeetCode's environment
                for (int p : active_primes) prime_to_indices[p].clear();
                return dist[u];
            }

            // Adjacent moves
            for (int v : {u - 1, u + 1}) {
                if (v >= 0 && v < n && dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }

            // Teleportation move
            int val = nums[u];
            if (val > 1 && spf[val] == val && !prime_used[val]) {
                prime_used[val] = true;
                for (int v : prime_to_indices[val]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
        }

        for (int p : active_primes) prime_to_indices[p].clear();
        return -1;
    }
};