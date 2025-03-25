/* 
* Problem Statement:
* Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water. 
*/

/*
 * Solution: BFS using a queue and a direction grid for graph traversal
 * while using a helper function is cleaner, it increases runtime because it introduces function call overhead
 * Pushes arguements onto stack
 * Transfers control
 * Pops return address later
 */


void bfs(char** grid, int i, int j, int rows, int cols) {
            int queue[rows*cols][2];
            int directions[4][2] = {{1,0}, {-1,0}, {0,1},{0,-1}};


            int front = 0, rear = 0;
            queue[rear][0] = i;
            queue[rear][1] = j;
            rear++;

            grid[i][j] = '0';

                while(front < rear) {
                    int r = queue[front][0];
                    int c = queue[front][1];
                    front++;

                    for(int d = 0; d < 4; d++) {
                       int nr = r + directions[d][0];
                       int nc = c + directions[d][1];

                        if(nr >=0 && nr<rows && nc >=0 && nc<cols && grid[nr][nc]=='1' ){
                            grid[nr][nc] = '0';
                            queue[rear][0] = nr;
                            queue[rear][1] = nc;
                            rear++;
                        }
                    }
                }
           
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = *gridColSize;
    int count = 0;

   
    for(int i = 0; i< rows; i++) {
        for(int j = 0; j<cols; j++){
            if(grid[i][j] == '1') {
            bfs(grid, i, j, rows, cols);    
            count++;

           }
        }
    }
    return count;
}
