class Solution:
    def separateDigits(self, nums: list[int]) -> list[int]:
        """
        Approach: Convert each integer to a string to easily iterate over its digits,
        then convert each character back to an integer and flatten the list.
        """
        answer = []
        
        for num in nums:
            # Convert number to string to access individual digits
            s_num = str(num)
            for char in s_num:
                # Convert back to integer and append to result
                answer.append(int(char))
                
        return answer

    def separateDigitsAlternative(self, nums: list[int]) -> list[int]:
        """
        Alternative: One-liner using list comprehension for Pythonic efficiency.
        """
        return [int(digit) for num in nums for digit in str(num)]