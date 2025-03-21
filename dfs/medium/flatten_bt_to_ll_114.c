/* 
* Problem Statement:
* Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree. 
*/

/*
 * Solution: Recursive DFS
 * using simple recursive dfs we can flatten the bt and achieve O(n) time and O(h) space complexity. the O(h) is due to recursion being based off of the call stack, worst case h = n w/ tree skewed and best case on balanced tree is h = log n
 */
/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void flatten(struct Treenode* root) {
    if(!root) return;

    /*Flatten left and right subtrees */
    flatten(root->left);
    flatten(root->right);

    /*Store original left and right subtrees*/
    struct Treenode* left = root->left;
    struct Treenode* right = root->right;

    /*Put left subtree on the right*/
    root->left = NULL;
    root->right = left;

    /*Find the tail of the new right subtree*/
    struct Treenode* temp = root;
    while(temp->right){
        temp = temp->right;
    }
    /*Attach the original right subtree */
    temp->right = right;
}
