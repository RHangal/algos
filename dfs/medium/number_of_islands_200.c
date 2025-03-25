/* 
* Problem Statement:
* Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water. 
*/

/*
 * Solution: Recursive DFS with helper function where we Zero out islands so we dont retraverse any squares
 * 
 */

void dfs(char** grid, int i, int j, int rowSize, int colSize) {
    if(i<0 || i>=rowsSize || j<0 || j>=colSize || grid[i][j] == '0') return;

    grid[i][j] = '0';

    dfs(grid, i+1, j, rowSize, colSize); // down
    dfs(grid, i-1, j, rowSize, colSize); // up
    dfs(grid, i, j+1, rowSize, colSize); // right
    dfs(grid, i, j-1, rowSize, colSize); // left

}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int rowSize = gridSize;
    int colSize = *gridColSize;

    int count = 0;

    for(int i = 0; i < rowSize; i++) {
        for(int j = 0; j < colSize; j++) {
            if (grid[i][j] == '1') {
                dfs(grid, i, j, rowSize, colSize);
                count++
            }
        }
    }
    return count;
}
