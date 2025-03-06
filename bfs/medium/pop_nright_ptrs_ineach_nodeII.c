/* Problem:
 * Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
 *
 * Solution:
 * This solution is the exact same iterative approach as the I version of this problem using a queue,
 * It works regardless if the tree is perfect binary or not
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
            if(i != levelSize - 1) temp->next = queue[front];
             
            if(temp->left) queue[rear++] = temp->left;
            if(temp->right) queue[rear++] = temp->right;
        }
    }

    return root;

}
