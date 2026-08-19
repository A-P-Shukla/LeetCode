# 1386. Cinema Seat Allocation

### Metadata Table
| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Hash Table, Bit Manipulation, Greedy |
| Date | 2026-08-19 |
| LeetCode Link | [Cinema Seat Allocation](https://leetcode.com/problems/cinema-seat-allocation/) |

---

### Intuition

The problem asks for the maximum number of 4-person groups we can seat in a cinema with $n$ rows, where each row has 10 seats. Seats 1 and 10 are aisle seats and cannot form a complete 4-seat block by themselves or in combination with other seats. Thus, seats 1 and 10 can be ignored completely when evaluating seating configurations.

A 4-person group can be seated in one of three possible contiguous 4-seat blocks per row:
1. **Left Block**: Seats 2, 3, 4, 5
2. **Middle Block**: Seats 4, 5, 6, 7
3. **Right Block**: Seats 6, 7, 8, 9

Key Observations:
- **Maximum per row**: A row can host at most **2** groups (by taking the Left and Right blocks simultaneously, since seats 2–5 and 6–9 do not overlap).
- **Default for unreserved rows**: Any row without any reserved seats in positions 2 through 9 can automatically host **2** groups.
- **Large $n$ constraint**: Since $n$ can be up to $10^9$, we cannot iterate through all rows. However, the number of reserved seats is at most $10^4$. Therefore, we only need to process rows that contain reserved seats.

We can represent the reservation status of seats 2–9 in a row using an 8-bit integer (bitmask):
- Bit $k$ (0-indexed) is set if seat $k + 2$ is reserved.
- **Left Block**: requires bits 0, 1, 2, 3 to be 0 (`0x0F` or `0b00001111`).
- **Right Block**: requires bits 4, 5, 6, 7 to be 0 (`0xF0` or `0b11110000`).
- **Middle Block**: requires bits 2, 3, 4, 5 to be 0 (`0x3C` or `0b00111100`).

For each row with reservations:
1. If both Left and Right blocks are available, we add 2 to our total.
2. Else if at least one of Left, Right, or Middle blocks is available, we add 1 to our total.
3. Otherwise, we add 0.

---

### Complexity Analysis

- **Time Complexity**: $\mathcal{O}(R)$, where $R$ is the number of reserved seats ($R \le 10^4$). Populating the bitmasks takes $\mathcal{O}(R)$ time, and iterating over at most $R$ modified rows in the hash table takes $\mathcal{O}(U)$ time, where $U \le R$ is the number of unique reserved rows.
- **Space Complexity**: $\mathcal{O}(U)$, where $U$ is the number of distinct rows that have reservations, required for storing the hash map.

---