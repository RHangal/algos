/* 
* Problem Statement:
* Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:

Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4]

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/

/*
 * Solution: BFS looking at the right child first
 * Time/Space = O(n)
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
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

#define MAX_NODES 100

int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    /*Prep output array*/
    int* result = malloc(MAX_NODES * sizeof(int));
    *returnSize = 0;

    struct TreeNode* queue[MAX_NODES];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while(front < rear) {
        int levelSize = rear-front;

        for(int i = 0; i < levelSize; i++) {
            struct TreeNode* current = queue[front++];

            if(i==0) result[(*returnSize)++] = current->val;

            if(current->right) queue[rear++] = current->right;
            if(current->left) queue[rear++] = current->left;
        }
    }

    return result;
        
}

