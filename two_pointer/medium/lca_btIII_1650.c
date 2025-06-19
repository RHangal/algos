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
 * I'm using a two-pointer technique to find the lowest common ancestor by taking advantage of the fact that each node has a reference to its parent.

I initialize two pointers, one starting at p and the other at q. I move each pointer upward to its parent one step at a time. If a pointer reaches the root (NULL), I redirect it to the other node's starting position.

By doing this, both pointers will traverse equal numbers of steps — essentially covering the depth of both nodes — and they will eventually meet at the lowest common ancestor.
*
*
*
* This works because after both pointers have traversed the distance from p and q to the root — possibly swapping paths once — they’ll align and meet at the first common ancestor. It's guaranteed because both nodes belong to the same tree.
*
*
* "I use two pointers that walk upward and switch starting points when they reach the root — ensuring both cover the same total depth and meet at the LCA."
 */

struct Node* lowestCommonAncestor(struct Node* p, struct Node* q) {
    struct Node* a = p;
    struct Node* b = q;

    while(a != b) {
        a = a ? a->parent : q;
        b = b ? b->parent : p;
    }

    return a;

}


