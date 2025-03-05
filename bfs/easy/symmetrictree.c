/* 
* Problem Statement:
* Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
*/

/*
 * Solution:
 * We can solve use recursion
 * Create a function that compares two nodes: a right node and a left node
 * 1. if p == NULL AND q == NULL, return true
 * 2. if p == NULL OR q == Null, return false
 * 3. if p->val == q->val, call function twice passing right/left nodes
 * 4. if p->val != q->val, return false (simplify using else statment) 
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSymmetric(struct TreeNode* root) {
     bool symmetricCheck(struct TreeNode* p, struct TreeNode* q){
        if (p == NULL && q == NULL){
            return true;
        }
        if (p == NULL || q == NULL){
            return false;
        }
        if (p->val == q->val){
            return symmetricCheck(p->right,q->left) && symmetricCheck(p->left,q->right);
        }
        
        return false;
        
    }
    return symmetricCheck(root,root);
}


