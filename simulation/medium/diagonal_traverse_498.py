Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

 

Example 1:


Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]
Example 2:

Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]

We use a simulation based solution w/ a time complexity of O(m*n) and space complexity of O(m*n) as well


class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        if not mat or not mat[0]:
            return []

        m,n = len(mat), len(mat[0])
        res = []

        for d in range(m+n-1):
            intermediate = []

            #Determine the starting row and col for this diagonal
            r = 0 if d<n else d-n+1
            c = d if d<n else n-1

            #Collect all elements on this diagonal
            while r<m and c >=0:
                intermediate.append(mat[r][c])
                r+=1
                c-=1

            #Reverse on even-numbered diagonals (zig-zag)
            if d % 2 == 0:
                res.extend(intermediate[::-1])
            else:
                res.extend(intermediate)

        return res
