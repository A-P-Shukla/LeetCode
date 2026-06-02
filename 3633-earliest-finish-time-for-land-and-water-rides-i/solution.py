class Solution:
    def earliestFinishTime(self, landStartTime: list[int], landDuration: list[int], waterStartTime: list[int], waterDuration: list[int]) -> int:
        n = len(landStartTime)
        m = len(waterStartTime)
        min_finish_time = float('inf')

        for i in range(n):
            for j in range(m):
                # Option 1: Land ride first, then Water ride
                land_finish = landStartTime[i] + landDuration[i]
                water_start = max(land_finish, waterStartTime[j])
                finish_option_1 = water_start + waterDuration[j]

                # Option 2: Water ride first, then Land ride
                water_finish = waterStartTime[j] + waterDuration[j]
                land_start = max(water_finish, landStartTime[i])
                finish_option_2 = land_start + landDuration[i]

                # Keep track of the minimum possible finish time
                min_finish_time = min(min_finish_time, finish_option_1, finish_option_2)

        return min_finish_time