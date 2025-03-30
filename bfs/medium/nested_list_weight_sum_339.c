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
 * Solution: We can use the in built interface along with iterative BFS and a queue to return the sum, 
 * O(n) Time
 * O(n) Space
 * 
 */

typedef struct {
    struct NestedInteger* item;
    int depth;
} QueueNode;

int depthSum(struct NestedInteger** nestedList, int nestedListSize) {
    QueueNode queue[2500];
    int front = 0, rear = 0;
    int total = 0, i;

    for(i = 0; i < nestedListSize; i++) {
        queue[rear++] = (QueueNode){nestedList[i], 1};
    }

    while(front < rear) {
        QueueNode* current = &queue[front++];

        struct NestedInteger* item = current->item;
        int depth = current->depth;

        if(NestedIntegerIsInteger(item)) {
            total += NestedIntegerGetInteger(item) * depth;
        } else {
            struct NestedInteger** innerList = NestedIntegerGetList(item);
            int innerSize = NestedIntegerGetListSize(item);
            for(i = 0; i < innerSize; i++) {
                queue[rear++] = (QueueNode){innerList[i], depth + 1};
            }
        }
    }
    return total; 
}

