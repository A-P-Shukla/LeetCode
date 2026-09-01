class Solution:
    def minMoves(self, classroom: List[str], energy: int) -> int:
        m, n = len(classroom), len(classroom[0])
        
        start_r, start_c = -1, -1
        litters = []
        
        for r in range(m):
            for c in range(n):
                if classroom[r][c] == 'S':
                    start_r, start_c = r, c
                elif classroom[r][c] == 'L':
                    litters.append((r, c))
                    
        num_litter = len(litters)
        if num_litter == 0:
            return 0
            
        target_mask = (1 << num_litter) - 1
        
        litter_map = {}
        for idx, (r, c) in enumerate(litters):
            litter_map[(r, c)] = idx
            
        num_masks = 1 << num_litter
        max_energy = [[[-1] * num_masks for _ in range(n)] for _ in range(m)]
        
        queue = deque([(start_r, start_c, 0, energy, 0)])
        max_energy[start_r][start_c][0] = energy
        
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        
        while queue:
            r, c, mask, e, steps = queue.popleft()
            
            if e == 0:
                continue
                
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                if 0 <= nr < m and 0 <= nc < n:
                    cell = classroom[nr][nc]
                    if cell == 'X':
                        continue
                        
                    ne = e - 1
                    if cell == 'R':
                        ne = energy  
                        
                    nmask = mask
                    if cell == 'L':
                        litter_idx = litter_map[(nr, nc)]
                        nmask |= (1 << litter_idx)
                        
                    if nmask == target_mask:
                        return steps + 1
                        
                    if ne > 0 and ne > max_energy[nr][nc][nmask]:
                        max_energy[nr][nc][nmask] = ne
                        queue.append((nr, nc, nmask, ne, steps + 1))
                        
        return -1