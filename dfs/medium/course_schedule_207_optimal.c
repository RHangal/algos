/* 
* Problem Statement:
* There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false. 
*/

/*
 * Solution: Recursive DFS + Cycle detection. 
 * We're looking for a Directed Acyclic Graph -> return true
 *
 */

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define MAX_NUM_COURSE 2001

void errx(int errno, char* msg) {
    fprintf(stderr, "%s", msg);
    exit(errno);
}

typedef struct node {
    int course;
    struct node* next;
    
} Node;

bool dfs(int course, Node* depmap[MAX_NUM_COURSE], int* visited) {
    if(visited[course] == 1) return false;
    if(visited[course] == 2) return true;

    visited[course] = 1;

    for (Node* n = depmap[course]; n !=NULL; n = n->next) {
        if (!dfs(n->course, depmap, visited)) return false;
    }

    visited[course] = 2;
    return true;

}

bool canFinish(int numCourse, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int visited[MAX_NUM_COURSE] = {0};
    Node* depmap[MAX_NUM_COURSE] = {NULL};

    for(int i = 0; i< prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int prereq = prerequisites[i][1];

        Node* new_node = malloc(sizeof(Node));
        if (!new_node) errx(-2, "Memory allocation failed");

        new_node->course = prereq;
        new_node->next = depmap[course];
        depmap[course] = new_node;
    }

    for(int i = 0; i < numCourse; i++) {
        if(!dfs(i, depmap, visited)) return false;
    }

    return true;
}
