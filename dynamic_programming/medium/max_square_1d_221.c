/* 
* Problem Statement:
* Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area. 
*/

/*
 * Solution:
 * Dynamic programming solution, initializing a blank array of size (n x m)
 * Iterate through the original array and at each point move from the bottom up to calculate the max square
 * Keep track and update the max value then finally return the max * max to determine the area
 */

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MIN3(a,b,c) MIN(MIN(a,b),c)
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || *matrixColSize == 0) return 0;
    
    int* dp = (int*)calloc(*matrixColSize, sizeof(int));
    if(!dp) return -1;

    int maxNumber = 0;
    int diag = 0;
    for (size_t i=0; i<matrixSize; i++) {
        diag = 0;
        for(size_t j=0; j<*matrixColSize; j++) {
            if (matrix[i][j] == '0') {
                dp[j] = 0;
                continue;
                }
            int left = 0, above = 0, temp = dp[j]; 
            if (i > 0) {above = dp[j];}
            if (j > 0) {left = dp[j-1];}
          

            dp[j] = MIN3(left,above,diag) + 1;
            maxNumber = MAX(maxNumber,dp[j]);
            diag = temp;
        }
    }

  
    free(dp);
    
    return maxNumber * maxNumber; 

}
