/* 
* Problem Statement:
* 236. Lowest Common Ancestor of a Binary Tree
Solved
Medium
Topics
Companies
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
*/

/*
 * Solution:  
 *
 *
 *
 * */

int rec(struct Treenode* root, struct Treenode* p, struct Treenode* q, struct Treenode** ret) {
    if(!root) return 1;

    int i = 1;

    if(root == p){
        i = 2;
    } else if(root == q){
        i =3;
    }

    i = i * rec(root->left, p, q, ret) * rec(root->right, p, q, ret);
    if(i == 6) {
        *ret = root;
        return 0;
    }

    return i;
}

struct Treenode* lowestCommonAncestor(struct Treenode* root, struct Treenode* p, struct Treenode* q) {
   struct Treenode* ret;
   rec(root, p, q, &ret);
   return ret;
}

