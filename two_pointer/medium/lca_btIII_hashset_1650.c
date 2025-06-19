/* 
* Problem Statement:
* Given two nodes of a binary tree p and q, return their lowest common ancestor (LCA).

Each node will have a reference to its parent node. The definition for Node is below:

class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
}
According to the definition of LCA on Wikipedia: "The lowest common ancestor of two nodes p and q in a tree T is the lowest node that has both p and q as descendants (where we allow a node to be a descendant of itself)." 
*/

/*
 * Solution:
 * I solve this problem by treating each node's value as a unique key and using a boolean array to simulate a hash set.
I first walk up from node p, marking all of its ancestors (including itself) in the set.
Then I walk up from node q, and the first ancestor that is already marked is the lowest common ancestor.

🧠 Why It Works
Since all node values are guaranteed to be unique and within the range [-1e9, 1e9], we can safely map them to a flat array using an offset.
This gives us O(1) lookup time, and avoids the overhead of dynamic data structures like hash maps.
 **/

#include <stdio.h>
#include <stdbool.h>

#define OFFSET 1000000000
#define MAXVAL 2000000001

struct Node* lowestCommonAncestor(struct Node* p, struct Node* q) {
    bool* seen = calloc(MAXVAL, sizeof(bool));

    struct Node* curr = p;
    while(curr) {
        seen[curr->val + OFFSET] = true;
        curr = curr->parent;
    }

    curr = q;
    while(curr) {
        if(seen[curr->val + OFFSET]) {
            free(seen);
            return curr;
        }
        curr = curr->parent;
    }

    free(seen);
    return NULL;

   
}


