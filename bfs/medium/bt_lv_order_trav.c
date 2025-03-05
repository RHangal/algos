/* 
* Problem Statement:
* Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
*/

/*
 * Solution:
 * First we handle the edge case of root being NULL and set the returnSize and returnColumnSizes accordingly
 * Next we need to initialize our resolution as an array of arrays int** with a size of 2000 based on max constraints given
 * Initialize returnColumnSizes as 2000 times size of int as its an array holding up to 2000 ints
 * Initialize returnSize as 0
 * Initialize que which is an array of struct TreeNode* up to 2000 
 * Set root as que[0] and increment rear
 * We move from left to right (front to rear) in a while loop front<rear
 * Figure out level size by subtracting rear-front
 * allocate memory for the res at the returnSize
 * set return column size
 * Loop through from 0 < levelsize and use a temp node to store whats in the que while incrementing the front
 * append the value of the temp node to our res array
 * Check left and right node and append to the queue if they exist (left to right order)
 * Increment return size after each loop
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
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int** res = (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));
    *returnSize = 0;

    struct TreeNode* queue[2000];  // Single queue storing nodes directly
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
        (*returnSize)++;
    }

    return res;
}
