class Solution:
    def smallestPalindrome(self, s: str, target: str) -> str:
        n = len(s)
        cnt = [0] * 26
        for ch in s:
            cnt[ord(ch) - ord('a')] += 1
        
        odd_cnt = 0
        mid_char = ""
        for i in range(26):
            if cnt[i] % 2 != 0:
                odd_cnt += 1
                mid_char = chr(ord('a') + i)
        
        # Validate palindrome feasibility
        if n % 2 == 0 and odd_cnt != 0:
            return ""
        if n % 2 != 0 and odd_cnt != 1:
            return ""
        
        half = n // 2
        half_count = [cnt[i] // 2 for i in range(26)]
        
        # Determine max match length for first half
        temp_count = list(half_count)
        max_match = 0
        for i in range(half):
            idx = ord(target[i]) - ord('a')
            if temp_count[idx] > 0:
                temp_count[idx] -= 1
                max_match += 1
            else:
                break
        
        # Candidate 0: Exact match of first half
        if max_match == half:
            p_list = [''] * n
            for i in range(half):
                p_list[i] = target[i]
                p_list[n - 1 - i] = target[i]
            if n % 2 != 0:
                p_list[half] = mid_char
            p = "".join(p_list)
            if p > target:
                return p
        
        # Precompute available counts at each index k
        avail_at_k = [list(half_count)]
        for i in range(max_match):
            next_avail = list(avail_at_k[-1])
            next_avail[ord(target[i]) - ord('a')] -= 1
            avail_at_k.append(next_avail)
            
        start_k = min(half - 1, max_match)
        for k in range(start_k, -1, -1):
            cur_avail = list(avail_at_k[k])
            target_idx = ord(target[k]) - ord('a')
            
            chosen_char = -1
            for c in range(target_idx + 1, 26):
                if cur_avail[c] > 0:
                    chosen_char = c
                    break
            
            if chosen_char != -1:
                p_list = [''] * n
                # Match prefix up to k-1
                for i in range(k):
                    p_list[i] = target[i]
                
                # Pick strictly larger char at index k
                p_list[k] = chr(ord('a') + chosen_char)
                cur_avail[chosen_char] -= 1
                
                # Fill k+1 to half-1 in ascending order
                fill_idx = k + 1
                for c in range(26):
                    while cur_avail[c] > 0:
                        p_list[fill_idx] = chr(ord('a') + c)
                        fill_idx += 1
                        cur_avail[c] -= 1
                
                # Set middle element if odd length
                if n % 2 != 0:
                    p_list[half] = mid_char
                
                # Mirror to form second half
                for i in range(half):
                    p_list[n - 1 - i] = p_list[i]
                
                return "".join(p_list)
        
        return ""