/* 
* Problem Statement:
* Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them. 
*/

/*
 * Solution: Recursive DFS passing diameter by reference but can also use global variable
 *
 */

int dfs(struct TreeNode* root, int* diameter) {
    if(!root) return 0;

    int left = dfs(root->left, diameter);
    int right = dfs(root->right, diameter);

    if(left + right > *diameter) *diameter = left + right;

    return 1 + (left > right ? left : right);
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int diameter = 0;
    dfs(root, &diameter);
    return diameter;
}
