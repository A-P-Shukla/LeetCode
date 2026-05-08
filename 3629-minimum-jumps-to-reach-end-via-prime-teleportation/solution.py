import collections

# Precompute SPF at module level for efficiency across test cases
MAXV = 1000001
spf = list(range(MAXV))
for i in range(2, int(MAXV**0.5) + 1):
    if spf[i] == i:
        for j in range(i*i, MAXV, i):
            if spf[j] == j:
                spf[j] = i

class Solution:
    def minimumJumps(self, nums: list[int]) -> int:
        n = len(nums)
        if n == 1:
            return 0
        
        # Identify prime values in nums that can trigger a teleportation
        primes_in_nums = {x for x in nums if x > 1 and spf[x] == x}
        
        # Map trigger primes to indices where the prime is a factor of the value
        prime_to_indices = collections.defaultdict(list)
        for i, val in enumerate(nums):
            temp = val
            while temp > 1:
                p = spf[temp]
                if p in primes_in_nums:
                    prime_to_indices[p].append(i)
                while temp % p == 0:
                    temp //= p
                    
        # BFS initialization
        q = collections.deque([0])
        dist = [-1] * n
        dist[0] = 0
        prime_visited = set()
        
        while q:
            u = q.popleft()
            
            if u == n - 1:
                return dist[u]
            
            d_next = dist[u] + 1
            
            # 1. Adjacent steps
            for v in (u - 1, u + 1):
                if 0 <= v < n and dist[v] == -1:
                    dist[v] = d_next
                    q.append(v)
            
            # 2. Prime Teleportation
            p = nums[u]
            # If current value is a prime and we haven't used its teleportation list yet
            if p in primes_in_nums and p not in prime_visited:
                prime_visited.add(p)
                for v in prime_to_indices[p]:
                    if dist[v] == -1:
                        dist[v] = d_next
                        q.append(v)
                        
        return -1