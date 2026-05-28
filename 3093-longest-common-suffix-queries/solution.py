from typing import List

class TrieNode:
    def __init__(self):
        self.children = {}
        self.best_index = -1

class Solution:
    def stringIndices(self, wordsContainer: List[str], wordsQuery: List[str]) -> List[int]:
        root = TrieNode()
        
        def update_best(node: TrieNode, idx: int) -> None:
            if node.best_index == -1:
                node.best_index = idx
            elif len(wordsContainer[idx]) < len(wordsContainer[node.best_index]):
                node.best_index = idx
                
        # Build the suffix trie
        for idx, word in enumerate(wordsContainer):
            curr = root
            update_best(curr, idx)
            # Traverse characters in reverse
            for char in reversed(word):
                if char not in curr.children:
                    curr.children[char] = TrieNode()
                curr = curr.children[char]
                update_best(curr, idx)
                
        ans = []
        # Answer each query
        for query in wordsQuery:
            curr = root
            best = root.best_index
            for char in reversed(query):
                if char not in curr.children:
                    break
                curr = curr.children[char]
                best = curr.best_index
            ans.append(best)
            
        return ans