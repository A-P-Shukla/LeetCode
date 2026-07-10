class Solution:
    def answerQueries(self, n: int, nums: list[int], maxDiff: int, queries: list[list[int]]) -> list[int]:
        # Pair nodes with their values and sort by value
        sorted_nodes = sorted([(nums[i], i) for i in range(n)])
        
        comp_id = [0] * n
        current_comp = 0
        comp_id[sorted_nodes[0][1]] = current_comp
        
        # Identify connected components based on the maxDiff threshold
        for i in range(1, n):
            if sorted_nodes[i][0] - sorted_nodes[i-1][0] > maxDiff:
                current_comp += 1
            comp_id[sorted_nodes[i][1]] = current_comp
            
        results = []
        for u, v in queries:
            if u == v:
                results.append(0)
            elif comp_id[u] != comp_id[v]:
                results.append(-1)
            else:
                # If in same component, distance is 1 if directly reachable, else 2
                if abs(nums[u] - nums[v]) <= maxDiff:
                    results.append(1)
                else:
                    results.append(2)
        return results