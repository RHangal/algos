Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].


Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.

class Solution:
   def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
       if not root:
           return 0

       if root.val < low:
           return self.rangeSumBST(root.right,low,high)
       elif root.val > high:
           return self.rangeSumBST(root.left,low,high)
       else:
           return(root.val + self.rangeSumBST(root.right,low,high)+ self.rangeSumBST(root.left,low,high))


