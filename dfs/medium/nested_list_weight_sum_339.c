/* 
* Problem Statement:
* You are given a nested list of integers nestedList. Each element is either an integer or a list whose elements may also be integers or other lists.

The depth of an integer is the number of lists that it is inside of. For example, the nested list [1,[2,2],[[3],2],1] has each integer's value set to its depth.

Return the sum of each integer in nestedList multiplied by its depth.

Constraints:

1 <= nestedList.length <= 50
The values of the integers in the nested list is in the range [-100, 100].
The maximum depth of any integer is less than or equal to 50.
*/

/*
 * Solution: We can use the in built interface along with recursive DFS to return the sum, 
 * O(n) Time
 * O(depth) Space
 * 
 */

int dfs(struct NestedInteger** nestedList, int size, int depth) {
    int total = 0, i;

    for (i = 0; i < size; i++){
        if(NestedIntegerIsInteger(nestedList[i])) {
            total += NestedIntegerGetInteger(nestedList[i]) * depth;
        } else {
            struct NestedInteger** innerList = NestedIntegerGetList(nestedList[i]);
            int innerSize = NestedIntegerGetListSize(nestedList[i]);
            total+= dfs(innerList, innerSize, depth+1);
        }
    }
    return total;
}

int depthSum(struct NestedInteger** nestedList, int nestedListSize) {
    return dfs(nestedList, nestedListSize, 1);
}




