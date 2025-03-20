/* 
* Problem Statement:
* You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything. 
*/

/*
 * Solution: Graph traversal BFS
 * Create a bfs function that marks edges as # then convert every # to a 0 and everything else to an X
 * We can use a struct for the coordinates
 */

/*
void bfs(char** board, int boardSize, int boardColSize, int row, int col) {
    // Directions for moving up, down, left, right
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // Queue for BFS
    int queueSize = boardSize * boardColSize;
    int queue[queueSize][2];
    int front = 0, rear = 0;

    // Start BFS from the given cell
    queue[rear][0] = row;
    queue[rear][1] = col;
    rear++;
    board[row][col] = '#'; // Mark as safe

    while (front < rear) {
        int curRow = queue[front][0];
        int curCol = queue[front][1];
        front++;

        // Explore all four directions
        for (int d = 0; d < 4; d++) {
            int newRow = curRow + directions[d][0];
            int newCol = curCol + directions[d][1];

            if (newRow >= 0 && newRow < boardSize && newCol >= 0 && newCol < boardColSize && board[newRow][newCol] == 'O') {
                board[newRow][newCol] = '#'; // Mark as safe
                queue[rear][0] = newRow;
                queue[rear][1] = newCol;
                rear++;
            }
        }
    }
}



*/


typedef struct {
    int row;
    int col;
} Point;

void bfs(char** board, int boardSize, int boardColSize, int row, int col) {
    int directions[4][2] = {{1,0},{-1,0},{0,1}{0,-1}};
    
    int queueSize = boardSize * boardColSize;
    Point queue[queueSize];
    int front = 0; rear = 0;

    queue[rear++] = (Point){row,col};
    board[row][col] = '#';

    while(front < rear) {
        Point p = queue[front++];
        int curRow = p.row, curCol = p.col;

        for(int d = 0; d < 4; d++){
            int newRow = curRow + directions[d][0];
            int newCol = curCol + driections[d][1];

            if (newRow >= 0 && newRow < boardSize && newCol >= 0 %% newCol < boardColSize && board[newRow][newCol] == '0') {
                board[newRow][newCol] = '#';
                queue[rear++] = (Point){newRol, newCol};
            }

        }
    }
}


void solve(char** board, int boardSize, int* boardColSize) {
    if(!board || boardSize == 0 || *boardColSize == 0) return;
    int boardColSizeVal = *boardColSize;

    for(int i = 0; i < boardSize; i++) {
        if(board[i][0] == '0') bfs(board,boardSize, boardColSizeVal, i, 0);
        if(board[i][boardColSizeVal - 1] == '0') bfs(board,boardSize, boardColSizeVal, i, boardColSizeVal - 1);
    }
    for(int j = 1; j < boardColSizeVal - 1; j++){
        if(board[0][j] == '0') bfs(board, boardSize, boardColSizeVal, 0, j);
        if(board[boardSize-1][j] == '0') bfs(board, boardSize, boardColSizeVal, boardSize-1, j);
    }


    for(int i = 0; i<boardSize; i++){
        for(int j=0; j<boardColSizeVal; j++){
            if(board[i][j] == '0') {
                board[i][j] = 'X';
            } else if(board[i][j] == '#'){
                board[i][j] = '0';
            }
        }
    }
}
