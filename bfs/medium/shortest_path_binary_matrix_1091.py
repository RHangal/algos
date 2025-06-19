Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        n = len(grid)
        if grid[0][0] != 0 or grid[n-1][n-1] != 0: return -1

        directions = [
                [-1,-1],[-1,0],[-1,1],
                [0,-1],        [0,1],
                [1,-1],[1,0],[1,1]
                ]
        queue = deque([[0,0,1]])
        grid[0][0] = 1

        while(queue):
            row,col,dist = queue.popleft()

            if row == n-1 and col == n-1:
                return dist

            for dr, dc in directions:
                nr,nc = row + dr, col + dc

                if 0<=nr<n and 0<=nc<n and grid[nr][nc] == 0:
                    queue.append([nr,nc,dist+1])
                    grid[nr][nc] = 1

        return -1



