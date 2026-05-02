class Solution:
    def rotatedDigits(self, n: int) -> int:
        """
        Counts the number of "good" integers in range [1, n].
        A number is good if:
        1. It contains no digits from {3, 4, 7}.
        2. It contains at least one digit from {2, 5, 6, 9}.
        """
        count = 0
        
        # Sets for O(1) average lookup
        invalid_digits = {'3', '4', '7'}
        rotating_digits = {'2', '5', '6', '9'}
        
        for i in range(1, n + 1):
            s = str(i)
            # Check if any invalid digits exist
            is_valid = True
            has_diff = False
            
            for char in s:
                if char in invalid_digits:
                    is_valid = False
                    break
                if char in rotating_digits:
                    has_diff = True
            
            if is_valid and has_diff:
                count += 1
                
        return count

    def rotatedDigits_optimized(self, n: int) -> int:
        """
        Alternative approach using set logic for slightly cleaner Python code.
        """
        count = 0
        s1 = {3, 4, 7}
        s2 = {2, 5, 6, 9}
        
        for i in range(1, n + 1):
            digits = set()
            temp = i
            while temp > 0:
                digits.add(temp % 10)
                temp //= 10
            
            # Must not have any from s1, and must have at least one from s2
            if not (digits & s1) and (digits & s2):
                count += 1
        return count