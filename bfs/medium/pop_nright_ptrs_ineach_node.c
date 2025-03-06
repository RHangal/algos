/* 
* Problem Statement:
* You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
    Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

    Initially, all next pointers are set to NULL.

 
*/

/*
 * Solution:
 * This solution is an iterative approach based on previous level order traversal problems but much easier/simple
 * First check for edge case of root being null
 * Second initialize queue of struct Node with size being 2^12-1 (based on constraints) which will be (1<<12) - 1 in C
 * Third set front and rear and move through our que 
 * We'll declare and initialize a levelSize variable of rear-front
 * looping from 0 - levelSize well add the left/right nodes to our que (they exist for sure but well use a conditional in case)
 * Declare a temp variable = queue[front] and increment the front
 * As we loop we set the temp->next value and if i = levelSize -1 we set it to NULL
 * Finally we return the root
 *
 */
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root) {
    if(!root) {
        return NULL;
    }
	
    struct Node* queue[(1<<12) - 1];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while(front < rear) {
        int levelSize = rear - front;
        for (int i =0; i < levelSize; i++){
            struct Node* temp = queue[front++];
            if(i == levelSize - 1) temp->next = NULL;
            else temp->next = queue[front];
             
            if(temp->left) queue[rear++] = temp->left;
            if(temp->right) queue[rear++] = temp->right;
        }
    }

    return root;

}
