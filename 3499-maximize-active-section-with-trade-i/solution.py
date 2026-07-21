class Solution:
    def maximizeActiveSection(self, s: str) -> int:
        n = len(s)
        ones = []
        zeros = []
        total_ones = 0
        
        i = 0
        start_with_one = (s[0] == '1')
        
        # Group segments
        while i < n:
            count = 0
            target = s[i]
            while i < n and s[i] == target:
                count += 1
                i += 1
            if target == '1':
                ones.append(count)
                total_ones += count
            else:
                zeros.append(count)
        
        if not zeros:
            return total_ones
            
        # Pad ones list to match zeros adjacent to it
        if not start_with_one:
            ones.insert(0, 0)
        if s[-1] == '0':
            ones.append(0)
            
        max_gain = 0
        # For each block of 0s, consider removing one of the adjacent 1-blocks
        for j in range(len(zeros)):
            gain = zeros[j] - min(ones[j], ones[j + 1])
            if gain > max_gain:
                max_gain = gain
                
        return total_ones + max_gain