class Solution:
    def maxNumOfSubstrings(self, s: str) -> list[str]:
        first = {}
        last = {}
        
        for i, ch in enumerate(s):
            if ch not in first:
                first[ch] = i
            last[ch] = i

        candidates = []

        for ch in first:
            L = first[ch]
            R = last[ch]
            valid = True
            j = L
            
            while j <= R:
                curr_ch = s[j]
                if first[curr_ch] < L:
                    valid = False
                    break
                R = max(R, last[curr_ch])
                j += 1
                
            if valid:
                candidates.append((L, R))

        candidates.sort(key=lambda x: x[1])

        result = []
        last_end = -1

        for L, R in candidates:
            if L > last_end:
                result.append(s[L:R + 1])
                last_end = R

        return result