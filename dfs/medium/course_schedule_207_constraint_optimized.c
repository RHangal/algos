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

#define MAX_COURSES 2000
#define MAX_EDGES 5000

bool dfs(int node, int** graph, int*graphColSize, int* visited) {
    if(visited[node] == 1) return false; /*Cycle detected*/
    if(visited[node] == 2) return true; /*Already visited*/

    visited[node] = 1;

    for (int i = 0; i < graphColSize[node]; i++) {
        int neighbor = graph[node][i];
        if(!dfs(neighbor, graph, graphColSize, visited)) return false;
    }

    visited[node] = 2; /*Mark as visited*/
    return true;

}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    /*Build graph as an adjacency list*/
    int graph[MAX_COURSES][MAX_EDGES];
    int graphColSize[MAX_COURSES] = {0};
    int visited[MAX_COURSES] = {0};


    for(int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int prereq = prerequisites[i][1];
        graph[prereq][graphColSize[prereq]++] = course;
    }

    /*Track Visited State*/
    int* visited = calloc(numCourses, sizeof(int));

    /*DFS for each course*/
    for(int i = 0; i < numCourses; i++) {
        if (visited[i]==0) {
            if(!dfs(i, graph, graphColSize, visted)) return false;
        }
    }

    return true;
}
