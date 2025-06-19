# Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

#Example 1:

#Input: root = [1,2,3,null,5,null,4]

#Output: [1,3,4]


class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root: return []

        res = []
        queue = deque([root])

        while(queue):
            levelSize = len(queue)

            for i in range(levelSize):
                curr = queue.popleft()
                if i == 0:
                    res.append(curr.val)
                if curr.right:
                    queue.append(curr.right)
                if curr.left:
                    queue.append(curr.left)

        return res



