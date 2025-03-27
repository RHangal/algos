/* 
* Problem Statement:
* Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
*/

/*
 * Solution: Utilize a Priority Queue (Min Heap)
 *
 */

#include <stdlib.h>

void heapifyUp(int* heap, int index) {
    while(index > 0) {
        int parent = (index -1) / 2;
        if (heap[parent] <= heap[index]) break;
        int temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;
        index = parent;
    }
}

void heapifyDown(int* heap, int size, int index) {
    while(2*index+1 < size){
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && heap[left] < heap[smallest]) smallest = left;
        if(right < size && heap[right] < heap[smallest]) smallest = right;

        if(smallest == index) break;

        int temp = heap[smallest];
        heap[smallest] = heap[index];
        heap[index] = temp;
        index = smallest;
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    int* heap = malloc(k * sizeof(int));
    int heapSize = 0;
    int i;

    for(i = 0; i < numsSize; i++) {
        if(heapSize < k) {
            heap[heapSize++] = nums[i];
            heapifyUp(heap, heapSize-1);
        }else if (nums[i] > heap[0]) {
            heap[0] = nums[i];
            heapifyDown(heap, heapSize, 0)
        }
    }

    int result = heap[0];
    free(heap);
    return result;
}


