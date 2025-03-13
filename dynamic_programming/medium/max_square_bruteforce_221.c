/* 
* Problem Statement:
* Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area. 
*/

/*
 * Solution: Brute Force
 * There are two ways to brute force O(n^4) and O(n^3), its easier to implement O(n^3) 
 */

int maximalSquareOptimizedBruteForce(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || *matrixColSize == 0) return 0;

    int maxSide = 0;

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            if (matrix[i][j] == '1') {
                int maxSize = 1; // Start with 1x1 square
                int valid = 1;

                while (i + maxSize < matrixSize && j + maxSize < *matrixColSize && valid) {
                    // Check new row and column (only the border, not the full square)
                    for (int x = i; x <= i + maxSize; x++) {
                        if (matrix[x][j + maxSize] == '0') {
                            valid = 0;
                            break;
                        }
                    }
                    for (int y = j; y <= j + maxSize; y++) {
                        if (matrix[i + maxSize][y] == '0') {
                            valid = 0;
                            break;
                        }
                    }

                    if (valid) {
                        maxSize++;
                    }
                }

                maxSide = (maxSize > maxSide) ? maxSize : maxSide;
            }
        }
    }

    return maxSide * maxSide;
}

