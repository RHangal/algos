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
 * Solution: We use recursive DFS to check if p or q is located in the left and right subtrees, returning root if found
 * 
 * "I'm using a bottom-up DFS approach to find the lowest common ancestor. I recursively search the left and right subtrees, and if both return non-null, it means one target node was found in each subtree — so the current node is their lowest common ancestor. If only one side returns non-null, I propagate it upward."
 *
 * Time: O(n) — because we may visit every node in the tree once

Space: O(h) — where h is the height of the tree (due to recursion stack)
 */

struct Treenode* lowestCommonAncestor(struct Treenode* root, struct Treenode* p, struct Treenode* q) {
    if (!root || root == p || root == q) return root;

    struct Treenode* left = lowestCommonAncestor(root->left, p, q);
    struct Treenode* right = lowestCommonAncestor(root->right, p, q);

    if(left && right) return root;
    return left ? left: right;
}

