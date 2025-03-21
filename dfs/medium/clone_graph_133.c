/* 
* Problem Statement:
* Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph. 
*/

/*
 * Solution: DFS using recursion
 * This solution is more compact than bfs and uses recursive dfs the clone the graph
 */

struct Node *cloneGraph_helper(struct Node* s, Struct Node* clones[]){
    if(s==NULL) return NULL;
    if(!clones[s->val]){
        struct Node* r = malloc(sizeof(struct Node));

        if(s->neighbors > 0) {
            r->neighbors = malloc(s->numNeighbors * sizeof(struct Node*));
        } else {
            r->neighbors = NULL;
        }
        r->numNeighbors = s->numNeighbors;
        r->val = s->val;
        clones[s->val] = r;
        if(s->numNeighbors > 0) {
            for(int = 0; i < s->numNeighbors; i++){
                r->neighbors[i] = cloneGraph_helper(s->neighbors[i], clones);
            }
        }
        return r;
    }
    return clones[s->val];
}

struct Node* cloneGraph(struct Node* s) {
    struct Node* clones[101] = {NULL};
    struct Node* ans = cloneGraph_helper(s, clones);
    return ans;
}
