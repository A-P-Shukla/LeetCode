import bisect

class Solution:
    def maxDistance(self, side: int, points: list[list[int]], k: int) -> int:
        def get_perimeter_dist(x, y, side):
            if y == 0: return x                 # Bottom
            if x == side: return side + y       # Right
            if y == side: return 3 * side - x   # Top
            return 4 * side - y                 # Left

        # Map points to 1D perimeter coordinates and sort
        mapped_points = []
        for x, y in points:
            d = get_perimeter_dist(x, y, side)
            mapped_points.append((d, x, y))
        
        mapped_points.sort()
        n = len(mapped_points)
        ds = [p[0] for p in mapped_points]

        def can(D):
            # Check starts only up to n/k based on pigeonhole principle for circular gaps
            for i in range(n // k + 1):
                count = 1
                last_idx = i
                possible = True
                for _ in range(k - 1):
                    target = ds[last_idx] + D
                    # Binary search for the next point clockwise
                    next_idx = bisect.bisect_left(ds, target, lo=last_idx + 1)
                    if next_idx == n:
                        possible = False
                        break
                    last_idx = next_idx
                    count += 1
                
                if possible and count == k:
                    # Verify Manhattan distance for the cycle wrap-around
                    p_start = mapped_points[i]
                    p_end = mapped_points[last_idx]
                    if abs(p_start[1] - p_end[1]) + abs(p_start[2] - p_end[2]) >= D:
                        return True
            return False

        # Binary search for the maximum minimum distance
        low, high = 1, side
        ans = 0
        while low <= high:
            mid = (low + high) // 2
            if can(mid):
                ans = mid
                low = mid + 1
            else:
                high = mid - 1
        return ans