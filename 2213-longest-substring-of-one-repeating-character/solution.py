class SegmentTree:
    def __init__(self, s: str):
        self.n = len(s)
        self.max_len = [0] * (4 * self.n)
        self.prefix_len = [0] * (4 * self.n)
        self.prefix_char = [''] * (4 * self.n)
        self.suffix_len = [0] * (4 * self.n)
        self.suffix_char = [''] * (4 * self.n)
        self.length = [0] * (4 * self.n)
        self._build(1, 0, self.n - 1, s)

    def _merge(self, idx: int, left_child: int, right_child: int):
        self.length[idx] = self.length[left_child] + self.length[right_child]

        # Prefix
        self.prefix_char[idx] = self.prefix_char[left_child]
        self.prefix_len[idx] = self.prefix_len[left_child]
        if (self.prefix_len[left_child] == self.length[left_child] and 
                self.suffix_char[left_child] == self.prefix_char[right_child]):
            self.prefix_len[idx] += self.prefix_len[right_child]

        # Suffix
        self.suffix_char[idx] = self.suffix_char[right_child]
        self.suffix_len[idx] = self.suffix_len[right_child]
        if (self.suffix_len[right_child] == self.length[right_child] and 
                self.suffix_char[left_child] == self.prefix_char[right_child]):
            self.suffix_len[idx] += self.suffix_len[left_child]

        # Max len
        m_len = max(self.max_len[left_child], self.max_len[right_child])
        if self.suffix_char[left_child] == self.prefix_char[right_child]:
            m_len = max(m_len, self.suffix_len[left_child] + self.prefix_len[right_child])
        self.max_len[idx] = m_len

    def _build(self, idx: int, start: int, end: int, s: str):
        if start == end:
            ch = s[start]
            self.max_len[idx] = 1
            self.prefix_len[idx] = 1
            self.prefix_char[idx] = ch
            self.suffix_len[idx] = 1
            self.suffix_char[idx] = ch
            self.length[idx] = 1
            return
        
        mid = (start + end) // 2
        left_child, right_child = 2 * idx, 2 * idx + 1
        self._build(left_child, start, mid, s)
        self._build(right_child, mid + 1, end, s)
        self._merge(idx, left_child, right_child)

    def update(self, idx: int, start: int, end: int, pos: int, ch: str):
        if start == end:
            self.prefix_char[idx] = ch
            self.suffix_char[idx] = ch
            return

        mid = (start + end) // 2
        left_child, right_child = 2 * idx, 2 * idx + 1
        if pos <= mid:
            self.update(left_child, start, mid, pos, ch)
        else:
            self.update(right_child, mid + 1, end, pos, ch)
        self._merge(idx, left_child, right_child)


class Solution:
    def longestRepeating(self, s: str, queryCharacters: str, queryIndices: list[int]) -> list[int]:
        n = len(s)
        tree = SegmentTree(s)
        ans = []

        for ch, idx in zip(queryCharacters, queryIndices):
            tree.update(1, 0, n - 1, idx, ch)
            ans.append(tree.max_len[1])

        return ans