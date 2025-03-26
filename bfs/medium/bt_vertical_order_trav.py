/* 
*# Problem Statement:
*# Given the root of a binary tree, return the vertical order traversal of its nodes' values. (i.e., from top to bottom, column by column).

# If two nodes are in the same row and column, the order should be from left to right.
*/

/*
 * # Solution:
 * # BFS + Hashmap
 */

 # Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []

        # Dictionary to hold column index → list of node values
        columns = defaultdict(list)

        # Queue holds (node, column)
        queue = deque([(root, 0)])

        # Track min/max column indices
        min_col = max_col = 0

        while queue:
            node, col = queue.popleft()
            columns[col].append(node.val)

            if node.left:
                queue.append((node.left, col - 1))
                min_col = min(min_col, col - 1)
            if node.right:
                queue.append((node.right, col + 1))
                max_col = max(max_col, col + 1)

        # Extract values in order from leftmost to rightmost column
        return [columns[i] for i in range(min_col, max_col + 1)]



