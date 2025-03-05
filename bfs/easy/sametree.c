/* 
* Problem Statement:
* Given the roots of two binary trees p and q, write a function to check if they are the same or not.
* Two binary trees are considered the same if they are structurally identical, and the nodes have the same value. 
*/

/*
 * Solution:
 * We solve using recursion
 * 1. check if p AND q are NULL, return true 
 * 2. check if p OR are NULL, return false 
 * 3. check if p->val == q->val, call function again (recursion) passing in p->left/right and q->left/right
 * 4. check if p->val != q->val, return false (can use else statement to simplify)
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
     if (p == NULL && q == NULL) {
        return true;
    }
    if (p == NULL || q == NULL) {
        return false;
    }
    if (p->val == q->val) {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    return false;
}
