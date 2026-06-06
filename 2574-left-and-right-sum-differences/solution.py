class Solution:
    def leftRightDifference(self, nums: list[int]) -> list[int]:
        total_sum = sum(nums)
        left_sum = 0
        answer = []
        
        for num in nums:
            # Calculate the right sum mathematically
            right_sum = total_sum - left_sum - num
            # Append the absolute difference
            answer.append(abs(left_sum - right_sum))
            # Update the left sum for the next iteration
            left_sum += num
            
        return answer