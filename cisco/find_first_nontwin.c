#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 10007  // A prime number to reduce collisions

// Linked list node for handling collisions
typedef struct Node {
    int key;
    int count;
    struct Node* next;
} Node;

// Hash table (array of linked lists)
Node* hashTable[HASH_SIZE];

// Hash function (simple modulo-based)
int hashFunction(int key) {
    return abs(key) % HASH_SIZE;
}

// Insert or update value in hash table
void insert(int key) {
    int index = hashFunction(key);
    Node* curr = hashTable[index];

    // Search for the key in the linked list
    while (curr) {
        if (curr->key == key) {
            curr->count++;
            return;
        }
        curr = curr->next;
    }

    // If not found, insert at head of the list
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->count = 1;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Get the count of a number from the hash table
int getCount(int key) {
    int index = hashFunction(key);
    Node* curr = hashTable[index];

    while (curr) {
        if (curr->key == key) {
            return curr->count;
        }
        curr = curr->next;
    }
    return 0; // Key not found
}

// Free the allocated memory for hash table
void freeHashTable() {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* curr = hashTable[i];
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
        hashTable[i] = NULL;
    }
}

void funcTwins(array_single_int inputArr) {
    if (!inputArr.data || inputArr.size == 0) {
        printf("-1\n");
        return;
    }

    // Step 1: Insert all elements into the hash table
    for (int i = 0; i < inputArr.size; i++) {
        insert(inputArr.data[i]);
    }

    // Step 2: Find the first element that occurs only once
    for (int i = 0; i < inputArr.size; i++) {
        if (getCount(inputArr.data[i]) == 1) {
            printf("%d\n", inputArr.data[i]);
            freeHashTable();
            return;
        }
    }

    // Step 3: If all are twins, return -1
    printf("-1\n");

    // Free hash table memory
    freeHashTable();
}

int main() {
    array_single_int inputArr;

    // Input array size
    scanf("%d", &inputArr.size);
    inputArr.data = (int *)malloc(sizeof(int) * inputArr.size);

    // Input array elements
    for (int i = 0; i < inputArr.size; i++) {
        scanf("%d", &inputArr.data[i]);
    }

    funcTwins(inputArr);

    // Free allocated memory
    free(inputArr.data);
    return 0;
}

