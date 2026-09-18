class Solution:
    def maxNumOfSubstrings(self, s: str) -> list[str]:
        first = {}
        last = {}
        
        # Record the first and last occurrence of each character
        for i, ch in enumerate(s):
            if ch not in first:
                first[ch] = i
            last[ch] = i

        candidates = []

        # Try forming a valid minimal substring starting at first[ch] for each character
        for ch in first:
            L = first[ch]
            R = last[ch]
            valid = True
            j = L
            
            while j <= R:
                curr_ch = s[j]
                # If a character inside extends before L, L cannot be the start of a minimal valid interval
                if first[curr_ch] < L:
                    valid = False
                    break
                R = max(R, last[curr_ch])
                j += 1
                
            if valid:
                candidates.append((L, R))

        # Sort candidates by end index R ascending
        candidates.sort(key=lambda x: x[1])

        result = []
        last_end = -1

        # Greedily select non-overlapping intervals
        for L, R in candidates:
            if L > last_end:
                result.append(s[L:R + 1])
                last_end = R

        return result