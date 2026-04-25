# 3464. Maximize the Distance Between Points on a Square

Property | Value
--- | ---
Difficulty | Hard
Topics | Array, Math, Binary Search, Geometry, Sorting
Date | April 25, 2026
LeetCode Link | [Maximize the Distance Between Points on a Square](https://leetcode.com/problems/maximize-the-distance-between-points-on-a-square/)

## Intuition

The problem asks us to select $k$ points from a given set of points on the boundary of a square to maximize the minimum Manhattan distance between any two selected points. This "maximize the minimum" structure is a classic signal for **Binary Search on the Answer**.

1.  **Coordinate Mapping**: A key observation is that points on the boundary of a square can be mapped to a 1D coordinate representing the distance along the perimeter. Let the side length be `side`. We map a point $(x, y)$ to $d \in [0, 4 \cdot side)$ as follows:
    *   Bottom edge ($y=0$): $d = x$
    *   Right edge ($x=side$): $d = side + y$
    *   Top edge ($y=side$): $d = 3 \cdot side - x$
    *   Left edge ($x=0$): $d = 4 \cdot side - y$
    
    This 1D mapping allows us to sort the points and process them in clockwise order.

2.  **Manhattan vs. Perimeter Distance**: For any two points on a square boundary, the Manhattan distance $L_1$ is at most the shortest distance along the boundary. Since $k \ge 4$, the maximum possible minimum distance $D$ must be $\le side$ (because the average gap between 4 points on a $4 \cdot side$ perimeter is $side$). When $D \le side$, the Manhattan distance between two points $P_i, P_j$ equals their perimeter distance if they are on the same or adjacent sides. If they are on opposite sides, the Manhattan distance is at least $side \ge D$. This allows us to use the 1D perimeter order to greedily pick points.

3.  **Greedy Check**: For a fixed distance $D$, we want to know if we can pick $k$ points. Because it's a circular arrangement, we try starting our greedy selection from different points. However, we only need to check starting points within the first $\lfloor n/k \rfloor$ indices. This is because in any valid selection of $k$ points, at least one "gap" between adjacent indices in the sorted list must be $\le \lfloor n/k \rfloor$. By rotating our starting point, we ensure we find a valid configuration if one exists.

## Complexity Analysis

*   **Time Complexity**: $O(N \log N + N \log N \log(\text{side}))$.
    *   Sorting the points takes $O(N \log N)$.
    *   Binary search on the answer $D$ takes $O(\log(\text{side}))$ iterations.
    *   Inside the check function, we iterate through $O(N/K)$ starting points and perform $K$ binary searches on the $N$ points to find the next point, resulting in $O(\frac{N}{K} \cdot K \cdot \log N) = O(N \log N)$ per check.
*   **Space Complexity**: $O(N)$ to store the points and their perimeter coordinates.