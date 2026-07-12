# 1331. Rank Transform of an Array

| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | Array, Hash Table, Sorting |
| Date | 2026-07-12 |
| LeetCode Link | https://leetcode.com/problems/rank-transform-of-an-array/ |

### Intuition

To determine the rank of each element, we need to know the relative order of the unique elements in the input array. 

1.  **Extract and Sort:** First, identify all unique values present in the array. Sorting these values allows us to determine their relative magnitude easily.
2.  **Mapping:** Once sorted, the index of each unique element (plus one) naturally represents its rank. We can store these rankings in a Hash Map (dictionary in Python) where the key is the array value and the value is its corresponding rank.
3.  **Transformation:** Iterate through the original array and replace each element with its rank retrieved from the map.

This approach ensures that identical values receive the same rank, and the process is efficient enough to handle the constraints of up to $10^5$ elements.

### Complexity Analysis

*   **Time Complexity:** $O(N \log N)$, where $N$ is the number of elements in the array. Sorting the unique elements takes $O(N \log N)$ time. Populating the hash map and transforming the array takes $O(N)$ time.
*   **Space Complexity:** $O(N)$. We store up to $N$ unique elements in the hash map and create a result array of size $N$.