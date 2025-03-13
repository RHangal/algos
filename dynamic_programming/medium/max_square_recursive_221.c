/* 
* Problem Statement:
* Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area. 
*/

/*
 * Solution: Recursive DP
 * A bottom up approach using memoization and recursion
 */

#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MIN3(a, b, c) MIN(MIN(a, b), (c))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxSquareRecursive(char** matrix, int i, int j, int** memo) {
    if (i < 0 || j < 0) return 0;  // Out of bounds, base case
    if (memo[i][j] != -1) return memo[i][j];  // Return cached value

    if (matrix[i][j] == '0') return (memo[i][j] = 0);  // A '0' cannot form a square

    // Compute the maximum square size recursively
    memo[i][j] = 1 + MIN3(
        maxSquareRecursive(matrix, i - 1, j, memo),     // Above
        maxSquareRecursive(matrix, i, j - 1, memo),     // Left
        maxSquareRecursive(matrix, i - 1, j - 1, memo)  // Diagonal
    );

    return memo[i][j];
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || *matrixColSize == 0) return 0;

    // Create memoization table
    int** memo = (int**)malloc(matrixSize * sizeof(int*));
    for (int i = 0; i < matrixSize; i++) {
        memo[i] = (int*)malloc(*matrixColSize * sizeof(int));
        for (int j = 0; j < *matrixColSize; j++) memo[i][j] = -1;  // Initialize with -1
    }

    int maxSide = 0;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            if (matrix[i][j] == '1') {
                maxSide = MAX(maxSide, maxSquareRecursive(matrix, i, j, memo));
            }
        }
    }

    // Free memory
    for (int i = 0; i < matrixSize; i++) free(memo[i]);
    free(memo);

    return maxSide * maxSide; // Return area of the largest square
}

