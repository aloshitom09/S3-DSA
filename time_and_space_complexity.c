#include <stdio.h>

int main() {
    int n, key, flag = 0, count = 2;
    
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    count++;

    int sorted[n];
    printf("Enter the numbers in ascending order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &sorted[i]);
        count++;
    }

    printf("Enter the number to be searched: ");
    scanf("%d", &key);
    count++;

    int s = 0, e = n - 1;
    count += 3;

    while (s <= e) {
        int m = (s + e) / 2;
        count++;

        if (sorted[m] == key) {
            count++;
            printf("Element found at index %d\n", m);
            flag = 1;
            break;
        } 
        else if (sorted[m] > key) {
            e = m - 1;
            count++;
        } 
        else {
            s = m + 1;
            count++;
        }
    }

    if (flag == 0)
        printf("Number not found\n");

    // Approximate space complexity in bytes
    int space = (8 * 4) + (n * 4); // assuming int = 4 bytes
    printf("Space Complexity = %d bytes\n", space);

    printf("Time Complexity (in count units) = %d\n", count);

    return 0;
}
