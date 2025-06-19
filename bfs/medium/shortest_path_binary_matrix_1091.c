/* 
* Problem Statement:
* Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.
* 
*/

/*
 * Solution: BFS
 * Use a queue to perform level-order traversal starting from (0, 0) and explore all 8-connected directions.
Track visited cells by marking them or using a visited matrix.
The moment you reach (n-1, n-1), return the path length. If BFS finishes without reaching the goal, return -1.
 * Time: O(n^2) → You may visit every cell once

Space: O(n^2) → For queue and visited tracking
 */


#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int dist;
} QueueNode;

int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;

    if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;

    int directions[8][2] = {
        {-1,-1},{-1,0},{-1,1},
        {0,-1},        {0,1},
        {1,-1}, {1,0}, {1,1}
    };

    /*BFS queue */
    QueueNode* queue = malloc(n * n * sizeof(QueueNode));
    int front = 0, rear = 0;

    queue[rear++] = (QueueNode){0, 0, 1};
    grid[0][0] = 1;

    while(front < rear) {
        QueueNode curr = queue[front++];
        int r = curr.row, c = curr.col, d = curr.dist;

        if(r == n-1 && c == n-1) {
            free(queue);
            return d;
        }

        for (int i = 0; i < 8; i++) {
            int nr = r + directions[i][0];
            int nc = c + directions[i][1];

            if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                queue[rear++] = (QueueNode){nr,nc,d+1};
                grid[nr][nc] = 1;
            }

        }
    }

    free(queue);
    return -1;
}









