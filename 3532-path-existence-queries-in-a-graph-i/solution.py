class Solution:
    def pathExistence(self, n: int, nums: list[int], maxDiff: int, queries: list[list[int]]) -> list[bool]:
        # component_id[i] will store the ID of the connected component node i belongs to
        component_id = [0] * n
        current_id = 0
        
        # Since nums is sorted, nodes i and i+1 are connected if nums[i+1] - nums[i] <= maxDiff
        for i in range(1, n):
            if nums[i] - nums[i - 1] > maxDiff:
                current_id += 1
            component_id[i] = current_id
            
        results = []
        # Two nodes are connected if they have the same component_id
        for u, v in queries:
            results.append(component_id[u] == component_id[v])
            
        return results