/* 
* Problem Statement:
* Given the root of a binary tree, return the vertical order traversal of its nodes' values. (i.e., from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

 
*/

/*
 * Solution: BFS + static hashmap
 * b/c this is C we implement a static hash using an OFFSET
 * 
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

#define MAX_COLS 201
#define OFFSET 100


typedef struct {
    struct TreeNode* node;
    int col;
} QueueItem;

typedef struct {
    int* values;
    int size;
    int capacity;
} Column;

void addToColumn(Column* col, int val) {
    if(col->size == col-> capacity) {
        col->capacity = col-> capacity * 2 + 1;
        col->values = realloc(col->values, col->capacity * sizeof(int));
    }
    col->values[col->size++] = val;
}

int** verticalOrder(struct TreeNode* root, int* returnSize, int** returnColSize){
    if(!root) {
        *returnSize = 0;
        return NULL;
    }

    Column* columns = calloc(MAX_COLS, sizeof(Column));
    QueueItem queue[100];
    int front = 0, rear = 0;
    int minCol = OFFSET, maxCol = OFFSET;

    queue[rear++] = (QueueItem){root,OFFSET};

    while (front < rear) {
        QueueItem current = queue[front++];
        struct TreeNode* node = current.node;
        int col = current.col;

        addToColumn(&columns[col], node->val);

        if (node->left) {
            queue[rear++] = (QueueItem){node->left, col - 1};
            if(col - 1 < minCol) minCol = col - 1;
        }

        if (node->right) {
            queue[rear++] = (QueueItem){node->right, col + 1};
            if(col + 1 > MaxCol) maxCol = col + 1;
        }

        int colCount = maxCol - minCol + 1;
        *returnSize = colCount;

        int** result = malloc(colCount * sizeof(int*));
        *returnColSize = malloc(colCount * sizeof(int));

        for(int i = minCol; i <= maxCol; i++) {
            int index = i - minCol;
            result[index] = columns[i].values;
            (*returnColumnSizes)[index] = columns[i].sizes;
        }
        
        /**
        for (int i = 0; i < colCount; i++) {
        int col = minCol + i;  
        result[i] = columns[col].values;
        (*returnColumnSizes)[i] = columns[col].size;
        }
        **/
        free(columns);
        return result;

    }
}
