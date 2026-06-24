#include <vector>

using namespace std;

long long MOD = 1e9 + 7;

typedef vector<vector<long long>> Matrix;

Matrix multiply(const Matrix& A, const Matrix& B, int size) {
    Matrix C(size, vector<long long>(size, 0));
    for (int i = 0; i < size; ++i)
        for (int k = 0; k < size; ++k)
            for (int j = 0; j < size; ++j)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

Matrix power(Matrix A, long long p, int size) {
    Matrix res(size, vector<long long>(size, 0));
    for (int i = 0; i < size; ++i) res[i][i] = 1;
    while (p > 0) {
        if (p & 1) res = multiply(res, A, size);
        A = multiply(A, A, size);
        p >>= 1;
    }
    return res;
}

class Solution {
public:
    int countZigZag(int n, int l, int r) {
        int K = r - l + 1;
        int size = 2 * K;
        Matrix T(size, vector<long long>(size, 0));

        // State indices: 0 to K-1 (value), direction 0 (prev was up/next must be down), 
        // direction 1 (prev was down/next must be up).
        // Actual index = direction * K + value
        for (int v = 0; v < K; ++v) {
            for (int next_v = 0; next_v < K; ++next_v) {
                if (v == next_v) continue;
                if (v < next_v) T[v][K + next_v] = 1;      // Up step: from v to next_v
                else T[K + v][next_v] = 1;                // Down step: from v to next_v
            }
        }

        Matrix Tn = power(T, n - 2, size);
        
        vector<long long> v2(size, 0);
        for (int i = 0; i < K; ++i) {
            for (int j = 0; j < K; ++j) {
                if (i < j) v2[K + j] = (v2[K + j] + 1) % MOD;
                else if (i > j) v2[j] = (v2[j] + 1) % MOD;
            }
        }

        long long ans = 0;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                ans = (ans + v2[i] * Tn[i][j]) % MOD;
            }
        }
        return (int)ans;
    }
};