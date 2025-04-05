#include <stdio.h>
#define TABLE_SIZE 10
// Hash table arrays
int hashTableDouble[TABLE_SIZE];
int hashTableQuadratic[TABLE_SIZE];

// primary hash function
int hash1(int key) {
    return key % TABLE_SIZE;
}
// secondary hash function for Double Hashing
int hash2(int key) {
    return 7 - (key % 7);
}
// func to insert into hash table using Double Hashing
void insert_double_hashing(int key) {
    int index = hash1(key);  
    int stepSize = hash2(key);  
    int i = 0;

    // Find an empty slot using double hashing
    while (hashTableDouble[(index + i * stepSize) % TABLE_SIZE] != -1) {
        i++;
    }

    // insert the key into the table at the calculated position
    hashTableDouble[(index + i * stepSize) % TABLE_SIZE] = key;
}
// function to insert into hash table using Quadratic Hashing
void insert_quadratic_hashing(int key) {
    int index = hash1(key); 
    int i = 0;

    // find an empty slot using quadratic hashing
    while (hashTableQuadratic[(index + i * i) % TABLE_SIZE] != -1) {
        i++;  
    }

    // insert the key into the table at the calculated position
    hashTableQuadratic[(index + i * i) % TABLE_SIZE] = key;
}

// function to display hash table contents
void display(int hashTable[], const char *methodName) {
    printf("\nHash Table using %s:\n", methodName);
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1) {
            printf("%d -> %d\n", i, hashTable[i]);
        } else {
            printf("%d -> Empty\n", i);
        }
    }
}
int main() {
    printf("**\tCompiled By Aswin phuyal\t**\n");
        int key;
        // initialize hash tables with -1 to indicate empty slots
        for (int i = 0; i < TABLE_SIZE; i++) {
            hashTableDouble[i] = -1;
            hashTableQuadratic[i] = -1;
        }
        // take input
        printf("Enter keys to insert into the hash table (enter -1 to stop):\n");
        while (1) {
            printf("Enter key: ");
            scanf("%d", &key);
            if (key == -1) {
                break;
            }
            // insert the key into both hash tables
            insert_double_hashing(key);
            insert_quadratic_hashing(key);
        }
        // display
        display(hashTableDouble, "Double Hashing");
        display(hashTableQuadratic, "Quadratic Hashing");
}