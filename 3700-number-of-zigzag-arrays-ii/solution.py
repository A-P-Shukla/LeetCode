MOD = 10**9 + 7

def multiply(A, B):
    size = len(A)
    C = [[0] * size for _ in range(size)]
    for i in range(size):
        for k in range(size):
            if A[i][k] == 0: continue
            for j in range(size):
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD
    return C

def power(A, p):
    size = len(A)
    res = [[0] * size for _ in range(size)]
    for i in range(size): res[i][i] = 1
    while p > 0:
        if p % 2 == 1: res = multiply(res, A)
        A = multiply(A, A)
        p //= 2
    return res

class Solution:
    def countZigZag(self, n: int, l: int, r: int) -> int:
        K = r - l + 1
        size = 2 * K
        T = [[0] * size for _ in range(size)]
        
        for v in range(K):
            for next_v in range(K):
                if v == next_v: continue
                if v < next_v: T[v][K + next_v] = 1
                else: T[K + v][next_v] = 1
        
        if n == 2: return K * (K - 1)
        
        Tn = power(T, n - 2)
        v2 = [0] * size
        for i in range(K):
            for j in range(K):
                if i < j: v2[K + j] += 1
                elif i > j: v2[j] += 1
        
        ans = 0
        for i in range(size):
            for j in range(size):
                ans = (ans + v2[i] * Tn[i][j]) % MOD
        return ans