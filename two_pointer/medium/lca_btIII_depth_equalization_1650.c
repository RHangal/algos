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
 * Solution: Depth Equalization using two pointers
 * I solve this by first computing the depth of both nodes by walking up to the root using their parent pointers.

Once I have the depths, I move the deeper node upward until both nodes are at the same level.

Then I walk both nodes up in sync until they meet — the point where they meet is the Lowest Common Ancestor.

🧠 Why It Works
Equalizing the depths ensures both nodes take the same number of steps to reach the ancestor.
Since the tree is valid and both nodes have parent references, they’re guaranteed to meet at their LCA.

Time Complexity: O(h)

Where h is the height of the tree (worst-case distance from node to root)

We traverse up to the root once per node, and again in sync to find the LCA

Space Complexity: O(1)

We use only a few pointers and counters — no recursion or extra data structures
 * */

struct Node* lowestCommonAncestor(struct Node* p, struct Node* q) {
  struct Node* currP = p;
  struct Node* currQ = q;

  int hP = 0, hQ = 0;

  while(currP) {
      currP = currP->parent;
      hP++;
  }
  while(currQ) {
      currQ = currQ->parent;
      hQ++;
  }

  while(hP > hQ) {
      p = p->parent;
      hP--;
  }

  while(hQ > hP) {
      q = q->parent;
      hQ--;
  }

  while(p != q) {
      p = p->parent;
      q = q->parent;
  }

  return p;  
  
}    


