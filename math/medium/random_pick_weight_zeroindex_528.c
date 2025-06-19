/* 
* Problem Statement:
* You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.

You need to implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1] (inclusive) and returns it. The probability of picking an index i is w[i] / sum(w).

For example, if w = [1, 3], the probability of picking index 0 is 1 / (1 + 3) = 0.25 (i.e., 25%), and the probability of picking index 1 is 3 / (1 + 3) = 0.75 (i.e., 75%).
* 
* Constraints:

1 <= w.length <= 104
1 <= w[i] <= 105
pickIndex will be called at most 104 times.
*/

/*
 * Solution:  I preprocess the weights into a prefix sum array where each entry represents the cumulative total up to that index.
To pick an index, I generate a random integer in the range [1, total sum] and use binary search to find the smallest index such that the prefix sum at that index is greater than or equal to the random number.
This simulates weighted probability in O(log n) time by mapping each weight to a proportional region of the number line.
*
* Operation	Complexity
Constructor	O(n) ← build prefix sum array
pickIndex()	O(log n) ← binary search
Space	O(n) ← prefix sum storage
 */

#include <stdlib.h>
#include <time.h>


typedef struct {
    int* prefixSum;
    int size;
} Solution;

Solution* solutionCreate(int* w, int wSize) {
    Solution* obj = malloc(sizeof(Solution));
    obj->prefixSum = calloc(wSize+1, sizeof(int));
    obj->size = wSize +1;

    for(int i = 0; i < wSize; i++) {
        obj->prefixSum[i+1] = obj->prefixSum[i] + w[i];
    }

    srand(time(NULL));

    return obj;
}

int solutionPickIndex(Solution* obj) {
    int target = rand() % obj->prefixSum[obj->size - 1];

    int left = 0, right = obj->size - 1;
    while(left < right) {
        int mid = left + (right - left) / 2;
        if(obj->prefixSum[mid] > target)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left - 1;
}

void solutionFree(Solution* obj){
    free(obj->prefixSum);
    free(obj);
}
