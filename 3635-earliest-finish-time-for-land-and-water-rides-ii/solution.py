class Solution:
    def earliestFinishTime(self, landStartTime: list[int], landDuration: list[int], 
                           waterStartTime: list[int], waterDuration: list[int]) -> int:
        n = len(landStartTime)
        m = len(waterStartTime)
        
        # Find the earliest possible finish time for any land ride
        L_fin_min = min(landStartTime[i] + landDuration[i] for i in range(n))
        
        # Find the earliest possible finish time for any water ride
        W_fin_min = min(waterStartTime[j] + waterDuration[j] for j in range(m))
        
        # Case 1: Land Ride -> Water Ride
        # We pair the optimal land ride with each water ride
        min_L_to_W = float('inf')
        for j in range(m):
            W_finish = waterStartTime[j] + waterDuration[j]
            current_finish = max(W_finish, L_fin_min + waterDuration[j])
            if current_finish < min_L_to_W:
                min_L_to_W = current_finish
                
        # Case 2: Water Ride -> Land Ride
        # We pair the optimal water ride with each land ride
        min_W_to_L = float('inf')
        for i in range(n):
            L_finish = landStartTime[i] + landDuration[i]
            current_finish = max(L_finish, W_fin_min + landDuration[i])
            if current_finish < min_W_to_L:
                min_W_to_L = current_finish
                
        return min(min_L_to_W, min_W_to_L)