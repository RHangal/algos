/* 
* Problem Statement:
* Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between). 
*/

/*
 * Solution:
 * This solution is the exact same as the binary tree level order traversal with a few extra steps
 * 1. a helper function is created to reverse an array given a pointer to an array and an int size of said array
 * 2. every odd (num % 2 == 1) number we zigzag and reverse the values stored in our res
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

// Function to reverse an array in place
void reverseArray(int* arr, int size) {
    int left = 0, right = size - 1;
    while (left < right) {
        int temp = arr[left];
        arr[left++] = arr[right];
        arr[right--] = temp;
    }
}

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int** res = (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));
    *returnSize = 0;

    struct TreeNode* queue[2000]; 
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;
        res[*returnSize] = (int*)malloc(levelSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelSize;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];
            res[*returnSize][i] = node->val;
            
            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
          
        }

         
        if ((*returnSize) % 2 == 1) {
            reverseArray(res[*returnSize], levelSize);
        }
        (*returnSize)++;
    }

    return res;
}
