# 2196. Create Binary Tree From Descriptions

### Metadata Table
Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Hash Table, Tree, Binary Tree
Date | June 7, 2026
LeetCode Link | [https://leetcode.com/problems/create-binary-tree-from-descriptions/](https://leetcode.com/problems/create-binary-tree-from-descriptions/)

### Intuition
To reconstruct a binary tree from parent-child relationships, we need a way to:
1. Instatitate and look up nodes dynamically without creating duplicate instances for the same value.
2. Link parents to their children as specified.
3. Determine which node is the global root of the tree.

**Step 1: Node Representation and Map Tracking**
We can use a hash map (`valToNode`) mapping integer values to their corresponding `TreeNode` pointers/objects. As we process each relation, we check if the parent or child node already exists in our map. If not, we create them. This ensures that every unique value maps to exactly one instance of a `TreeNode`.

**Step 2: Tree Construction**
For each description `[parent, child, isLeft]`, we fetch (or create) both the `parent` and `child` nodes. We then link `parent->left` or `parent->right` to the `child` node depending on the value of `isLeft`.

**Step 3: Finding the Root**
A critical property of a tree is that the root node is the only node with no incoming edges (i.e., it is never a child). By tracking all values that appear as a `child` in a hash set, we can easily identify the root. Once all descriptions are processed, the unique node value that is present in our node map but absent from our `children` set is the root of the tree.

### Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the number of descriptions. We iterate through the descriptions array once to build the tree and populate the set of children. Finding the root involves a linear scan over the unique nodes, which is bounded by $\mathcal{O}(N)$ since there are at most $N + 1$ unique nodes in a valid tree.
- **Space Complexity:** $\mathcal{O}(N)$ to store the nodes in the map and the child relations in the hash set.