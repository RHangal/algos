Given two nodes of a binary tree p and q, return their lowest common ancestor (LCA).

Each node will have a reference to its parent node. The definition for Node is below:

class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
}
According to the definition of LCA on Wikipedia: "The lowest common ancestor of two nodes p and q in a tree T is the lowest node that has both p and q as descendants (where we allow a node to be a descendant of itself)."



class Solution:
    def lowestCommonAncestor(self, p: 'Node', q: 'Node'):
        hashset = set()

        curr = p
        while(curr):
            hashset.add(curr.val)
            curr = curr.parent

        curr = q
        while(curr):
            if curr.val in hashset:
                return curr
            curr = curr.parent
            
