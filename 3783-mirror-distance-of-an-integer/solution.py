class Solution:
    def mirrorDistance(self, n: int) -> int:
        """
        Calculates the mirror distance by converting the integer to a string,
        reversing it, and finding the absolute difference.
        """
        # Convert n to string, reverse the string, and convert back to integer
        # This naturally handles cases like n = 10 -> reverse = 01 -> 1
        reversed_n = int(str(n)[::-1])
        
        # Calculate and return the absolute difference
        return abs(n - reversed_n)