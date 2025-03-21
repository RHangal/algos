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
 * Solution: BFS Iterative
 * Using a queue we create a deep copy of the graph
 */

#include <stdlib.h>

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

struct Node* cloneGraph(struct Node* node) {
    if(!node) return NULL;

    struct Node* clones[101] = {0};
    struct Node** queue = malloc(101 * sizeof(struct Node*));    int front = 0, rear = 0;

    /* creat and store clone of the starting node */
    struct Node* nodeClone = malloc(sizeof(struct Node));
    nodeClone->val = node->val;
    nodeClone->numNeighbors = node->numNeighbors;
    nodeClone->neighbors = NULL;
    clones[node->val] = nodeClone;

    queue[rear++] = node;

    while(front < rear) {
        struct Node* curr = queue[front++];
        struct Node* currClone = clones[curr->val];

        /* Allocate neighbors array only if needed */
        if(currClone->neighbors == NULL && curr->numNeighbors >0){
            currClone->neighbors = malloc(curr->numNeighbors * sizeof(struct Node*));
        }
        /*Traverse neighbors */
        for (int i = 0; i < curr->numNeighbors; i++) {
            struct Node* neighbor = curr->neighbors[i];
            

            /*If the neighbor hasnt been cloned, clone it now */
            if(!clones[neighbor->val]){
                struct Node* neighborClone = malloc(sizeof(struct Node));
                neighborClone->val = neighbor->val;
                neighborClone->numNeighbors = neighbor->numNeighbors;
                neighborClone->neighbors = NULL;
                clones[neighbor->val] = neighborClone;
                queue[rear++] = neighbor;
            }

            currClone->neighbors[i] = clones[neighbor->val]
        }
    }

    free(queue);
    return clones[node->val];
}

