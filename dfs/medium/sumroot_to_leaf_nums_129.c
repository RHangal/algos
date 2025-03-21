/* 
* Problem Statement:
* You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children. 
*/

/*
 * Solution: Recursive DFS (no memo needed)
 * We can use recursion w/ a helper functio to solve this in O(n)
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*Helper function to perform dfs*/
int dfs(struct Treenode* root, int current) {
    if(!root) return 0;
    
    /*Calculating the number based on the next node*/
    current = (current * 10) + root->val;
    
    /*if leaf return current number*/
    if(!root->left && !root->right) return current;
    
    /*Recur on left and right children*/
    return dfs(root->left, current) + dfs(root->right, current);

}

int sumNumbers(struct Treenode* root) {
    return dfs(root,0);
}


