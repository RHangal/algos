#include <stdio.h>
#include <stdlib.h>

// Struct for 2D matrix
typedef struct {
    int **data;
    int row;
    int col;
} array_double_int;

// Function to rotate matrix 90 degrees clockwise
void funcRotate(array_double_int inputMat) {
    int N = inputMat.row;
    int M = inputMat.col;

    // Allocate memory for rotated matrix
    int **rotated = (int **)malloc(sizeof(int *) * M);
    for (int i = 0; i < M; i++) {
        rotated[i] = (int *)malloc(sizeof(int) * N);
    }

    // Rotate the matrix 90 degrees clockwise
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            rotated[j][N - 1 - i] = inputMat.data[i][j];
        }
    }

    // Print the rotated matrix
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", rotated[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < M; i++) {
        free(rotated[i]);
    }
    free(rotated);
}

int main() {
    array_double_int inputMat;

    // Input for matrix dimensions
    scanf("%d %d", &inputMat.row, &inputMat.col);

    // Allocate memory for the original matrix
    inputMat.data = (int **)malloc(sizeof(int *) * inputMat.row);
    for (int i = 0; i < inputMat.row; i++) {
        inputMat.data[i] = (int *)malloc(sizeof(int) * inputMat.col);
        for (int j = 0; j < inputMat.col; j++) {
            scanf("%d", &inputMat.data[i][j]); // Read matrix elements
        }
    }

    funcRotate(inputMat);

    // Free memory for original matrix
    for (int i = 0; i < inputMat.row; i++) {
        free(inputMat.data[i]);
    }
    free(inputMat.data);

    return 0;
}

