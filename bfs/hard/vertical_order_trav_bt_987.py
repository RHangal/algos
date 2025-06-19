Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.

Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.

Solution: BFS and sorting solution utilizing a hashtable/map which has a time complexity of O(n log n) - due to the sorting per column and a space complexity of O(n)

from collections import defaultdict, deque
class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []

        cols = defaultdict(list)
        queue = deque([(root, 0, 0)]) # (node, col, row)

        col_min = col_max = 0

        while queue:
            node, col, row = queue.popleft()
            cols[col].append((row, node.val))

            if node.left:
                queue.append((node.left, col-1, row+1))
                col_min = min(col_min, col-1)

            if node.right:
                queue.append((node.right, col+1, row+1))
                col_max = max(col_max, col+1)

        # Sort each column by row first, then value
        return [
                [val for row,val in sorted(cols[i])] for i in range(col_min, col_max+1)
                ]
