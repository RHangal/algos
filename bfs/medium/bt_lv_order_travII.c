/* 
* Problem Statement:
* Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root). 
*/

/*
 * Solution:
 * For this solution we follow the same steps as the binary tree lv order traversalI and reverse the res array at the end
 * Similar to zigzag solution but here we apply the reversal to the entire res array rather than the elements within it
 * We MUST also reverse the returnColumnSizes so we know how to index the new reversed array!!!
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
void reverseArray(int** arr, int size) {
   int left = 0, right = size - 1;
    while(left < right) {
        int* temp = arr[left];
        arr[left++] = arr[right];
        arr[right--] = temp; 
    }

}

void reverseColumnArray(int* arr, int size) {
   int left = 0, right = size - 1;
    while(left < right) {
        int temp = arr[left];
        arr[left++] = arr[right];
        arr[right--] = temp; 
    }

}


int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if(!root) {
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

    while(front<rear) {
        int levelSize = rear-front;
        res[*returnSize] = (int*)malloc(levelSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelSize;
        
        for(int i = 0; i<levelSize; i++) {
            struct TreeNode* node = queue[front++];
            res[*returnSize][i] = node->val;

            if(node->left) queue[rear++] = node->left;
            if(node->right)queue[rear++] = node->right;
            
        }

        (*returnSize)++;
    }
    reverseColumnArray(*returnColumnSizes, *returnSize);
    reverseArray(res, *returnSize);

    return res;
}

