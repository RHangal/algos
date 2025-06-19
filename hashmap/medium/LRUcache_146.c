/* 
* Problem Statement:
* Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.
* 
*/

/*
 * Solution:
 * We want to implement an LRU (Least Recently Used) Cache that supports:

get(key) in O(1)

put(key, value) in O(1)

Eviction of the least recently used item when capacity is exceeded

To do this efficiently in C (without built-in hash maps), we combine:

1. Hash Map (for O(1) key-to-node lookup)
2. Doubly Linked List (for O(1) tracking of usage order)
 */

#include <stdlib.h>

#define HASH_SIZE 9973

typedef struct Node {
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    int capacity;
    int size;
    Node* head;
    Node* tail;
    Node* hash[HASH_SIZE];
} LRUCache;

int hashFunc(int key) {
    return key % HASH_SIZE;
}

Node* createNode(int key, int value) {
    Node* node = malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->prev = node->next = NULL;
    return node;
}

void moveToFront(LRUCache* obj, Node* node) {
    if (node->prev) node->prev->next = node->next;
    else obj->head = node->next;
    if (node->next) node->next->prev = node->prev;
    else obj->tail = node->prev;

    node->prev = NULL;
    node->next = obj->head;
    if (obj->head) obj->head->prev = node;
    obj->head = node;
    if (!obj->tail) obj->tail = node;
}

void insertToFront(LRUCache* obj, Node* node) {
    node->prev = NULL;
    node->next = obj->head;
    if (obj->head) obj->head->prev = node;
    obj->head = node;
    if (!obj->tail) obj->tail = node;
}

void evictTail(LRUCache* obj) {
    if (!obj->tail) return;
    Node* tail = obj->tail;
    int h = hashFunc(tail->key);
    obj->hash[h] = NULL;

    obj->tail = tail->prev;
    if (obj->tail) obj->tail->next = NULL;
    else obj->head = NULL;

    free(tail);
    obj->size--;
}

LRUCache* LRUCacheCreate(int capacity) {
    LRUCache* cache = malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->size = 0;
    cache->head = cache->tail = NULL;

    for(int i=0; i<HASH_SIZE; i++) {
        cache->hash[i] = NULL;
    }
    return cache;
}

int LRUCacheGet(LRUCache* obj, int key) {
    int h = hashFunc(key);
    Node* node = obj->hash[h];
    if (!node || node->key != key) return -1;
    moveToFront(obj, node);
    return node->value;
}

void LRUCachePut(LRUCache* obj, int key, int value) {
    int h = hashFunc(key);
    Node* node = obj->hash[h];
    if (node && node->key == key) {
        node->value = value;
        moveToFront(obj, node);
        return;
    }

    if(obj->size == obj->capacity) evictTail(obj);

    Node* newNode = createNode(key, value);
    insertToFront(obj, newNode);
    obj->hash[hashFunc(key)] = newNode;
    obj->size++;
}

void LRUCacheFree(LRUCache* obj) {
    Node* curr = obj->head;
    while(curr) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }

    free(obj);
}

