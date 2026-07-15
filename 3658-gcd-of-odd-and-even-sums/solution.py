import math

class Solution:
    """
    Calculates the GCD of the sum of the first n odd numbers (n^2) 
    and the sum of the first n even numbers (n^2 + n).
    
    Using the Euclidean algorithm property:
    GCD(n^2, n^2 + n) = GCD(n^2, (n^2 + n) - n^2) = GCD(n^2, n) = n.
    """
    def gcdOfOddAndEvenSums(self, n: int) -> int:
        return n