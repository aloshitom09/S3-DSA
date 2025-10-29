#include <stdio.h>
#define SIZE 10

int hashFunction(int key) {
    return key % SIZE;
}

int main() {
    int hashTable[SIZE];
    int n, key, index;

    // Initialize hash table
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        index = hashFunction(key);

        // Linear probing in case of collision
        while (hashTable[index] != -1) {
            index = (index + 1) % SIZE;
        }

        hashTable[index] = key;
    }

    printf("\n---------------------------------\n");
    printf("| Index |   Value               |\n");
    printf("---------------------------------\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("|  %2d   |   %4d               |\n", i, hashTable[i]);
        else
            printf("|  %2d   |   Empty             |\n", i);
    }
    printf("---------------------------------\n");

    printf("\nHash Function Used: index = key %% 10\n");
    printf("Collision Handling: Linear Probing\n");

    return 0;
}
