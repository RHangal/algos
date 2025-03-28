/* 
* Problem Statement:
* Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107 
*/

/*
 * Solution: We can use a hashmap to store the prefix sum
 * “This is a linear time solution using prefix sums and a custom hashmap with quadratic probing to store the frequency of running sums. For each element, I check whether (current prefix sum - k) has been seen before — if so, it means there’s a subarray that sums to k. All operations are O(1) on average thanks to open addressing, giving the full algorithm a time and space complexity of O(n).”
 *
 */

#include <stdlib.h>

typedef struct {
    int key;
    int value;
} HashEntry;

typedef struct {
    HashEntry* table;
    int size;
} HashMap;

HashMap* createMap(int size) {
    HashMap* hashmap = (HashMap*)malloc(sizeof(HashMap));
    hashmap->table = (HashEntry*)calloc(size,sizeof(HashEntry));
    hashmap->size = size;
    return hashmap;
}

int hashFunction(int key, int size) {
    return abs(key) % size;
}

void put(HashMap* hashmap, int key, int value) {
    int initialIndex = hashFunction(key, hashmap->size);
    int i = 0, index;

    while(1) {
        index = (initialIndex + i * i) % hashmap->size;
        if(hashmap->table[index].value == 0 || hashmap->table[index].key == key) break;

        i++;

        if(i == hashmap->size) return;
    }

    if(hashmap->table[index].value == 0) {
        hashmap->table[index].value = value;
        hashmap->table[index].key = key;
    } else {
        hashmap->table[index].value +=value;
    }
}

int get(HashMap* hashmap, int key) {
    int initialIndex = hashFunction(key, hashmap->size);
    int i = 0, index;

    while(1) {
        index = (initialIndex + i * i) % hashmap->size;
        if(hashmap->table[index].value == 0) return 0;
        if(hashmap->table[index].key == key) return hashmap->table[index].value;
        i++;
        if(i == hashmap->size) return 0;
    }
}


void freeMap(HashMap* hashmap) {
    free(hashmap->table);
    free(hashmap);
}

int subarraySum(int* nums, int numsSize, int k) {
    HashMap* hashmap = createMap(2*numsSize+1);
    put(hashmap, 0, 1);

    int prefixSum = 0, count = 0, i;

    for(i = 0; i < numsSize; i++){
        prefixSum += nums[i];

        count += get(hashmap, prefixSum-k);

        put(hashmap, prefixSum, 1);
    }
    freeMap(hashmap);
    return count;

}


        
