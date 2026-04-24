# 2833. Furthest Point From Origin

| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | String, Counting |
| Date | April 24, 2026 |
| LeetCode Link | [https://leetcode.com/problems/furthest-point-from-origin/](https://leetcode.com/problems/furthest-point-from-origin/) |

## Intuition

The problem asks us to find the maximum possible absolute distance from the origin on a number line after a sequence of moves. We are given fixed moves ('L' for left, 'R' for right) and flexible moves ('_' which can be either left or right).

To maximize the absolute distance from zero, we should leverage the flexible moves ('_') to reinforce the direction that already has the majority of the fixed moves. 

1.  **Fixed Displacement**: First, calculate the net displacement caused by the fixed 'L' and 'R' characters. If we treat 'R' as $+1$ and 'L' as $-1$, the net fixed displacement is simply `count(R) - count(L)`.
2.  **Greedy Choice**: To reach the furthest point, we should assign all '_' characters to the same direction. 
    *   If the net fixed displacement is positive (more 'R' than 'L'), we move right for every '_'.
    *   If the net fixed displacement is negative (more 'L' than 'R'), we move left for every '_'.
    *   If they are equal, either direction for all '_' yields the same maximum distance.

Mathematically, the furthest distance is the absolute difference between the counts of 'L' and 'R', plus the total count of '_' characters:
`Distance = abs(count('R') - count('L')) + count('_')`

## Complexity Analysis

- **Time Complexity**: $O(n)$, where $n$ is the length of the string `moves`. We traverse the string once to count the occurrences of each character.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the counts regardless of the input size.